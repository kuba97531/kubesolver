#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#include "cube3.h"
#include "cube3r.h"
#include "cube_initialization.h"
#include "util.h"
#include "solver_io.h"
#include "solver_cube_compression.h"
#include "solver_growing_cache.h"
#include "version.h"

#define MAX_SEQUENCE_LEN 22
#define MAX_NUMBER_OF_SEQUENCES 1000000
#define MAX_SEQUENCE_COUNT 1500

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
        if (compare_packed_cubes_full(arr + last_unique, arr + i) != 0) {
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
            if (cube_compare(&rotated, &current_unpacked.cube) != 0) {
                cache->array[new_level_end].packed = pack_ce(&rotated, rotation);
                new_level_end++;
                cache->used = new_level_end;
                resize_growing_cache(cache);
            }
        }
    }
    sort_cubes(cache->array, level_end, new_level_end);

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
    
    if (compare_packed_cubes_only_cube_state(array + left, element) == 0) {
        //we should return the first element on the list that matches.
        return left;
    }

    //now we know that left < element, and right >= element and we will keep this as new invariant.
    //this will guarantee that when the search is over we can return right.

    while (left + 1 < right) {
        int middle = (left + right)/2;
        int cmp = compare_packed_cubes_only_cube_state(array + middle, element);
        if (cmp < 0) {
            left = middle;
        } else {
            right = middle;
        }
    }

    if (compare_packed_cubes_only_cube_state(array + right, element) != 0) {
        printf("Internal assertion failed! Couldn't restore the move sequence.!\n");
        exit(0);
    }
    return right;
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

typedef struct {
    int sequence_len;
    int sequences_count;
    int sequences[MAX_SEQUENCE_LEN * MAX_SEQUENCE_COUNT];
} list_of_sequences;

void add_reverse_sequence(list_of_sequences* out_sequences, int sequence_len, int* reverse_sequence) {
    if (out_sequences -> sequences_count == 0) {
        out_sequences->sequence_len = sequence_len;
    }
    if (out_sequences -> sequences_count == MAX_SEQUENCE_COUNT) {
        printf("ERROR. Max limit of %d half-sequences generated at one level exceeded..!\n", MAX_SEQUENCE_COUNT);
        exit(1);
    }
    if (out_sequences->sequence_len != sequence_len) {
        printf("ERROR. Bug found. Internal assertion failed! Found sequences of different length on the same level.!\n");
        exit(1);
    }
    for (int i=0; i<sequence_len; i++) {
        out_sequences->sequences[sequence_len * out_sequences->sequences_count + i] = reverse_sequence[sequence_len - 1 - i];
    }
    out_sequences->sequences_count += 1;
}

void find_cache_sequence(list_of_sequences* out_sequences, int* temp_reverse_sequence, int depth, solver_cube_packed* cache, int current_level_start, int original_item) {
    if (original_item == 0) {
        add_reverse_sequence(out_sequences, depth, temp_reverse_sequence);
        return;
    }
    
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
    temp_reverse_sequence[depth] = last_move;

    while (index <= right && compare_packed_cubes_only_cube_state(cache + index, &expected_parent) == 0) {
        find_cache_sequence(out_sequences, temp_reverse_sequence, depth + 1, cache, left, index);
        index++;
    }
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

int find_sequence(
                  int out_sequence[], 
                  int* out_sequence_len,
                  solver_cube_packed* c, int f, int t,
                  solver_cube_packed* cc, int ff, int tt,
                  int max_number_of_output_sequences, int print_sequences) {
    int c_level_start = f;
    int cc_level_start = ff;
    int sequences_found = 0;
    while (f < t && ff < tt) {
        int cmp = compare_packed_cubes_only_cube_state(c + f, cc + ff);
        if (cmp == 0) {
            int af = f;
            int aff = ff;
            while (af < t && compare_packed_cubes_only_cube_state(c + f, c + af) == 0) {
                af++;
            }
            while (aff < tt && compare_packed_cubes_only_cube_state(cc + ff, cc + aff) == 0) {
                aff++;
            }
            for (int _f = f; _f < af; _f++) 
            for (int _ff = ff; _ff < aff; _ff++) {
                int temp_array[MAX_SEQUENCE_LEN];
                list_of_sequences left_sequences = { 0 };
                list_of_sequences right_sequences = { 0 };
                find_cache_sequence(&left_sequences, temp_array, 0, c, c_level_start, _f);
                find_cache_sequence(&right_sequences, temp_array, 0, cc, cc_level_start, _ff);
                if (left_sequences.sequences_count == 0 || right_sequences.sequences_count == 0) {
                    printf("Internal assertion failed! It was impossible to reconstruct a sequence.\n");
                    exit(1);
                }
                int sequence_len = left_sequences.sequence_len + right_sequences.sequence_len;
                for (int left_index = 0; left_index < left_sequences.sequences_count; left_index ++) {
                    for (int i=0; i< left_sequences.sequence_len; i++) {
                        temp_array[i] = left_sequences.sequences[left_sequences.sequence_len * left_index + i];
                    }
                    for (int right_index = 0; right_index < right_sequences.sequences_count; right_index++) {
                        reverse_and_merge_into_first(
                            left_sequences.sequence_len, temp_array, 
                            right_sequences.sequence_len, right_sequences.sequences + (right_index * right_sequences.sequence_len));

                        if (!is_forbidden_sequence(sequence_len, temp_array, 1)) {
                            if (out_sequence != NULL && out_sequence_len != NULL) {
                                *out_sequence_len = sequence_len;
                                for (int i=0; i< sequence_len;i++) 
                                { 
                                    out_sequence[i] = temp_array[i];
                                }
                            }
                            if (print_sequences) {
                                print_sequence(sequence_len, temp_array);
                                printf("\n");
                                fflush(stdout);
                            }
                            sequences_found++;
                            if (sequences_found >= max_number_of_output_sequences) {
                                return sequences_found;
                            }
                        }
                    }
                }
            }
            f = af;
            ff = aff;
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

    init_growing_cache(&cache_c);
    init_growing_cache(&cache_cc);
    
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
    printf("  ");
    set_3gen("R2L2F2B2DU");
    solve_single_phase(phase_solution, &phase_count, &attempted_position, &starting_position, levels);
    print_sequence(phase_count, phase_solution);
    printf("\n");
}

typedef struct {
    int max_number_of_output_sequences;
    int max_depth_after_find;
    int max_depth;
} solve_settings;

typedef struct {
    growing_cache cache;
    int level_start;
    int level_end;
} solve_local_items;

void solve(cube* c, cube* cc, solve_settings settings){

    solve_local_items items[2];
    
    for (int i=0; i<2; i++) {
        init_growing_cache(&(items[i].cache));
        items[i].level_start = 0;
        items[i].level_end = 1;
    }
    items[0].cache.array[0].packed = pack_ce(c, 0);
    items[1].cache.array[0].packed = pack_ce(cc, 0);

    int sequences_found = 0;

    int levels = 0;
    while(1) {
        int current_cache_id = levels % 2; // alternate between 0 and 1
        int current_direction = 1 - 2 * current_cache_id; // alternate between 1 and -1
        items[current_cache_id].cache.array[items[current_cache_id].level_end].packed = items[current_cache_id].level_start;

        int new_level_end = generate_new_level(&items[current_cache_id].cache, items[current_cache_id].level_start, items[current_cache_id].level_end, items[current_cache_id].level_end + 1, current_direction);

        items[current_cache_id].level_start = items[current_cache_id].level_end + 1;
        items[current_cache_id].level_end = new_level_end;
        levels++;
        info("Searching %d move solutions...", levels);

        sequences_found += find_sequence(NULL, NULL, 
                                        items[0].cache.array, items[0].level_start, items[0].level_end, 
                                        items[1].cache.array, items[1].level_start, items[1].level_end, 
                                        settings.max_number_of_output_sequences - sequences_found, 1);
        if (sequences_found >= settings.max_number_of_output_sequences) {
            goto SOLVE_FINALLY;
        }
        if (sequences_found > 0 && settings.max_depth_after_find >= 0 && levels + settings.max_depth_after_find < settings.max_depth) {
            settings.max_depth = levels + settings.max_depth_after_find;
        }
        if (levels >= settings.max_depth) {
            goto SOLVE_FINALLY;
        }
        current_cache_id = 1 - current_cache_id;
    }
    SOLVE_FINALLY:
        for (int i=0; i<2; i++) {
            free(items[i].cache.array);
        }
        return;
}

int main(int argc, char* argv[]) {
    set_all_rotations();
    initialize_cube_compression();
    
    cube starting_position = full_cube();
    cube attempted_position = full_cube();

    char buffer[100];
    solve_settings settings = {
        .max_depth = MAX_SEQUENCE_LEN,
        .max_number_of_output_sequences = MAX_NUMBER_OF_SEQUENCES,
        .max_depth_after_find = -1
    };

    int applied_rotations[10000];
    int applied_rotations_n = 0;

    for (int i=1; i< argc; i++) {
        char* arg = argv[i];
        if (!strcmp(arg,"--silent")) {
            disable_info_messages();
        } else if (!strcmp(arg,"--max-number-of-sequences") || !strcmp(arg,"-n")) {
            int scanf_result = sscanf(argv[++i], "%d", &settings.max_number_of_output_sequences);
            if (!scanf_result) 
            {
                printf("ERROR: invalid argument to %s (%s).\n", arg, argv[i]);
                exit(1);
            }
        } else if (!strcmp(arg,"--max-depth-of-search") || !strcmp(arg,"-d")) {
            int scanf_result = sscanf(argv[++i], "%d", &settings.max_depth);
            if (!scanf_result) 
            {
                printf("ERROR: invalid argument to %s (%s).\n", arg, argv[i]);
                exit(1);
            }
            settings.max_depth = MIN(settings.max_depth, MAX_SEQUENCE_LEN);
        } else if (!strcmp(arg,"--max-depth-after-first-match") || !strcmp(arg,"-da")) {
            int scanf_result = sscanf(argv[++i], "%d", &settings.max_depth_after_find);
            if (!scanf_result) 
            {
                printf("ERROR: invalid argument to %s (%s).\n", arg, argv[i]);
                exit(1);
            }
        } else {
            printf("ERROR: unknown argument %s.\n", arg);
            exit(1);
        }
    }

    info(WELCOME_STRING);

    if (settings.max_depth < MAX_SEQUENCE_LEN) {
        info("Setting max search depth to %d moves.\n", settings.max_depth);
    }
    if (settings.max_number_of_output_sequences != MAX_NUMBER_OF_SEQUENCES) {
        info("Setting max number of output sequences to %d.\n", settings.max_number_of_output_sequences);
    }
    if (settings.max_depth_after_find != -1) {
        info("Setting additional depth search after first find to %d.\n", settings.max_depth_after_find);
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
        else if (!strcmp(buffer,"set")) {
            int scan_result = scanf(" %s", buffer);
            if (scan_result == 0) {
                printf("ERROR: missing argument to set\n");
                exit(1);
            }
            if (!strcmp(buffer,"d") || !(strcmp(buffer,"max-depth-of-search"))){
                scan_result = scanf(" %d", &settings.max_depth);
                if (scan_result == 0) {
                    printf("ERROR: wrong argument to set max-depth-of-search\n");
                    exit(1);
                }
                settings.max_depth = MIN(settings.max_depth, MAX_SEQUENCE_LEN);
                info("Setting max search depth to %d moves.\n", settings.max_depth);
            }
            if (!strcmp(buffer,"da") || !(strcmp(buffer,"max-depth-after-first-match"))){
                scan_result = scanf(" %d", &settings.max_depth_after_find);
                if (scan_result == 0) {
                    printf("ERROR: wrong argument to set max-additional-depth-of-search\n");
                    exit(1);
                }
                info("Will search sequences longer by at most %d moves than the shortest found sequence.\n", settings.max_depth_after_find);
            }
            else if (!strcmp(buffer,"n") || !(strcmp(buffer,"max-number-of-sequences"))){
                scan_result = scanf(" %d", &settings.max_number_of_output_sequences);
                if (scan_result == 0) {
                    printf("ERROR: wrong argument to set\n");
                    exit(1);
                }
                info("Setting max number of output sequences to %d.\n", settings.max_number_of_output_sequences);
            }

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
            solve(&attempted_position, &starting_position, settings);
         }
         else if (!strcmp(buffer,"reconstruct")) { 
            solve(&starting_position, &attempted_position, settings);
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
