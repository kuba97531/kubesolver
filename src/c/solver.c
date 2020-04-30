#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

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


typedef struct {
  solver_cube_packed *array;
  uint64_t used;
  uint64_t size;
} growing_cache;

const int initial_cache_size = 1024*16;

void init(growing_cache* cache) {
    cache->array = malloc(initial_cache_size * sizeof(solver_cube_packed));
    cache->used = 0;
    cache->size = initial_cache_size;
}

void resize(growing_cache* cache) {
    if (cache->used > cache->size - 1) {
        uint64_t new_size = cache->size * 2;
        //info("regrowing cache to %d, as it's too small", new_size);
        solver_cube_packed* bigger = realloc(cache->array, new_size * sizeof(solver_cube_packed));
        if (bigger == NULL) {
            printf("ERROR: not enough memory\n");
            exit(0);
        }
        cache->size = cache->size * 2;
        cache->array = bigger;
    }
}

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

void sort_cubes(solver_cube_packed* arr, int from, int to) 
{
    qsort(arr + from, to - from, sizeof(solver_cube_packed), solver_cube_compare);
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

// Returns the number of last unique element
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

int generate_new_level(growing_cache* cache, int level_start, int level_end, int new_level_start, int direction) {
    int new_level_end = new_level_start;
    for (int c = level_start; c < level_end; c++) {
        solver_cube_unpacked current_unpacked;
        
        unpack_ce(&current_unpacked.cube, &current_unpacked.last_move, cache->array[c].packed);
        int current_rotation = current_unpacked.last_move;        

        for (int i=0; i<legal_rotations_len; i++)  {
            int rotation = legal_rotations[i];
            if (c > 0 && is_forbidden_pair(rotation, current_rotation, direction))
            {
                continue;
            }
            cube rotated = all_rotations[rotation](&current_unpacked.cube);
            cache->array[new_level_end].packed = pack_ce(&rotated, rotation);
            new_level_end++;
            cache->used = new_level_end;
            resize(cache);
        }
    }
    sort_cubes(cache->array, level_end, new_level_end);

    for (int i= level_end; i<new_level_end - 1; i++) {
        if (solver_cube_compare(cache->array + i, cache->array + i+1) > 0 )
        {
            printf("SORTING FAILURE at i = %d\n", i);
            fprintf(stderr, "SORTING FAILURE\n");
            return -1;
        }
    }
    level_end = remove_duplicates(cache->array, level_start, new_level_end);
    cache->used = level_end;
    return level_end;
}

int reverse_rotation(int rotation_id) {
    int r3 = rotation_id %3;
    return rotation_id - r3 + 2 - r3;
}

// We know that cachepleft] is <= element and cache[right] > element
int find_index_in_cache_level(solver_cube_packed* array, int left, int right, solver_cube_packed* element) {
    assert(left >=0);
    assert(left < right);
    while (left + 1 < right) {
        int middle = (left + right)/2;
        int cmp = solver_cube_compare(array + middle, element);
        if (cmp == 0 ) {
            return middle;
        }
        if (cmp < 0) {
            left = middle;
        } else {
            right = middle;
        }
    }

    if (solver_cube_compare(array + left, element) == 0) {
        //should always be true
        return left;
    }
    
    printf("ERROR! find didn't find a sequence between %d and %d!\n", left, right);
    for (int i = left; i<right; i++) {
        int cmp = solver_cube_compare(array + i, element);
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

int find_sequence(int out_sequence[], int* out_sequence_len, solver_cube_packed* c, int f, int t, solver_cube_packed* cc, int ff, int tt, int max_number_of_output_sequences, int print_sequences) {
    int c_level_start = f;
    int cc_level_start = ff;
    int sequences_found = 0;
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
                sequences_found++;
                if (sequences_found >= max_number_of_output_sequences) {
                    return sequences_found;
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
    return sequences_found;
}

void solve_single_phase(int out_sequence[], int* out_sequence_len, cube* c, cube* cc, int levels) {
    growing_cache cache_c;
    growing_cache cache_cc;

    init(&cache_c);
    init(&cache_cc);
    
    cache_c.array[0].packed = pack_ce(c, 0);
    cache_cc.array[0].packed = pack_ce(cc, 0);
    
    int level_start_c = 0;
    int level_end_c = 1;
    int level_start_cc = 0;
    int level_end_cc = 1;
    int level_c = 0;
    int level_cc = 0;

    for (int i=0; i<levels; i++) {
        
        cache_c.array[level_end_c].packed = level_start_c;
        int new_level_end = generate_new_level(&cache_c, level_start_c, level_end_c, level_end_c + 1, 1);

        level_start_c = level_end_c + 1;
        level_end_c = new_level_end;
        level_c++;

        int found = find_sequence(out_sequence, out_sequence_len, cache_c.array, level_start_c, level_end_c , cache_cc.array, level_start_cc, level_end_cc, 1, 0);
        if (found)  goto SOLVE_PHASE_FINALLY;

        cache_cc.array[level_end_cc].packed = level_start_cc;
        new_level_end = generate_new_level(&cache_cc, level_start_cc, level_end_cc, level_end_cc+1, -1);
        level_start_cc = level_end_cc + 1;
        level_end_cc = new_level_end;
        level_cc++;

        found = find_sequence(out_sequence, out_sequence_len, cache_c.array, level_start_c, level_end_c , cache_cc.array, level_start_cc, level_end_cc, 1, 0);
        if (found) goto SOLVE_PHASE_FINALLY;
    }
    SOLVE_PHASE_FINALLY:
        free(cache_c.array);
        free(cache_cc.array);
        return;
}

void solve_two_phase(int input_sequence[], int input_sequence_len, int levels)
{
    cube starting_position, attempted_position;

    int phase_solution[80];
    int phase_count;

    starting_position = attempted_position = add_domino_elements(empty_cube());
    for (int i=0; i<input_sequence_len; i++) {
        attempted_position = all_rotations[input_sequence[i]](&attempted_position);
    }
    set_3gen("RLFBDU");
    solve_single_phase(phase_solution, &phase_count, &attempted_position, &starting_position, levels);
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
    solve_single_phase(phase_solution, &phase_count, &attempted_position, &starting_position, levels);
    print_sequence(phase_count, phase_solution);
    printf("\n");
}

void solve(cube* c, cube* cc, int levels, int max_number_of_output_sequences){
    growing_cache cache_c;
    growing_cache cache_cc;

    init(&cache_c);
    init(&cache_cc);
    
    cache_c.array[0].packed = pack_ce(c, 0);
    cache_cc.array[0].packed = pack_ce(cc, 0);
    
    int level_start_c = 0;
    int level_end_c = 1;

    int level_start_cc = 0;
    int level_end_cc = 1;

    int level_c = 0;
    int level_cc = 0;

    int sequences_found = 0;

    while(1) {
        cache_c.array[level_end_c].packed = level_start_c;
        int new_level_end = generate_new_level(&cache_c, level_start_c, level_end_c, level_end_c + 1, 1);

        level_start_c = level_end_c + 1;
        level_end_c = new_level_end;
        level_c++;
        info("Searching %d move solutions...", level_c + level_cc);

        sequences_found += find_sequence(NULL, NULL, cache_c.array, level_start_c, level_end_c , cache_cc.array, level_start_cc, level_end_cc, max_number_of_output_sequences - sequences_found, 1);
        if (sequences_found >= max_number_of_output_sequences) {
            goto SOLVE_FINALLY;
        }

        if (level_c + level_cc >= levels) {
            goto SOLVE_FINALLY;
        }

        cache_cc.array[level_end_cc].packed = level_start_cc;
        new_level_end = generate_new_level(&cache_cc, level_start_cc, level_end_cc, level_end_cc+1, -1);
        level_start_cc = level_end_cc + 1;
        level_end_cc = new_level_end;
        level_cc++;
        info("Searching %d move solutions...", level_c + level_cc );
        sequences_found += find_sequence(NULL, NULL, cache_c.array, level_start_c, level_end_c , cache_cc.array, level_start_cc, level_end_cc, max_number_of_output_sequences - sequences_found, 1);
        if (sequences_found >= max_number_of_output_sequences) {
            goto SOLVE_FINALLY;
        }
        if (level_c + level_cc >= levels) {
            goto SOLVE_FINALLY;
        }
    }
    SOLVE_FINALLY:
        free(cache_c.array);
        free(cache_cc.array);
        return;
}


int main(int argc, char* argv[]) {
    set_all_rotations();
    initialize_cube_compression();
    
    cube starting_position = full_cube();
    cube attempted_position = full_cube();

    char buffer[100];
    int max_number_of_output_sequences = 1000000;
    int max_depth = 22;

    int applied_rotations[10000];
    int applied_rotations_n = 0;

    for (int i=1; i< argc; i++) {
        char* arg = argv[i];
        if (!strcmp(arg,"--silent")) {
            disable_info_messages();
        } else if (!strcmp(arg,"--max-number-of-sequences") || !strcmp(arg,"-n")) {
            int scanf_result = sscanf(argv[++i], "%d", &max_number_of_output_sequences);
            if (!scanf_result) 
            {
                printf("ERROR: invalid argument to %s (%s).\n", arg, argv[i]);
                exit(1);
            }
        } else if (!strcmp(arg,"--max-depth-of-search") || !strcmp(arg,"-d")) {
            int scanf_result = sscanf(argv[++i], "%d", &max_depth);
            if (!scanf_result) 
            {
                printf("ERROR: invalid argument to %s (%s).\n", arg, argv[i]);
                exit(1);
            }
        }
        else {
            printf("ERROR: unknown argument %s.\n", arg);
            exit(1);
        }
    }

    info("KubeSolver 1.0.3 (C) Jakub Straszewski 2020");

    if (max_depth != 22) {
        info("Setting max search depth to %d moves.\n", max_depth);
    }
    if (max_number_of_output_sequences != 1000000) {
        info("Setting max number of output sequences to %d.\n", max_number_of_output_sequences);
    }
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
        else if (!strcmp(buffer,"init_full_cube")) { 
            attempted_position = starting_position = full_cube();
            applied_rotations_n = 0;
        }
        else if (!strcmp(buffer,"init_empty_cube")) { 
            attempted_position = starting_position = empty_cube();
            applied_rotations_n = 0;
        }
        else if (!strcmp(buffer,"init_to_current_state")) { 
            starting_position = attempted_position;
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
        else if (!strcmp(buffer,"add_edges_permutation")) { 
            starting_position = attempted_position = add_missing_edges_permutation(starting_position);
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
            solve(&attempted_position, &starting_position, max_depth, max_number_of_output_sequences);
         }
         else if (!strcmp(buffer,"reconstruct")) { 
            solve(&starting_position, &attempted_position, max_depth, max_number_of_output_sequences);
         }
         else if (!strcmp(buffer, "solve_two_phase")) {
             solve_two_phase(applied_rotations, applied_rotations_n, 11);
         }
         else {
             printf("ERROR: Unknown command %s\n", buffer);
             exit(1);
         }
    }
}