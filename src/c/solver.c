#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cube3.h"
#include "cube3r.h"
#include <stdint.h>
#include "cube_compression.h"

typedef struct 
{
    __uint128_t packed; 
    int parent_index;
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

void sort_cubes(solver_cube_packed* arr, int from, int to) 
{
    qsort(arr + from, to - from, sizeof(solver_cube_packed), solver_cube_compare);
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

int generate_new_level(solver_cube_packed* cache, int max_cache_size, int level_start, int level_end ) {
    int new_level_end = level_end;
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
            cache[new_level_end].parent_index = c;
            new_level_end++;
        }
    }
    sort_cubes(cache, level_end, new_level_end);
    //qsort(cache + level_end, new_level_end - level_end, sizeof(cube), cube_compare);

    for (int i= level_end; i<new_level_end - 1; i++) {
        if (solver_cube_compare(cache+i, cache + i+1) > 0 )
        {
            printf("SORTING FAILURE\n");
            fprintf(stderr, "SORTING FAILURE\n");
            return -1;
        }
    }

    level_end = remove_duplicates(cache, level_start, new_level_end);
    return level_end;
}

void print_cache_sequence(solver_cube_packed* cache, int item) {
     if (item == 0 ) return;
    
      print_cache_sequence(cache, cache[item].parent_index);
    
     cube current_cube, parent_cube;
     int8_t last_move;
     unpack_ce(&current_cube, &last_move, cache[item].packed);
     unpack_ce(&parent_cube, &last_move, cache[cache[item].parent_index].packed);

     for (int i=0; i<ALL_ROTATION_LEN; i++)  {
         cube rotato = all_rotations[i](&parent_cube);
         if (cube_compare(&current_cube, &rotato) == 0) {
             printf("%s ", all_rotations_s[i]);
             break;
         }
     }
}

void print_reverse_cache_sequence(solver_cube_packed* cache, int item) {
    if (item ==0 ) return;    

     cube current_cube, parent_cube;
     int8_t last_move;
     unpack_ce(&current_cube, &last_move, cache[item].packed);
     unpack_ce(&parent_cube, &last_move, cache[cache[item].parent_index].packed);

    for (int i=0; i<ALL_ROTATION_LEN; i++)  {
        cube rotato = all_rotations[i](&current_cube);
        if (cube_compare(&parent_cube, &rotato) == 0) {
            printf("%s ", all_rotations_s[i]);
            break;
        }
    }
    print_reverse_cache_sequence(cache, cache[item].parent_index);
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

    cache_size /= 2;

    cache_c = malloc(cache_size  * sizeof(solver_cube_packed));
    cache_cc = malloc(cache_size  * sizeof(solver_cube_packed));

    cache_c[0].packed = pack_ce(c, 0);
    cache_c[0].parent_index = -1;
    
    cache_cc[0].packed = pack_ce(cc, 0);
    cache_cc[0].parent_index = -1;

    int level_start_c = 0;
    int level_end_c = 1;

    int level_start_cc = 0;
    int level_end_cc = 1;

    int level_c = 0;
    int level_cc = 0;

    for (int i=0; i<levels; i++) {
        int new_level_end = generate_new_level(cache_c, cache_size, level_start_c, level_end_c);
        level_start_c = level_end_c;
        level_end_c = new_level_end;
        level_c++;
        printf("Searching %d move solutions...\n", level_c + level_cc );

        find_sequence(cache_c, level_start_c, level_end_c , cache_cc, level_start_cc, level_end_cc);

        new_level_end = generate_new_level(cache_cc, cache_size, level_start_cc, level_end_cc);
        level_start_cc = level_end_cc;
        level_end_cc = new_level_end;
        level_cc++;
        printf("Searching %d move solutions...\n", level_c + level_cc );
        find_sequence(cache_c, level_start_c, level_end_c , cache_cc, level_start_cc, level_end_cc);
    }
}

void set_3gen(char* chs)
{
    legal_rotations_len = 0;
    for (int i=0; i<18; i++)
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

    long unsigned cache_size;
    int scanf_result = scanf("%lud", &cache_size);
    if (scanf_result == 0) {
        printf("scanf error\n");
        exit(1);
    }

    printf("cache_size = %lu Mega\n", cache_size);

    
    char buffer[100];
    scanf_result= scanf("%s", buffer);
    set_3gen(buffer);
    printf("Using generator: %s\n", buffer);

    cache_size *= 1024 * 1024;
    cache_size /= sizeof(solver_cube_packed);

    while (scanf("%s", buffer) != EOF) {
        //applu rotation
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
            solve(&starting_position, &attempted_position, 20, cache_size);
         }
         else {
             printf("Unknown command %s\n", buffer);
         }
    }
}