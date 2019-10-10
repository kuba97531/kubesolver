#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "cube3.c"
#include "cube3r.c"

int main() {
    cube cc = empty_cube();
    char buffer[100];
    while (scanf("%s", buffer) != EOF) {
        for (int i=0; i<ALL_ROTATION_LEN ; i++) {
            if (!strcmp(buffer,all_rotations_s[i])) {
                printf("<p>applying %s<p>\n", all_rotations_s[i]);
                cc = all_rotations[i](&cc);
            }
        }
        if (!strcmp(buffer,"print")) {
                link(&cc, "print");
                printf("\n");
            }
        if (!strcmp(buffer,"clear")) {
            cc = empty_cube();
            }

    }
}