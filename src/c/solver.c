#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cube3.c"
#include "cube3r.c"


typedef struct 
{
    cube cube;
    int8_t last_move;
    int parent_index;
} solver_cube;

int solver_cube_compare(const void *s1, const void *s2)
{
    return cube_compare(&((solver_cube *)s1)->cube, &((solver_cube *)s2)->cube);
}

void sort_cubes(solver_cube* arr, int from, int to) 
{
    qsort(arr + from, to - from, sizeof(solver_cube), cube_compare);
}

int is_sister_rotation(int r1, int r2) {
    return r1 / 3 == r2 / 3;
}


// void swap(solver_cube *arr, int *parr, int a, int b)
// {
//   solver_cube t=arr[a]; arr[a]=arr[b]; arr[b]=t;

//   int it=parr[a] ; parr[a]=parr[b]; parr[b]=it;
// }

// void sort(solver_cube *arr, int *parr, int beg, int end)
// {
//     if (end > beg + 1)
//     {
//         swap(arr, parr, beg, (beg + end)/2);
//         int piv = beg;
//         int l = beg + 1, r = end;
//         while (l < r)
//         {
//             if (solver_cube_compare(arr + l, arr + piv) < 0)
//                 l++;
//             else
//                 swap(arr, parr, l, --r);
//         }
//         swap(arr, parr, --l, beg);

//         sort(arr, parr, beg, l);
//         sort(arr, parr, r, end);
//     }
// }

// Returns the number of lat unique element
int remove_duplicates(solver_cube* arr, int from, int to) {
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

int generate_new_level(solver_cube* cache, int max_cache_size, int level_start, int level_end ) {
    int new_level_end = level_end;
    for (int c = level_start; c < level_end; c++) {
        cube current_cube = cache[c].cube;
        int current_rotation = cache[c].last_move;

        for (int i=0; i<legal_rotations_len; i++)  {
            int rotation = legal_rotations[i];
            if (c > 0 && is_sister_rotation(rotation, current_rotation))
            {
                continue;
            }
            if (new_level_end >= max_cache_size) {
                printf("Memory limit exceeded. Terminating\n");
                exit(-1);
                return -1;
            }
            cache[new_level_end].cube = all_rotations[rotation](&current_cube);
            cache[new_level_end].last_move = rotation;
            cache[new_level_end].parent_index = c;
            new_level_end++;
        }
    }
    sort_cubes(cache, level_end, new_level_end);
    //qsort(cache + level_end, new_level_end - level_end, sizeof(cube), cube_compare);

    for (int i= level_end; i<new_level_end - 1; i++) {
        if (cube_compare(cache+i, cache + i+1) > 0 )
        {
            printf("SORTING FAILURE\n");
            fprintf(stderr, "SORTING FAILURE\n");
            return -1;
        }
    }

    level_end = remove_duplicates(cache, level_start, new_level_end);
    return level_end;
}

void print_cache_sequence(solver_cube* cache, int item) {
     if (item == 0 ) return;
    
      print_cache_sequence(cache, cache[item].parent_index);
    
     cube current_cube = cache[item].cube;
     cube parent_cube = cache[cache[item].parent_index].cube;

     for (int i=0; i<ALL_ROTATION_LEN; i++)  {
         cube rotato = all_rotations[i](&parent_cube);
         if (cube_compare(&current_cube, &rotato) == 0) {
             printf("%s ", all_rotations_s[i]);
             break;
         }
     }
}

void print_reverse_cache_sequence(solver_cube* cache, int item) {
    if (item ==0 ) return;    

    cube current_cube = cache[item].cube;
    cube parent_cube = cache[cache[item].parent_index].cube;

    for (int i=0; i<ALL_ROTATION_LEN; i++)  {
            cube rotato = all_rotations[i](&current_cube);
        if (cube_compare(&parent_cube, &rotato) == 0) {
            printf("%s ", all_rotations_s[i]);
            break;
        }
    }
    print_reverse_cache_sequence(cache, cache[item].parent_index);
}


void find_sequence(solver_cube* c, int f, int t, solver_cube* cc, int ff, int tt) {
    while (f < t && ff < tt) {
        int cmp = solver_cube_compare(c + f, cc + ff);
        if (cmp ==0 && !is_sister_rotation(c[f].last_move, cc[ff].last_move)) {
            
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
    solver_cube* cache_c;
    solver_cube* cache_cc;

    cache_size /= 2;

    cache_c = malloc(cache_size  * sizeof(solver_cube));
    cache_cc = malloc(cache_size  * sizeof(solver_cube));

    cache_c[0].cube = *c;
    cache_c[0].last_move = -1;
    cache_c[0].parent_index = -1;
    

    cache_cc[0].cube = *cc;
    cache_cc[0].last_move = -1;
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
        for (int z = 0; z < strlen(chs); z++)
        {
            if (c == chs[z]) 
            {
                legal_rotations[legal_rotations_len++] = i;
            }
        }
    }
}

void set_all_rotations() {
    legal_rotations_len = 18;
    for (int i=0; i<18; i++)
    {
        legal_rotations[i] = i;
    }
}

int main() {
    set_all_rotations();

    cube starting_position = empty_cube();
    cube attempted_position = empty_cube();

    long unsigned cache_size;
    int scanf_result= scanf("%lud", &cache_size);

    printf("cache_size = %lu Mega\n", cache_size);

    
    char buffer[100];
    scanf_result= scanf("%s", buffer);
    set_3gen(buffer);
    printf("Using generator: %s\n", buffer);

    cache_size *= 1024 * 1024;
    cache_size /= sizeof(solver_cube);

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
        if (!strcmp(buffer,"print")) {  link(&attempted_position, "print"); printf("\n"); }
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