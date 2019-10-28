#include "cube3.h"
#ifndef CUBE3_R
#define CUBE3_R
cube R_1(cube *other); 
cube R_2(cube *other); 
cube R_3(cube *other); 
cube U_1(cube *other); 
cube U_2(cube *other); 
cube U_3(cube *other); 
cube F_1(cube *other); 
cube F_2(cube *other); 
cube F_3(cube *other); 
cube L_1(cube *other); 
cube L_2(cube *other); 
cube L_3(cube *other); 
cube D_1(cube *other); 
cube D_2(cube *other); 
cube D_3(cube *other); 
cube B_1(cube *other); 
cube B_2(cube *other); 
cube B_3(cube *other); 
cube x(cube *other); 
cube xx(cube *other); 
cube xxx(cube *other); 
cube y(cube *other); 
cube z(cube *other); 
cube zz(cube *other); 
#define ALL_ROTATION_LEN 24

extern t_rotation all_rotations[];
extern char* all_rotations_s[];

#endif
