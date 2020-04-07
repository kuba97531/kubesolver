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
cube x_1(cube *other);
cube x_2(cube *other);
cube x_3(cube *other);
cube y_1(cube *other);
cube y_2(cube *other);
cube y_3(cube *other);
cube z_1(cube *other);
cube z_2(cube *other);
cube z_3(cube *other);
cube M_1(cube *other);
cube M_2(cube *other);
cube M_3(cube *other);
cube E_1(cube *other);
cube E_2(cube *other);
cube E_3(cube *other);
cube S_1(cube *other);
cube S_2(cube *other);
cube S_3(cube *other);
cube r_1(cube *other);
cube r_2(cube *other);
cube r_3(cube *other);
cube l_1(cube *other);
cube l_2(cube *other);
cube l_3(cube *other);
cube u_1(cube *other);
cube u_2(cube *other);
cube u_3(cube *other);
cube d_1(cube *other);
cube d_2(cube *other);
cube d_3(cube *other);
cube f_1(cube *other);
cube f_2(cube *other);
cube f_3(cube *other);
cube b_1(cube *other);
cube b_2(cube *other);
cube b_3(cube *other);
#define ALL_ROTATION_LEN 54

extern t_rotation all_rotations[];
extern char* all_rotations_s[];
extern const char rotation_families[];
extern int edges_by_name_indexes[12][2];
extern char* edges_by_names[12][2];
extern int corners_by_name_indexes[8][3];
extern char* corners_by_names[8][6];

#endif
