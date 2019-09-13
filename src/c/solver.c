#include<stdio.h>
#include "cube3.c"
#include "cube3r.c"



int main() {
    cube x = empty_cube();

    cube r1 = R_1(&x);
    cube r2 = R_2(&x);
    cube r3 = R_3(&x);

    cube f1 = F_1(&x);
    cube f2 = F_2(&x);
    cube f3 = F_3(&x);

    cube u1 = U_1(&x);
    cube u2 = U_2(&x);
    cube u3 = U_3(&x);


    cube color =x;
color = D_1(&color);
    color = F_1(&color);
    color = R_2(&color);
    color = D_3(&color);
    color = R_2(&color);
    color = D_3(&color);
    color = L_2(&color);
    color = D_2(&color);
    color = U_1(&color);
    color = L_2(&color);
    color = B_2(&color);
    color = F_2(&color);
    color = U_2(&color);
    color = D_2(&color);
    color = L_3(&color);
    color = U_1(&color);
    color = B_1(&color);
    color = L_2(&color);
    color = B_3(&color);
    color = F_3(&color);
    color = R_3(&color);
    color = U_3(&color);
    color = R_1(&color);
    color = F_1(&color);
    color = D_1(&color);
    color = L_1(&color);
    color = B_1(&color);
    color = U_1(&color);
    color = R_3(&color);
    color = F_3(&color);
    color = D_3(&color);
    color = L_3(&color);
    color = B_3(&color);
    color = U_3(&color);


    link(&color, "color F3");


}