#include<stdio.h>
#include<stdlib.h>
#include "cube3.c"
#include "cube3r.c"

void sort_cubes(cube* arr, int from, int to) {
    qsort(arr + from, to - from, sizeof(cube), cube_compare);
    // for (int i=from; i<to - 1; i++) {
    //     printf("compare after sort: %d\n", cube_compare(arr + i, arr + i + 1) );
    // }
}

// Returns the number of lat unique element
int remove_duplicates(cube* arr, int from, int to) {
    int last_unique = from;
    for (int i = from + 1; i<to; i++ ) {
        if (cube_compare(arr + last_unique, arr + i) != 0) {
            arr[++last_unique] = arr[i];
        }
    }
    return last_unique + 1;
}

int main() {
    cube* cache;
    int milion = 1000 * 1000;
    cache = malloc(100 * milion * sizeof(cube));

    cache[0] = empty_cube();
    int level_start = 0;
    int level_end = 1;

    int new_level_end = 1;

    for (int l=1; l<=4; l++) {

        for (int i=0; i<ALL_ROTATION_LEN; i++)
            for (int c = level_start; c < level_end; c++) {
                cache[new_level_end] = all_rotations[i](cache + c);
                new_level_end++;
            }
        level_start = level_end;
        sort_cubes(cache, level_start, new_level_end);

        printf("after %d new_level_end = %d. And it was reduced to ", l, (new_level_end - level_start));
        level_end = remove_duplicates(cache, level_start, new_level_end);
        printf("%d\n", level_end - level_start);

        for (int c=level_start; c< level_end; c++) {
            //printf("L%d ", l);
            //pp3(cache+c);
            //link(cache + c, "kuba");
        }

        // printf("Level %d has %d items\n", l, level_end- level_start );
    }

    cube rr = empty_cube();
    rr = R_1(&rr);
    rr = R_1(&rr);

    cube r2 = empty_cube();
    r2 = R_2(&r2);

    printf("compare = %d\n", cube_compare(&rr, &r2));
}