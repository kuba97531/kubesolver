const int ALL_ROTATION_LEN = 24;

cube R_1(cube *other) { 
    cube result = *other;
    result.edges[1] = other->edges[5];
    result.edges[5] = other->edges[9];
    result.edges[9] = other->edges[19];
    result.edges[12] = other->edges[15];
    result.edges[13] = other->edges[12];
    result.edges[14] = other->edges[13];
    result.edges[15] = other->edges[14];
    result.edges[19] = other->edges[1];
    result.corners[1] = other->corners[5];
    result.corners[3] = other->corners[7];
    result.corners[5] = other->corners[9];
    result.corners[7] = other->corners[11];
    result.corners[9] = other->corners[18];
    result.corners[11] = other->corners[16];
    result.corners[12] = other->corners[14];
    result.corners[13] = other->corners[12];
    result.corners[14] = other->corners[15];
    result.corners[15] = other->corners[13];
    result.corners[16] = other->corners[3];
    result.corners[18] = other->corners[1];
    return result;
}

cube R_2(cube *other) { 
    cube result = *other;
    result.edges[1] = other->edges[9];
    result.edges[5] = other->edges[19];
    result.edges[9] = other->edges[1];
    result.edges[12] = other->edges[14];
    result.edges[13] = other->edges[15];
    result.edges[14] = other->edges[12];
    result.edges[15] = other->edges[13];
    result.edges[19] = other->edges[5];
    result.corners[1] = other->corners[9];
    result.corners[3] = other->corners[11];
    result.corners[5] = other->corners[18];
    result.corners[7] = other->corners[16];
    result.corners[9] = other->corners[1];
    result.corners[11] = other->corners[3];
    result.corners[12] = other->corners[15];
    result.corners[13] = other->corners[14];
    result.corners[14] = other->corners[13];
    result.corners[15] = other->corners[12];
    result.corners[16] = other->corners[7];
    result.corners[18] = other->corners[5];
    return result;
}

cube R_3(cube *other) { 
    cube result = *other;
    result.edges[1] = other->edges[19];
    result.edges[5] = other->edges[1];
    result.edges[9] = other->edges[5];
    result.edges[12] = other->edges[13];
    result.edges[13] = other->edges[14];
    result.edges[14] = other->edges[15];
    result.edges[15] = other->edges[12];
    result.edges[19] = other->edges[9];
    result.corners[1] = other->corners[18];
    result.corners[3] = other->corners[16];
    result.corners[5] = other->corners[1];
    result.corners[7] = other->corners[3];
    result.corners[9] = other->corners[5];
    result.corners[11] = other->corners[7];
    result.corners[12] = other->corners[13];
    result.corners[13] = other->corners[15];
    result.corners[14] = other->corners[12];
    result.corners[15] = other->corners[14];
    result.corners[16] = other->corners[11];
    result.corners[18] = other->corners[9];
    return result;
}

cube U_1(cube *other) { 
    cube result = *other;
    result.edges[0] = other->edges[3];
    result.edges[1] = other->edges[0];
    result.edges[2] = other->edges[1];
    result.edges[3] = other->edges[2];
    result.edges[4] = other->edges[12];
    result.edges[12] = other->edges[16];
    result.edges[16] = other->edges[20];
    result.edges[20] = other->edges[4];
    result.corners[0] = other->corners[2];
    result.corners[1] = other->corners[0];
    result.corners[2] = other->corners[3];
    result.corners[3] = other->corners[1];
    result.corners[4] = other->corners[12];
    result.corners[5] = other->corners[13];
    result.corners[12] = other->corners[16];
    result.corners[13] = other->corners[17];
    result.corners[16] = other->corners[20];
    result.corners[17] = other->corners[21];
    result.corners[20] = other->corners[4];
    result.corners[21] = other->corners[5];
    return result;
}

cube U_2(cube *other) { 
    cube result = *other;
    result.edges[0] = other->edges[2];
    result.edges[1] = other->edges[3];
    result.edges[2] = other->edges[0];
    result.edges[3] = other->edges[1];
    result.edges[4] = other->edges[16];
    result.edges[12] = other->edges[20];
    result.edges[16] = other->edges[4];
    result.edges[20] = other->edges[12];
    result.corners[0] = other->corners[3];
    result.corners[1] = other->corners[2];
    result.corners[2] = other->corners[1];
    result.corners[3] = other->corners[0];
    result.corners[4] = other->corners[16];
    result.corners[5] = other->corners[17];
    result.corners[12] = other->corners[20];
    result.corners[13] = other->corners[21];
    result.corners[16] = other->corners[4];
    result.corners[17] = other->corners[5];
    result.corners[20] = other->corners[12];
    result.corners[21] = other->corners[13];
    return result;
}

cube U_3(cube *other) { 
    cube result = *other;
    result.edges[0] = other->edges[1];
    result.edges[1] = other->edges[2];
    result.edges[2] = other->edges[3];
    result.edges[3] = other->edges[0];
    result.edges[4] = other->edges[20];
    result.edges[12] = other->edges[4];
    result.edges[16] = other->edges[12];
    result.edges[20] = other->edges[16];
    result.corners[0] = other->corners[1];
    result.corners[1] = other->corners[3];
    result.corners[2] = other->corners[0];
    result.corners[3] = other->corners[2];
    result.corners[4] = other->corners[20];
    result.corners[5] = other->corners[21];
    result.corners[12] = other->corners[4];
    result.corners[13] = other->corners[5];
    result.corners[16] = other->corners[12];
    result.corners[17] = other->corners[13];
    result.corners[20] = other->corners[16];
    result.corners[21] = other->corners[17];
    return result;
}

cube F_1(cube *other) { 
    cube result = *other;
    result.edges[2] = other->edges[21];
    result.edges[4] = other->edges[7];
    result.edges[5] = other->edges[4];
    result.edges[6] = other->edges[5];
    result.edges[7] = other->edges[6];
    result.edges[8] = other->edges[15];
    result.edges[15] = other->edges[2];
    result.edges[21] = other->edges[8];
    result.corners[2] = other->corners[23];
    result.corners[3] = other->corners[21];
    result.corners[4] = other->corners[6];
    result.corners[5] = other->corners[4];
    result.corners[6] = other->corners[7];
    result.corners[7] = other->corners[5];
    result.corners[8] = other->corners[14];
    result.corners[9] = other->corners[12];
    result.corners[12] = other->corners[2];
    result.corners[14] = other->corners[3];
    result.corners[21] = other->corners[8];
    result.corners[23] = other->corners[9];
    return result;
}

cube F_2(cube *other) { 
    cube result = *other;
    result.edges[2] = other->edges[8];
    result.edges[4] = other->edges[6];
    result.edges[5] = other->edges[7];
    result.edges[6] = other->edges[4];
    result.edges[7] = other->edges[5];
    result.edges[8] = other->edges[2];
    result.edges[15] = other->edges[21];
    result.edges[21] = other->edges[15];
    result.corners[2] = other->corners[9];
    result.corners[3] = other->corners[8];
    result.corners[4] = other->corners[7];
    result.corners[5] = other->corners[6];
    result.corners[6] = other->corners[5];
    result.corners[7] = other->corners[4];
    result.corners[8] = other->corners[3];
    result.corners[9] = other->corners[2];
    result.corners[12] = other->corners[23];
    result.corners[14] = other->corners[21];
    result.corners[21] = other->corners[14];
    result.corners[23] = other->corners[12];
    return result;
}

cube F_3(cube *other) { 
    cube result = *other;
    result.edges[2] = other->edges[15];
    result.edges[4] = other->edges[5];
    result.edges[5] = other->edges[6];
    result.edges[6] = other->edges[7];
    result.edges[7] = other->edges[4];
    result.edges[8] = other->edges[21];
    result.edges[15] = other->edges[8];
    result.edges[21] = other->edges[2];
    result.corners[2] = other->corners[12];
    result.corners[3] = other->corners[14];
    result.corners[4] = other->corners[5];
    result.corners[5] = other->corners[7];
    result.corners[6] = other->corners[4];
    result.corners[7] = other->corners[6];
    result.corners[8] = other->corners[21];
    result.corners[9] = other->corners[23];
    result.corners[12] = other->corners[9];
    result.corners[14] = other->corners[8];
    result.corners[21] = other->corners[3];
    result.corners[23] = other->corners[2];
    return result;
}

cube L_1(cube *other) { 
    cube result = *other;
    result.edges[3] = other->edges[17];
    result.edges[7] = other->edges[3];
    result.edges[11] = other->edges[7];
    result.edges[17] = other->edges[11];
    result.edges[20] = other->edges[23];
    result.edges[21] = other->edges[20];
    result.edges[22] = other->edges[21];
    result.edges[23] = other->edges[22];
    result.corners[0] = other->corners[19];
    result.corners[2] = other->corners[17];
    result.corners[4] = other->corners[0];
    result.corners[6] = other->corners[2];
    result.corners[8] = other->corners[4];
    result.corners[10] = other->corners[6];
    result.corners[17] = other->corners[10];
    result.corners[19] = other->corners[8];
    result.corners[20] = other->corners[22];
    result.corners[21] = other->corners[20];
    result.corners[22] = other->corners[23];
    result.corners[23] = other->corners[21];
    return result;
}

cube L_2(cube *other) { 
    cube result = *other;
    result.edges[3] = other->edges[11];
    result.edges[7] = other->edges[17];
    result.edges[11] = other->edges[3];
    result.edges[17] = other->edges[7];
    result.edges[20] = other->edges[22];
    result.edges[21] = other->edges[23];
    result.edges[22] = other->edges[20];
    result.edges[23] = other->edges[21];
    result.corners[0] = other->corners[8];
    result.corners[2] = other->corners[10];
    result.corners[4] = other->corners[19];
    result.corners[6] = other->corners[17];
    result.corners[8] = other->corners[0];
    result.corners[10] = other->corners[2];
    result.corners[17] = other->corners[6];
    result.corners[19] = other->corners[4];
    result.corners[20] = other->corners[23];
    result.corners[21] = other->corners[22];
    result.corners[22] = other->corners[21];
    result.corners[23] = other->corners[20];
    return result;
}

cube L_3(cube *other) { 
    cube result = *other;
    result.edges[3] = other->edges[7];
    result.edges[7] = other->edges[11];
    result.edges[11] = other->edges[17];
    result.edges[17] = other->edges[3];
    result.edges[20] = other->edges[21];
    result.edges[21] = other->edges[22];
    result.edges[22] = other->edges[23];
    result.edges[23] = other->edges[20];
    result.corners[0] = other->corners[4];
    result.corners[2] = other->corners[6];
    result.corners[4] = other->corners[8];
    result.corners[6] = other->corners[10];
    result.corners[8] = other->corners[19];
    result.corners[10] = other->corners[17];
    result.corners[17] = other->corners[2];
    result.corners[19] = other->corners[0];
    result.corners[20] = other->corners[21];
    result.corners[21] = other->corners[23];
    result.corners[22] = other->corners[20];
    result.corners[23] = other->corners[22];
    return result;
}

cube D_1(cube *other) { 
    cube result = *other;
    result.edges[6] = other->edges[22];
    result.edges[8] = other->edges[11];
    result.edges[9] = other->edges[8];
    result.edges[10] = other->edges[9];
    result.edges[11] = other->edges[10];
    result.edges[14] = other->edges[6];
    result.edges[18] = other->edges[14];
    result.edges[22] = other->edges[18];
    result.corners[6] = other->corners[22];
    result.corners[7] = other->corners[23];
    result.corners[8] = other->corners[10];
    result.corners[9] = other->corners[8];
    result.corners[10] = other->corners[11];
    result.corners[11] = other->corners[9];
    result.corners[14] = other->corners[6];
    result.corners[15] = other->corners[7];
    result.corners[18] = other->corners[14];
    result.corners[19] = other->corners[15];
    result.corners[22] = other->corners[18];
    result.corners[23] = other->corners[19];
    return result;
}

cube D_2(cube *other) { 
    cube result = *other;
    result.edges[6] = other->edges[18];
    result.edges[8] = other->edges[10];
    result.edges[9] = other->edges[11];
    result.edges[10] = other->edges[8];
    result.edges[11] = other->edges[9];
    result.edges[14] = other->edges[22];
    result.edges[18] = other->edges[6];
    result.edges[22] = other->edges[14];
    result.corners[6] = other->corners[18];
    result.corners[7] = other->corners[19];
    result.corners[8] = other->corners[11];
    result.corners[9] = other->corners[10];
    result.corners[10] = other->corners[9];
    result.corners[11] = other->corners[8];
    result.corners[14] = other->corners[22];
    result.corners[15] = other->corners[23];
    result.corners[18] = other->corners[6];
    result.corners[19] = other->corners[7];
    result.corners[22] = other->corners[14];
    result.corners[23] = other->corners[15];
    return result;
}

cube D_3(cube *other) { 
    cube result = *other;
    result.edges[6] = other->edges[14];
    result.edges[8] = other->edges[9];
    result.edges[9] = other->edges[10];
    result.edges[10] = other->edges[11];
    result.edges[11] = other->edges[8];
    result.edges[14] = other->edges[18];
    result.edges[18] = other->edges[22];
    result.edges[22] = other->edges[6];
    result.corners[6] = other->corners[14];
    result.corners[7] = other->corners[15];
    result.corners[8] = other->corners[9];
    result.corners[9] = other->corners[11];
    result.corners[10] = other->corners[8];
    result.corners[11] = other->corners[10];
    result.corners[14] = other->corners[18];
    result.corners[15] = other->corners[19];
    result.corners[18] = other->corners[22];
    result.corners[19] = other->corners[23];
    result.corners[22] = other->corners[6];
    result.corners[23] = other->corners[7];
    return result;
}

cube B_1(cube *other) { 
    cube result = *other;
    result.edges[0] = other->edges[13];
    result.edges[10] = other->edges[23];
    result.edges[13] = other->edges[10];
    result.edges[16] = other->edges[19];
    result.edges[17] = other->edges[16];
    result.edges[18] = other->edges[17];
    result.edges[19] = other->edges[18];
    result.edges[23] = other->edges[0];
    result.corners[0] = other->corners[13];
    result.corners[1] = other->corners[15];
    result.corners[10] = other->corners[20];
    result.corners[11] = other->corners[22];
    result.corners[13] = other->corners[11];
    result.corners[15] = other->corners[10];
    result.corners[16] = other->corners[18];
    result.corners[17] = other->corners[16];
    result.corners[18] = other->corners[19];
    result.corners[19] = other->corners[17];
    result.corners[20] = other->corners[1];
    result.corners[22] = other->corners[0];
    return result;
}

cube B_2(cube *other) { 
    cube result = *other;
    result.edges[0] = other->edges[10];
    result.edges[10] = other->edges[0];
    result.edges[13] = other->edges[23];
    result.edges[16] = other->edges[18];
    result.edges[17] = other->edges[19];
    result.edges[18] = other->edges[16];
    result.edges[19] = other->edges[17];
    result.edges[23] = other->edges[13];
    result.corners[0] = other->corners[11];
    result.corners[1] = other->corners[10];
    result.corners[10] = other->corners[1];
    result.corners[11] = other->corners[0];
    result.corners[13] = other->corners[22];
    result.corners[15] = other->corners[20];
    result.corners[16] = other->corners[19];
    result.corners[17] = other->corners[18];
    result.corners[18] = other->corners[17];
    result.corners[19] = other->corners[16];
    result.corners[20] = other->corners[15];
    result.corners[22] = other->corners[13];
    return result;
}

cube B_3(cube *other) { 
    cube result = *other;
    result.edges[0] = other->edges[23];
    result.edges[10] = other->edges[13];
    result.edges[13] = other->edges[0];
    result.edges[16] = other->edges[17];
    result.edges[17] = other->edges[18];
    result.edges[18] = other->edges[19];
    result.edges[19] = other->edges[16];
    result.edges[23] = other->edges[10];
    result.corners[0] = other->corners[22];
    result.corners[1] = other->corners[20];
    result.corners[10] = other->corners[15];
    result.corners[11] = other->corners[13];
    result.corners[13] = other->corners[0];
    result.corners[15] = other->corners[1];
    result.corners[16] = other->corners[17];
    result.corners[17] = other->corners[19];
    result.corners[18] = other->corners[16];
    result.corners[19] = other->corners[18];
    result.corners[20] = other->corners[10];
    result.corners[22] = other->corners[11];
    return result;
}

cube r_1(cube *other) { 
    cube result = *other;
    result.edges[0] = other->edges[4];
    result.edges[2] = other->edges[6];
    result.edges[4] = other->edges[8];
    result.edges[6] = other->edges[10];
    result.edges[8] = other->edges[18];
    result.edges[10] = other->edges[16];
    result.edges[16] = other->edges[2];
    result.edges[18] = other->edges[0];
    return result;
}

cube r_2(cube *other) { 
    cube result = *other;
    result.edges[0] = other->edges[8];
    result.edges[2] = other->edges[10];
    result.edges[4] = other->edges[18];
    result.edges[6] = other->edges[16];
    result.edges[8] = other->edges[0];
    result.edges[10] = other->edges[2];
    result.edges[16] = other->edges[6];
    result.edges[18] = other->edges[4];
    return result;
}

cube r_3(cube *other) { 
    cube result = *other;
    result.edges[0] = other->edges[18];
    result.edges[2] = other->edges[16];
    result.edges[4] = other->edges[0];
    result.edges[6] = other->edges[2];
    result.edges[8] = other->edges[4];
    result.edges[10] = other->edges[6];
    result.edges[16] = other->edges[10];
    result.edges[18] = other->edges[8];
    return result;
}

cube u_1(cube *other) { 
    cube result = *other;
    result.edges[1] = other->edges[14];
    result.edges[3] = other->edges[12];
    result.edges[9] = other->edges[22];
    result.edges[11] = other->edges[20];
    result.edges[12] = other->edges[9];
    result.edges[14] = other->edges[11];
    result.edges[20] = other->edges[1];
    result.edges[22] = other->edges[3];
    return result;
}

cube u_2(cube *other) { 
    cube result = *other;
    result.edges[1] = other->edges[11];
    result.edges[3] = other->edges[9];
    result.edges[9] = other->edges[3];
    result.edges[11] = other->edges[1];
    result.edges[12] = other->edges[22];
    result.edges[14] = other->edges[20];
    result.edges[20] = other->edges[14];
    result.edges[22] = other->edges[12];
    return result;
}

cube u_3(cube *other) { 
    cube result = *other;
    result.edges[1] = other->edges[20];
    result.edges[3] = other->edges[22];
    result.edges[9] = other->edges[12];
    result.edges[11] = other->edges[14];
    result.edges[12] = other->edges[3];
    result.edges[14] = other->edges[1];
    result.edges[20] = other->edges[11];
    result.edges[22] = other->edges[9];
    return result;
}

t_rotation all_rotations[] = {
R_1,
R_2,
R_3,
U_1,
U_2,
U_3,
F_1,
F_2,
F_3,
L_1,
L_2,
L_3,
D_1,
D_2,
D_3,
B_1,
B_2,
B_3,
r_1,
r_2,
r_3,
u_1,
u_2,
u_3
};
char* all_rotations_s[] = {
"R",
"R2",
"R'",
"U",
"U2",
"U'",
"F",
"F2",
"F'",
"L",
"L2",
"L'",
"D",
"D2",
"D'",
"B",
"B2",
"B'",
"r",
"r2",
"r'",
"u",
"u2",
"u'"
};
