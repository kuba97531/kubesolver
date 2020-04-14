#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <omp.h>

#include "cube3.h"
#include "cube3r.h"
#include "cube_compression.h"
#include "cube_initialization.h"
#include "util.h"
#include "solver_io.h"

typedef struct 
{
    __uint128_t packed; 
} solver_cube_packed;

typedef struct 
{
    cube cube; 
    int8_t last_move;
} solver_cube_unpacked;

// int solver_cube_compare(const void *s1, const void *s2)
// {
//     cube c1, c2;
//     int8_t last_move;
//     unpack_ce(&c1, &last_move, ((solver_cube_packed *)s1)->packed);
//     unpack_ce(&c2, &last_move, ((solver_cube_packed *)s2)->packed);
//     return cube_compare(&c1, &c2);
// }

int solver_cube_compare(const void *s1, const void *s2)
{
    __uint128_t p1 = ((solver_cube_packed *)s1)->packed >> 8;
    __uint128_t p2 = ((solver_cube_packed *)s2)->packed >> 8;
    if (p1 > p2) {
        return 1;
    }
    else if (p2 > p1) {
        return -1;
    }
    return 0;
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


    if (cube_compare(&c, &other_c) != 0) {
        link(&other_c, "print"); 
        printf("WRONG pack of cube\n");
        exit(0);
    }
    else {
        //printf("ok pack\n");
    }
    if (last_move != unpacked_last_move) {
        printf("WRONG pack of cube last_move\n");
    }
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
    assert_sorted(arr, from, to-from);
}


// e.g. R and R'
int is_sister_rotation(int r1, int r2) {
    return r1 / 3 == r2 / 3;
}

int is_forbidden_pair(int r1, int r2, int direction) {
    if (is_sister_rotation(r1, r2)) {
        return 1;
    }
    if (rotation_families[r1] == rotation_families[r2]) {
        if (direction == 1) {
            return r1 > r2;
        }
        else {
            return r1 < r2;
        }
    }
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

int legal_rotations[40];
int legal_rotations_len = 0;

int generate_new_level(solver_cube_packed* cache, int max_cache_size, int level_start, int level_end, int new_level_start, solver_cube_packed* mergesort_temp, int direction) {
    int new_level_end = new_level_start;
    for (int c = level_start; c < level_end; c++) {
        solver_cube_unpacked current_unpacked;
        
        unpack_ce(&current_unpacked.cube, &current_unpacked.last_move, cache[c].packed);
        int current_rotation = current_unpacked.last_move;        

        for (int i=0; i<legal_rotations_len; i++)  {
            int rotation = legal_rotations[i];
            if (c > 0 && is_forbidden_pair(rotation, current_rotation, direction))
            {
                continue;
            }
            if (new_level_end >= max_cache_size) {
                info("Memory limit exceeded. Terminating\n");
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

// We know that cachepleft] is <= element and cache[right] > element
int find_index_in_cache_level(solver_cube_packed* cache, int left, int right, solver_cube_packed* element) {
    assert(left >=0);
    assert(left < right);
    while (left + 1 < right) {
        int middle = (left + right)/2;
        int cmp = solver_cube_compare(cache + middle, element);
        if (cmp == 0 ) {
            return middle;
        }
        if (cmp < 0) {
            left = middle;
        } else {
            right = middle;
        }
    }

    if (solver_cube_compare(cache + left, element) == 0) {
        //should always be true
        return left;
    }
    
    printf("ERROR! find didn't find a sequence between %d and %d!\n", left, right);
    for (int i = left; i<right; i++) {
        int cmp = solver_cube_compare(cache + i, element);
        if (cmp ==0 ) {
            printf("but should have found %d\n", i);
        }
    }
    exit(0);
}

void set_3gen(char* chs)
{
    legal_rotations_len = 0;
    for (int i=0; i<ALL_ROTATION_LEN; i++)
    {
        char* c = all_rotations_s[i];
        for (size_t z = 0; z < strlen(chs); z++)
        {
            char s2[] = "_2";
            if (z < strlen(chs) - 1 && chs[z+1] == '2')
            {
                s2[0] = chs[z];
                if (!strcmp(c, s2)) {
                    legal_rotations[legal_rotations_len++] = i;
                }
            }
            else if (c[0] == chs[z]) 
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

void find_cache_sequence(int* out_sequence_len, int* out_sequence, solver_cube_packed* cache, int current_level_start, int original_item) {
    if (original_item == 0 ) return;
      
    cube current_cube;
    int8_t last_move;

    unpack_ce(&current_cube, &last_move, cache[original_item].packed);

    cube rotato = all_rotations[reverse_rotation(last_move)](&current_cube);
    solver_cube_packed expected_parent;
    expected_parent.packed = pack_ce(&rotato, 0);
    
    int right = current_level_start -1;
    int left = (int) cache[right].packed;
    assert(left >= 0);
    int index = find_index_in_cache_level(cache, left, right, &expected_parent);
    find_cache_sequence(out_sequence_len, out_sequence, cache, left, index);
    out_sequence[*out_sequence_len] = last_move;
    (*out_sequence_len)++;
}

void print_sequence(int sequence_len, int sequence[]) {
    for (int i=0; i<sequence_len; i++) {
        int last_move = sequence[i];
        printf("%s ", all_rotations_s[last_move]);
    }
}

void reverse_and_merge_into_first(int sequence_len, int sequence[], int rev_seq_len, int rev_seq[]) {
    for (int i= 0; i<rev_seq_len; i++) {
        int last_move = reverse_rotation(rev_seq[rev_seq_len - i - 1]);
        sequence[i + sequence_len] = last_move;
    }
}

int is_forbidden_sequence(int sequence_len, int sequence[], int direction) {
    for (int i=1; i<sequence_len; i++) {
        if (is_forbidden_pair(sequence[i], sequence[i-1], direction)) 
        {
            return 1;
        }
    }
    return 0;
}

int find_sequence(int out_sequence[], int* out_sequence_len, solver_cube_packed* c, int f, int t, solver_cube_packed* cc, int ff, int tt, int exit_on_find, int print_sequences) {
    int c_level_start = f;
    int cc_level_start = ff;
    int result = 0;
    while (f < t && ff < tt) {
        int cmp = solver_cube_compare(c + f, cc + ff);
        if (cmp == 0) {
            int left_count = 0;
            int left_array[60];
            find_cache_sequence(&left_count, left_array, c, c_level_start, f);
            int right_count = 0;
            int right_array[30];
            find_cache_sequence(&right_count, right_array, cc, cc_level_start, ff);
            reverse_and_merge_into_first(left_count, left_array, right_count, right_array);
            if (!is_forbidden_sequence(left_count + right_count, left_array, 1)) {
                if (out_sequence != NULL && out_sequence_len != NULL) {
                    *out_sequence_len = left_count + right_count;
                    for (int i=0; i< left_count + right_count;i++) 
                    { 
                        out_sequence[i] = left_array[i];
                    }
                }
                if (print_sequences) {
                    print_sequence(left_count + right_count, left_array);
                    printf("\n");
                    fflush(stdout);
                }
                if (exit_on_find) {
                    return 1;
                }
                else {
                    result = 1;
                }
            }
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
    return result;
}

void solve_single_phase(int out_sequence[], int* out_sequence_len, cube* c, cube* cc, int levels, uint64_t cache_size) {
    solver_cube_packed* cache_c;
    solver_cube_packed* cache_cc;
    solver_cube_packed* mergesort_cache;

    cache_size /= 3;

    cache_c = malloc(cache_size  * sizeof(solver_cube_packed));
    cache_cc = malloc(cache_size  * sizeof(solver_cube_packed));
    mergesort_cache = malloc(cache_size  * sizeof(solver_cube_packed));
    if (cache_c == NULL || cache_cc == NULL || mergesort_cache == NULL) {
        printf("ERROR: not enough memory\n");
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
        
        cache_c[level_end_c].packed = level_start_c;
        int new_level_end = generate_new_level(cache_c, cache_size, level_start_c, level_end_c, level_end_c + 1, mergesort_cache, 1);

        level_start_c = level_end_c + 1;
        level_end_c = new_level_end;
        level_c++;

        int found = find_sequence(out_sequence, out_sequence_len, cache_c, level_start_c, level_end_c , cache_cc, level_start_cc, level_end_cc, 1, 0);
        if (found)  goto SOLVE_PHASE_FINALLY;

        cache_cc[level_end_cc].packed = level_start_cc;
        new_level_end = generate_new_level(cache_cc, cache_size, level_start_cc, level_end_cc, level_end_cc+1, mergesort_cache, -1);
        level_start_cc = level_end_cc + 1;
        level_end_cc = new_level_end;
        level_cc++;

        found = find_sequence(out_sequence, out_sequence_len, cache_c, level_start_c, level_end_c , cache_cc, level_start_cc, level_end_cc, 1, 0);
        if (found) goto SOLVE_PHASE_FINALLY;
    }
    SOLVE_PHASE_FINALLY:
        free(cache_c);
        free(cache_cc);
        if (mergesort_cache != NULL) free(mergesort_cache);
        return;
}

void solve_two_phase(int input_sequence[], int input_sequence_len, int levels, uint64_t cache_size)
{
    cube starting_position, attempted_position;

    int phase_solution[80];
    int phase_count;

    starting_position = attempted_position = add_domino_elements(empty_cube());
    for (int i=0; i<input_sequence_len; i++) {
        attempted_position = all_rotations[input_sequence[i]](&attempted_position);
    }
    set_3gen("RLFBDU");
    solve_single_phase(phase_solution, &phase_count, &attempted_position, &starting_position, levels, cache_size);
    print_sequence(phase_count, phase_solution);

    starting_position = attempted_position = full_cube();
    for (int i=0; i<input_sequence_len; i++) {
        attempted_position = all_rotations[input_sequence[i]](&attempted_position);
    }
    for (int i=0; i<phase_count; i++) {
        attempted_position = all_rotations[phase_solution[i]](&attempted_position);
    }
    printf("\n");
    set_3gen("R2L2F2B2DU");
    solve_single_phase(phase_solution, &phase_count, &attempted_position, &starting_position, levels, cache_size);
    print_sequence(phase_count, phase_solution);
    printf("\n");

    // for (int i=0; i<first_phase_count; i++) {
    //     cc = all_rotations[first_phase[i]](cc);
    // }
    // set_3gen("R2L2");
    // solve_single_phase(phase_solution, &phase_count, c, cc, levels, cache_size);
    // print_sequence(phase_count, phase_solution);

}

void solve(cube* c, cube* cc, int levels, uint64_t cache_size, int exit_on_find){
    solver_cube_packed* cache_c;
    solver_cube_packed* cache_cc;
    solver_cube_packed* mergesort_cache;

    cache_size /= 3;

    cache_c = malloc(cache_size  * sizeof(solver_cube_packed));
    cache_cc = malloc(cache_size  * sizeof(solver_cube_packed));
    mergesort_cache = malloc(cache_size  * sizeof(solver_cube_packed));
    if (cache_c == NULL || cache_cc == NULL) {
        printf("ERROR: not enough memory\n");
        exit(0);
    }
    if (mergesort_cache == NULL) {
        info("Failed to allocate enough memory for extra cache - using qsort instead of mergesort\n");
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
        
        cache_c[level_end_c].packed = level_start_c;
        int new_level_end = generate_new_level(cache_c, cache_size, level_start_c, level_end_c, level_end_c + 1, mergesort_cache, 1);

        level_start_c = level_end_c + 1;
        level_end_c = new_level_end;
        level_c++;
        info("Searching %d move solutions...", level_c + level_cc );

        int found = find_sequence(NULL, NULL, cache_c, level_start_c, level_end_c , cache_cc, level_start_cc, level_end_cc, exit_on_find, 1);
        if (found && exit_on_find) {
            goto SOLVE_FINALLY;
        }

        cache_cc[level_end_cc].packed = level_start_cc;
        new_level_end = generate_new_level(cache_cc, cache_size, level_start_cc, level_end_cc, level_end_cc+1, mergesort_cache, -1);
        level_start_cc = level_end_cc + 1;
        level_end_cc = new_level_end;
        level_cc++;
        info("Searching %d move solutions...", level_c + level_cc );
        found = find_sequence(NULL, NULL, cache_c, level_start_c, level_end_c , cache_cc, level_start_cc, level_end_cc, exit_on_find, 1);
        if (found && exit_on_find) {
            goto SOLVE_FINALLY;
        }
    }
    SOLVE_FINALLY:
        free(cache_c);
        free(cache_cc);
        if (mergesort_cache != NULL) free(mergesort_cache);
        return;
}


int main(int argc, char* argv[]) {
    uint64_t cache_size = portable_available_memory();
    cache_size /= sizeof(solver_cube_packed);

    set_all_rotations();
    initialize_cube_compression();
    
    cube starting_position = full_cube();
    cube attempted_position = full_cube();

    char buffer[100];
    int exit_on_find = 0;

    int applied_rotations[10000];
    int applied_rotations_n = 0;

    for (int i=0; i< argc; i++) {
        char* arg = argv[i];
        if (!strcmp(arg,"--silent")) {
            disable_info_messages();
        }
        if (!strcmp(arg,"--exit_on_find")) {
            exit_on_find = 1;
        }
    }

    info("KubeSolver 1.0 (C) Jakub Straszewski 2020");

    while (scanf("%s", buffer) != EOF) {
        //apply rotation
        int found = 0;
        for (int i=0; i<ALL_ROTATION_LEN ; i++) {
            if (!strcmp(buffer,all_rotations_s[i])) {
                attempted_position = all_rotations[i](&attempted_position);
                applied_rotations[applied_rotations_n++] = i;
                found = 1;
                break;
            }
        }
        if (found) continue;
        if (!strcmp(buffer,"calculate_repetitions")) {
            cube position = starting_position;
            int n = 0;
            while (n == 0 || cube_compare(&position, &starting_position)) {
                n++;
                for (int i=0; i< applied_rotations_n; i++) {
                    position = all_rotations[applied_rotations[i]](&position);
                }
                link(&position, "print"); 

            }
            link(&position, "position"); 
            link(&starting_position, "starting position"); 
            info("Requires %d moves to repeat", n);
        }
        else if (!strcmp(buffer,"print")) { 
             link(&attempted_position, "print"); 
             check_packing(attempted_position, 17);
             printf("\n");
             }
        else if (!strcmp(buffer,"set_gen")) { 
            int scan_result = scanf(" %s", buffer);
            if (scan_result == 0) {
                printf("ERROR: missing argument to set_gen\n");
                exit(1);
            }
            set_3gen(buffer);
              }
        else if (!strcmp(buffer,"exit_on_find")) { 
            exit_on_find = 1;
        }
        else if (!strcmp(buffer,"init_full_cube")) { 
            attempted_position = starting_position = full_cube();
            applied_rotations_n = 0;
        }
        else if (!strcmp(buffer,"init_empty_cube")) { 
            attempted_position = starting_position = empty_cube();
            applied_rotations_n = 0;
        }
        else if (!strcmp(buffer,"add_edge")) { 
            int scan_result = scanf(" %s", buffer);

            if (scan_result == 0) {
                printf("ERROR: missing argument to add_edge\n");
                exit(1);
            }
            starting_position = attempted_position = add_edge(starting_position, buffer);
        }
        else if (!strcmp(buffer,"add_corner")) { 
            int scan_result = scanf(" %s", buffer);

            if (scan_result == 0) {
                printf("ERROR: missing argument to add_corner\n");
                exit(1);
            }
            starting_position = attempted_position = add_corner(starting_position, buffer);
        }
        else if (!strcmp(buffer,"add_corners_orientation")) { 
            starting_position = attempted_position = add_missing_corner_orientation(starting_position);
        }
        else if (!strcmp(buffer,"add_corners_permutation")) { 
            starting_position = attempted_position = add_missing_corner_permutation(starting_position);
        }
        else if (!strcmp(buffer,"add_corners")) { 
            starting_position = attempted_position = add_missing_corners(starting_position);
        }
        else if (!strcmp(buffer,"add_edges_orientation")) { 
            starting_position = attempted_position = add_missing_edges_orientation(starting_position);
        }
        else if (!strcmp(buffer,"add_edges")) { 
            starting_position = attempted_position = add_missing_edges(starting_position);
        }
        else if (!strcmp(buffer,"set_domino_cube")) { 
            starting_position = attempted_position = add_domino_elements(empty_cube());
        }
        else if (!strcmp(buffer,"add_f2l")) { 
            cube c = starting_position;
            c = add_corner(c, "DFR");
            c = add_corner(c, "DFL");
            c = add_corner(c, "DBR");
            c = add_corner(c, "DBL");
            c = add_edge(c, "DF");
            c = add_edge(c, "DL");
            c = add_edge(c, "DR");
            c = add_edge(c, "DB");
            c = add_edge(c, "FR");
            c = add_edge(c, "FL");
            c = add_edge(c, "BR");
            c = add_edge(c, "BL");
            starting_position = attempted_position = c;
        }
        else if (!strcmp(buffer,"add_cross")) { 
            cube c = starting_position;
            c = add_edge(c, "DF");
            c = add_edge(c, "DL");
            c = add_edge(c, "DR");
            c = add_edge(c, "DB");
            starting_position = attempted_position = c;
        }
        else if (!strcmp(buffer,"solve")) { 
            solve(&attempted_position, &starting_position, 11, cache_size, exit_on_find);
         }
         else if (!strcmp(buffer,"reconstruct")) { 
            solve(&starting_position, &attempted_position, 11, cache_size, exit_on_find);
         }
         else if (!strcmp(buffer, "solve_two_phase")) {
             solve_two_phase(applied_rotations, applied_rotations_n, 11, cache_size);
         }
         else {
             printf("ERROR: Unknown command %s\n", buffer);
             exit(1);
         }
    }
}