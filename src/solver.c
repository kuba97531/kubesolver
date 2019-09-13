#include<stdio.h>
#include "cube3.c"



int main() {
    cube x = empty_cube();
    cube y = R_1(&x);

    printf("x %d y %d\n", x.edges[1], y.edges[1]);
    printf("hello\n");
    link(&x, "before");
    link(&y, "after");
}