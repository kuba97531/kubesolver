#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<string.h>
#include "cube3.h"
#include "cube3r.h"
#include <stdint.h>
#include "cube_compression.h"
#include <omp.h>

typedef struct 
{
    __uint128_t packed; 
} solver_cube_packed;

typedef struct 
{
    cube cube; 
    int8_t last_move;
} solver_cube_unpacked;

int solver_cube_compare(const void *s1, const void *s2)
{
    cube c1, c2;
    int8_t last_move;
    unpack_ce(&c1, &last_move, ((solver_cube_packed *)s1)->packed);
    unpack_ce(&c2, &last_move, ((solver_cube_packed *)s2)->packed);
    return cube_compare(&c1, &c2);
}

#define MERGE_SORT_SWAP(aaaaa,bbbbbb) {solver_cube_packed zzzzzzz = aaaaa; aaaaa= bbbbbb; bbbbbb = zzzzzzz;}

void merge(solver_cube_packed* a, int size, solver_cube_packed* temp) {
	int i1 = 0;
	int i2 = size / 2;
	int it = 0;

	while(i1 < size/2 && i2 < size) {
		if (solver_cube_compare(a + i1, a + i2) <= 0) {
			temp[it] = a[i1];
			i1 += 1;
		}
		else {
			temp[it] = a[i2];
			i2 += 1;
		}
		it += 1;
	}

	while (i1 < size/2) {
	    temp[it] = a[i1];
	    i1++;
	    it++;
	}
	while (i2 < size) {
	    temp[it] = a[i2];
	    i2++;
	    it++;
	}

	 memcpy(a, temp, size * sizeof(solver_cube_packed));
}

void assert_sorted(solver_cube_packed *a, int from, int size) {
    for (int i= from; i<from + size - 1; i++) {
        if (solver_cube_compare(a+i, a + i+1) > 0 )
        {
            printf("SORTING FAILURE at i = %d\n", i);
            fprintf(stderr, "SORTING FAILURE\n");
            exit(0);
            return;
        }
    }
}

void mergesort_serial(solver_cube_packed a[], int size, solver_cube_packed temp[]) {
    if (size == 1) {
        return;
    }
	if (size == 2) { 
	 	if (solver_cube_compare(a + 0, a + 1) <= 0)
	 		return;
	 	else {
	 		MERGE_SORT_SWAP(a[0], a[1]);
	 		return;
	 	}
	 }

	mergesort_serial(a, size/2, temp);
	mergesort_serial(a + size/2, size - size/2, temp);
	merge(a, size, temp);
}

void mergesort_parallel_omp (solver_cube_packed a[], int size, solver_cube_packed temp[], int threads) {
    if ( threads == 1 || size < 64) {
        // mergesort_serial(a, size, temp);
        qsort(a , size, sizeof(solver_cube_packed), solver_cube_compare);
    }
    else if (threads > 1) {
        #pragma omp parallel sections
        {
             #pragma omp section
             mergesort_parallel_omp(a, size/2, temp, threads/2);
             #pragma omp section
             mergesort_parallel_omp(a + size/2, size-size/2,
                 temp + size/2, threads-threads/2);
        }
        merge(a, size, temp);
    } 
}

void print_mask(__uint128_t t) {
    __uint128_t one = 1;
    for (int i=0; i< 40*3; i++) {
        if (t & ( one << i)) {
            printf("X");
        }
        else {
            printf("_");
        }
        if (i%3 == 2) {
        printf(" ");
        }
    }
    printf("\n");
}

void check_packing(cube c, int8_t last_move)
{
    cube other_c;
    int8_t unpacked_last_move;

    __uint128_t packed = pack_ce(&c, last_move);
    unpack_ce(&other_c, &unpacked_last_move, packed);

    if (cube_compare(&c, &other_c)) {
        printf("WRONG pack of cube\n");
    }
    else {
        //printf("ok pack\n");
    }
    if (last_move != unpacked_last_move) {
        printf("WRONG pack of cube\n");
    }
}

void sort_cubes(solver_cube_packed* arr, int from, int to, solver_cube_packed* mergesort_temp) 
{
    if (mergesort_temp != NULL) {
        int num_threads;
        #pragma omp parallel
        {
            #pragma omp master
            {
                num_threads = omp_get_num_threads();
            }
        }
        mergesort_parallel_omp(arr + from, to - from, mergesort_temp + from, num_threads);
    } else {
        qsort(arr + from, to - from, sizeof(solver_cube_packed), solver_cube_compare);
    }
}


//ruf ldb
int is_sister_rotation(int r1, int r2) {
    return r1 / 3 == r2 / 3;
}

int is_far_sister(int r1, int r2) {
    r1 /= 3;
    r2 /= 3;
    if ( r1 == 0 && r2 == 3) return 1;
    if ( r1 == 1 && r2 == 4) return 1;
    if ( r1 == 2 && r2 == 5) return 1;
    return 0;
}

// Returns the number of lat unique element
int remove_duplicates(solver_cube_packed* arr, int from, int to) {
    int last_unique = from;
    for (int i = from + 1; i<to; i++ ) {
        if (solver_cube_compare(arr + last_unique, arr + i) != 0) {
            arr[++last_unique] = arr[i];
        }
    }
    return last_unique + 1;
}

int legal_rotations[24];
int legal_rotations_len = 0;

void print_cache_sequence(solver_cube_packed* cache, int item);

int generate_new_level(solver_cube_packed* cache, int max_cache_size, int level_start, int level_end, int new_level_start, solver_cube_packed* mergesort_temp) {
    int new_level_end = new_level_start;
    for (int c = level_start; c < level_end; c++) {
        solver_cube_unpacked current_unpacked;
        
        unpack_ce(&current_unpacked.cube, &current_unpacked.last_move, cache[c].packed);
        int current_rotation = current_unpacked.last_move;        

        for (int i=0; i<legal_rotations_len; i++)  {
            int rotation = legal_rotations[i];
            if (c > 0 && ( is_sister_rotation(rotation, current_rotation)  || is_far_sister(rotation, current_rotation) ))
            {
                continue;
            }
            if (new_level_end >= max_cache_size) {
                printf("Memory limit exceeded. Terminating\n");
                exit(-1);
                return -1;
            }
            cube rotated = all_rotations[rotation](&current_unpacked.cube);
            cache[new_level_end].packed = pack_ce(&rotated, rotation);
            new_level_end++;
        }
    }
    sort_cubes(cache, level_end, new_level_end, mergesort_temp);

    for (int i= level_end; i<new_level_end - 1; i++) {
        if (solver_cube_compare(cache+i, cache + i+1) > 0 )
        {
            printf("SORTING FAILURE at i = %d\n", i);
            fprintf(stderr, "SORTING FAILURE\n");
            return -1;
        }
    }

    level_end = remove_duplicates(cache, level_start, new_level_end);
    return level_end;
}

int reverse_rotation(int rotation_id) {
    int r3 = rotation_id %3;
    return rotation_id - r3 + 2 - r3;
}

void print_cache_sequence(solver_cube_packed* cache, int original_item) {
     if (original_item == 0 ) return;
      
     cube current_cube;
     int8_t last_move;

     unpack_ce(&current_cube, &last_move, cache[original_item].packed);

    int item = original_item;
    while (cache[item].packed != 0) {
        item--;
    }
    
    cube rotato = all_rotations[reverse_rotation(last_move)](&current_cube);
    solver_cube_packed expected_parent;
    expected_parent.packed = pack_ce(&rotato, 0);
    
    while(item > 0 && cache[--item].packed > 0) {
        if (solver_cube_compare(&cache[item], &expected_parent) == 0) {
            print_cache_sequence(cache, item);
            printf("%s ", all_rotations_s[last_move]);
            break;
        }
    }
    
}

void print_reverse_cache_sequence(solver_cube_packed* cache, int original_item) {
    if (original_item == 0) return;    

    cube current_cube;
    int8_t last_move;
    

    unpack_ce(&current_cube, &last_move, cache[original_item].packed);
     
    int item = original_item;
    while (cache[item].packed != 0) {
         item--;
    }

    cube rotato = all_rotations[reverse_rotation(last_move)](&current_cube);
    solver_cube_packed expected_parent;
    expected_parent.packed = pack_ce(&rotato, 0);

    while(item > 0 && cache[--item].packed > 0) {
        if (solver_cube_compare(&cache[item], &expected_parent) == 0) {
            printf("%s ", all_rotations_s[reverse_rotation(last_move)]);
            print_reverse_cache_sequence(cache, item);
            break;
        }
    }
}


void find_sequence(solver_cube_packed* c, int f, int t, solver_cube_packed* cc, int ff, int tt) {
    while (f < t && ff < tt) {
        int cmp = solver_cube_compare(c + f, cc + ff);
        int8_t cf_last_move, ccff_last_move;
        cf_last_move  = unpack_last_move(c[f].packed);
        ccff_last_move  = unpack_last_move(cc[ff].packed);

        if (cmp ==0 && !is_sister_rotation( cf_last_move, ccff_last_move)) {
            
            print_cache_sequence(c, f);
            print_reverse_cache_sequence(cc, ff);
            printf("\n");
            fflush(stdout);
            f++;
            ff++;
        }
        else  if (cmp < 0)
        {
            f++;
        }
        else {
            ff++;
        }
    }
}

void solve(cube* c, cube* cc, int levels, int cache_size){
    solver_cube_packed* cache_c;
    solver_cube_packed* cache_cc;
    solver_cube_packed* mergesort_cache;

    cache_size /= 3;

    cache_c = malloc(cache_size  * sizeof(solver_cube_packed));
    cache_cc = malloc(cache_size  * sizeof(solver_cube_packed));
    mergesort_cache = malloc(cache_size  * sizeof(solver_cube_packed));

    if (mergesort_cache == NULL) {
        printf("Failed to allocate mergesort cache\n");
        exit(0);
    }

    cache_c[0].packed = pack_ce(c, 0);
    
    cache_cc[0].packed = pack_ce(cc, 0);
    
    int level_start_c = 0;
    int level_end_c = 1;

    int level_start_cc = 0;
    int level_end_cc = 1;

    int level_c = 0;
    int level_cc = 0;

    for (int i=0; i<levels; i++) {
        int new_level_end = generate_new_level(cache_c, cache_size, level_start_c, level_end_c, level_end_c + 1, mergesort_cache);
        cache_c[level_end_c].packed = 0;

        level_start_c = level_end_c + 1;
        level_end_c = new_level_end;
        level_c++;
        printf("Searching %d move solutions...\n", level_c + level_cc );

        find_sequence(cache_c, level_start_c, level_end_c , cache_cc, level_start_cc, level_end_cc);

        new_level_end = generate_new_level(cache_cc, cache_size, level_start_cc, level_end_cc, level_end_cc+1, mergesort_cache);
        cache_cc[level_end_cc].packed = 0;
        level_start_cc = level_end_cc + 1;
        level_end_cc = new_level_end;
        level_cc++;
        printf("Searching %d move solutions...\n", level_c + level_cc );
        find_sequence(cache_c, level_start_c, level_end_c , cache_cc, level_start_cc, level_end_cc);
    }
}

void set_3gen(char* chs)
{
    legal_rotations_len = 0;
    for (int i=0; i<ALL_ROTATION_LEN; i++)
    {
        char c = all_rotations_s[i][0];
        for (size_t z = 0; z < strlen(chs); z++)
        {
            if (c == chs[z]) 
            {
                legal_rotations[legal_rotations_len++] = i;
            }
        }
    }
}

void set_all_rotations(void) {
    legal_rotations_len = 18;
    for (int i=0; i<18; i++)
    {
        legal_rotations[i] = i;
    }
}

int main(void) {
    set_all_rotations();

    cube starting_position = empty_cube();
    cube attempted_position = empty_cube();

    int cache_size_in_MB;
    uint64_t cache_size;
    int scanf_result = scanf("%d", &cache_size_in_MB);
    if (scanf_result == 0) {
        printf("scanf error\n");
        exit(1);
    }

    char buffer[100];
    scanf_result= scanf("%s", buffer);
    set_3gen(buffer);
    printf("Using generator: %s\n", buffer);

    cache_size = cache_size_in_MB * (uint64_t)(1024 * 1024);
    cache_size /= sizeof(solver_cube_packed);
    printf("Allowing cache size of %u positions\n", (uint32_t)cache_size);

    while (scanf("%s", buffer) != EOF) {
        //apply rotation
        int found = 0;
        for (int i=0; i<ALL_ROTATION_LEN ; i++) {
            if (!strcmp(buffer,all_rotations_s[i])) {
                attempted_position = all_rotations[i](&attempted_position);
                found = 1;
                break;
            }
        }
        if (found) continue;
        if (!strcmp(buffer,"print")) { 
             link(&attempted_position, "print"); 
             check_packing(attempted_position, 17);
             printf("\n");
              }
        else if (!strcmp(buffer,"clear")) { starting_position = empty_cube(); attempted_position = empty_cube(); }
        else if (!strcmp(buffer,"solve")) { 
            printf("try solve\n");
            solve(&attempted_position, &starting_position, 20, cache_size);
         }
         else if (!strcmp(buffer,"reconstruct")) { 
            printf("try reconstruct\n");
            solve(&starting_position, &attempted_position, 20, cache_size);
         }
         else {
             printf("Unknown command %s\n", buffer);
         }
    }
}