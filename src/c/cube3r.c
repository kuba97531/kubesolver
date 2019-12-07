#include "cube3r.h"
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

cube x_1(cube *other) {
    cube result;
    int color_swap[7] = { 4, 0, 1, 3, 2, 5, 6 };
    result.edges[0] = color_swap[other->edges[4]];
    result.edges[1] = color_swap[other->edges[5]];
    result.edges[2] = color_swap[other->edges[6]];
    result.edges[3] = color_swap[other->edges[7]];
    result.edges[4] = color_swap[other->edges[8]];
    result.edges[5] = color_swap[other->edges[9]];
    result.edges[6] = color_swap[other->edges[10]];
    result.edges[7] = color_swap[other->edges[11]];
    result.edges[8] = color_swap[other->edges[18]];
    result.edges[9] = color_swap[other->edges[19]];
    result.edges[10] = color_swap[other->edges[16]];
    result.edges[11] = color_swap[other->edges[17]];
    result.edges[12] = color_swap[other->edges[15]];
    result.edges[13] = color_swap[other->edges[12]];
    result.edges[14] = color_swap[other->edges[13]];
    result.edges[15] = color_swap[other->edges[14]];
    result.edges[16] = color_swap[other->edges[2]];
    result.edges[17] = color_swap[other->edges[3]];
    result.edges[18] = color_swap[other->edges[0]];
    result.edges[19] = color_swap[other->edges[1]];
    result.edges[20] = color_swap[other->edges[21]];
    result.edges[21] = color_swap[other->edges[22]];
    result.edges[22] = color_swap[other->edges[23]];
    result.edges[23] = color_swap[other->edges[20]];
    result.corners[0] = color_swap[other->corners[4]];
    result.corners[1] = color_swap[other->corners[5]];
    result.corners[2] = color_swap[other->corners[6]];
    result.corners[3] = color_swap[other->corners[7]];
    result.corners[4] = color_swap[other->corners[8]];
    result.corners[5] = color_swap[other->corners[9]];
    result.corners[6] = color_swap[other->corners[10]];
    result.corners[7] = color_swap[other->corners[11]];
    result.corners[8] = color_swap[other->corners[19]];
    result.corners[9] = color_swap[other->corners[18]];
    result.corners[10] = color_swap[other->corners[17]];
    result.corners[11] = color_swap[other->corners[16]];
    result.corners[12] = color_swap[other->corners[14]];
    result.corners[13] = color_swap[other->corners[12]];
    result.corners[14] = color_swap[other->corners[15]];
    result.corners[15] = color_swap[other->corners[13]];
    result.corners[16] = color_swap[other->corners[3]];
    result.corners[17] = color_swap[other->corners[2]];
    result.corners[18] = color_swap[other->corners[1]];
    result.corners[19] = color_swap[other->corners[0]];
    result.corners[20] = color_swap[other->corners[21]];
    result.corners[21] = color_swap[other->corners[23]];
    result.corners[22] = color_swap[other->corners[20]];
    result.corners[23] = color_swap[other->corners[22]];
    return result;
}

cube x_2(cube *other) {
    cube result;
    int color_swap[7] = { 2, 4, 0, 3, 1, 5, 6 };
    result.edges[0] = color_swap[other->edges[8]];
    result.edges[1] = color_swap[other->edges[9]];
    result.edges[2] = color_swap[other->edges[10]];
    result.edges[3] = color_swap[other->edges[11]];
    result.edges[4] = color_swap[other->edges[18]];
    result.edges[5] = color_swap[other->edges[19]];
    result.edges[6] = color_swap[other->edges[16]];
    result.edges[7] = color_swap[other->edges[17]];
    result.edges[8] = color_swap[other->edges[0]];
    result.edges[9] = color_swap[other->edges[1]];
    result.edges[10] = color_swap[other->edges[2]];
    result.edges[11] = color_swap[other->edges[3]];
    result.edges[12] = color_swap[other->edges[14]];
    result.edges[13] = color_swap[other->edges[15]];
    result.edges[14] = color_swap[other->edges[12]];
    result.edges[15] = color_swap[other->edges[13]];
    result.edges[16] = color_swap[other->edges[6]];
    result.edges[17] = color_swap[other->edges[7]];
    result.edges[18] = color_swap[other->edges[4]];
    result.edges[19] = color_swap[other->edges[5]];
    result.edges[20] = color_swap[other->edges[22]];
    result.edges[21] = color_swap[other->edges[23]];
    result.edges[22] = color_swap[other->edges[20]];
    result.edges[23] = color_swap[other->edges[21]];
    result.corners[0] = color_swap[other->corners[8]];
    result.corners[1] = color_swap[other->corners[9]];
    result.corners[2] = color_swap[other->corners[10]];
    result.corners[3] = color_swap[other->corners[11]];
    result.corners[4] = color_swap[other->corners[19]];
    result.corners[5] = color_swap[other->corners[18]];
    result.corners[6] = color_swap[other->corners[17]];
    result.corners[7] = color_swap[other->corners[16]];
    result.corners[8] = color_swap[other->corners[0]];
    result.corners[9] = color_swap[other->corners[1]];
    result.corners[10] = color_swap[other->corners[2]];
    result.corners[11] = color_swap[other->corners[3]];
    result.corners[12] = color_swap[other->corners[15]];
    result.corners[13] = color_swap[other->corners[14]];
    result.corners[14] = color_swap[other->corners[13]];
    result.corners[15] = color_swap[other->corners[12]];
    result.corners[16] = color_swap[other->corners[7]];
    result.corners[17] = color_swap[other->corners[6]];
    result.corners[18] = color_swap[other->corners[5]];
    result.corners[19] = color_swap[other->corners[4]];
    result.corners[20] = color_swap[other->corners[23]];
    result.corners[21] = color_swap[other->corners[22]];
    result.corners[22] = color_swap[other->corners[21]];
    result.corners[23] = color_swap[other->corners[20]];
    return result;
}

cube x_3(cube *other) {
    cube result;
    int color_swap[7] = { 1, 2, 4, 3, 0, 5, 6 };
    result.edges[0] = color_swap[other->edges[18]];
    result.edges[1] = color_swap[other->edges[19]];
    result.edges[2] = color_swap[other->edges[16]];
    result.edges[3] = color_swap[other->edges[17]];
    result.edges[4] = color_swap[other->edges[0]];
    result.edges[5] = color_swap[other->edges[1]];
    result.edges[6] = color_swap[other->edges[2]];
    result.edges[7] = color_swap[other->edges[3]];
    result.edges[8] = color_swap[other->edges[4]];
    result.edges[9] = color_swap[other->edges[5]];
    result.edges[10] = color_swap[other->edges[6]];
    result.edges[11] = color_swap[other->edges[7]];
    result.edges[12] = color_swap[other->edges[13]];
    result.edges[13] = color_swap[other->edges[14]];
    result.edges[14] = color_swap[other->edges[15]];
    result.edges[15] = color_swap[other->edges[12]];
    result.edges[16] = color_swap[other->edges[10]];
    result.edges[17] = color_swap[other->edges[11]];
    result.edges[18] = color_swap[other->edges[8]];
    result.edges[19] = color_swap[other->edges[9]];
    result.edges[20] = color_swap[other->edges[23]];
    result.edges[21] = color_swap[other->edges[20]];
    result.edges[22] = color_swap[other->edges[21]];
    result.edges[23] = color_swap[other->edges[22]];
    result.corners[0] = color_swap[other->corners[19]];
    result.corners[1] = color_swap[other->corners[18]];
    result.corners[2] = color_swap[other->corners[17]];
    result.corners[3] = color_swap[other->corners[16]];
    result.corners[4] = color_swap[other->corners[0]];
    result.corners[5] = color_swap[other->corners[1]];
    result.corners[6] = color_swap[other->corners[2]];
    result.corners[7] = color_swap[other->corners[3]];
    result.corners[8] = color_swap[other->corners[4]];
    result.corners[9] = color_swap[other->corners[5]];
    result.corners[10] = color_swap[other->corners[6]];
    result.corners[11] = color_swap[other->corners[7]];
    result.corners[12] = color_swap[other->corners[13]];
    result.corners[13] = color_swap[other->corners[15]];
    result.corners[14] = color_swap[other->corners[12]];
    result.corners[15] = color_swap[other->corners[14]];
    result.corners[16] = color_swap[other->corners[11]];
    result.corners[17] = color_swap[other->corners[10]];
    result.corners[18] = color_swap[other->corners[9]];
    result.corners[19] = color_swap[other->corners[8]];
    result.corners[20] = color_swap[other->corners[22]];
    result.corners[21] = color_swap[other->corners[20]];
    result.corners[22] = color_swap[other->corners[23]];
    result.corners[23] = color_swap[other->corners[21]];
    return result;
}

cube y_1(cube *other) {
    cube result;
    int color_swap[7] = { 0, 5, 2, 1, 3, 4, 6 };
    result.edges[0] = color_swap[other->edges[3]];
    result.edges[1] = color_swap[other->edges[0]];
    result.edges[2] = color_swap[other->edges[1]];
    result.edges[3] = color_swap[other->edges[2]];
    result.edges[4] = color_swap[other->edges[12]];
    result.edges[5] = color_swap[other->edges[13]];
    result.edges[6] = color_swap[other->edges[14]];
    result.edges[7] = color_swap[other->edges[15]];
    result.edges[8] = color_swap[other->edges[9]];
    result.edges[9] = color_swap[other->edges[10]];
    result.edges[10] = color_swap[other->edges[11]];
    result.edges[11] = color_swap[other->edges[8]];
    result.edges[12] = color_swap[other->edges[16]];
    result.edges[13] = color_swap[other->edges[17]];
    result.edges[14] = color_swap[other->edges[18]];
    result.edges[15] = color_swap[other->edges[19]];
    result.edges[16] = color_swap[other->edges[20]];
    result.edges[17] = color_swap[other->edges[21]];
    result.edges[18] = color_swap[other->edges[22]];
    result.edges[19] = color_swap[other->edges[23]];
    result.edges[20] = color_swap[other->edges[4]];
    result.edges[21] = color_swap[other->edges[5]];
    result.edges[22] = color_swap[other->edges[6]];
    result.edges[23] = color_swap[other->edges[7]];
    result.corners[0] = color_swap[other->corners[2]];
    result.corners[1] = color_swap[other->corners[0]];
    result.corners[2] = color_swap[other->corners[3]];
    result.corners[3] = color_swap[other->corners[1]];
    result.corners[4] = color_swap[other->corners[12]];
    result.corners[5] = color_swap[other->corners[13]];
    result.corners[6] = color_swap[other->corners[14]];
    result.corners[7] = color_swap[other->corners[15]];
    result.corners[8] = color_swap[other->corners[9]];
    result.corners[9] = color_swap[other->corners[11]];
    result.corners[10] = color_swap[other->corners[8]];
    result.corners[11] = color_swap[other->corners[10]];
    result.corners[12] = color_swap[other->corners[16]];
    result.corners[13] = color_swap[other->corners[17]];
    result.corners[14] = color_swap[other->corners[18]];
    result.corners[15] = color_swap[other->corners[19]];
    result.corners[16] = color_swap[other->corners[20]];
    result.corners[17] = color_swap[other->corners[21]];
    result.corners[18] = color_swap[other->corners[22]];
    result.corners[19] = color_swap[other->corners[23]];
    result.corners[20] = color_swap[other->corners[4]];
    result.corners[21] = color_swap[other->corners[5]];
    result.corners[22] = color_swap[other->corners[6]];
    result.corners[23] = color_swap[other->corners[7]];
    return result;
}

cube y_2(cube *other) {
    cube result;
    int color_swap[7] = { 0, 4, 2, 5, 1, 3, 6 };
    result.edges[0] = color_swap[other->edges[2]];
    result.edges[1] = color_swap[other->edges[3]];
    result.edges[2] = color_swap[other->edges[0]];
    result.edges[3] = color_swap[other->edges[1]];
    result.edges[4] = color_swap[other->edges[16]];
    result.edges[5] = color_swap[other->edges[17]];
    result.edges[6] = color_swap[other->edges[18]];
    result.edges[7] = color_swap[other->edges[19]];
    result.edges[8] = color_swap[other->edges[10]];
    result.edges[9] = color_swap[other->edges[11]];
    result.edges[10] = color_swap[other->edges[8]];
    result.edges[11] = color_swap[other->edges[9]];
    result.edges[12] = color_swap[other->edges[20]];
    result.edges[13] = color_swap[other->edges[21]];
    result.edges[14] = color_swap[other->edges[22]];
    result.edges[15] = color_swap[other->edges[23]];
    result.edges[16] = color_swap[other->edges[4]];
    result.edges[17] = color_swap[other->edges[5]];
    result.edges[18] = color_swap[other->edges[6]];
    result.edges[19] = color_swap[other->edges[7]];
    result.edges[20] = color_swap[other->edges[12]];
    result.edges[21] = color_swap[other->edges[13]];
    result.edges[22] = color_swap[other->edges[14]];
    result.edges[23] = color_swap[other->edges[15]];
    result.corners[0] = color_swap[other->corners[3]];
    result.corners[1] = color_swap[other->corners[2]];
    result.corners[2] = color_swap[other->corners[1]];
    result.corners[3] = color_swap[other->corners[0]];
    result.corners[4] = color_swap[other->corners[16]];
    result.corners[5] = color_swap[other->corners[17]];
    result.corners[6] = color_swap[other->corners[18]];
    result.corners[7] = color_swap[other->corners[19]];
    result.corners[8] = color_swap[other->corners[11]];
    result.corners[9] = color_swap[other->corners[10]];
    result.corners[10] = color_swap[other->corners[9]];
    result.corners[11] = color_swap[other->corners[8]];
    result.corners[12] = color_swap[other->corners[20]];
    result.corners[13] = color_swap[other->corners[21]];
    result.corners[14] = color_swap[other->corners[22]];
    result.corners[15] = color_swap[other->corners[23]];
    result.corners[16] = color_swap[other->corners[4]];
    result.corners[17] = color_swap[other->corners[5]];
    result.corners[18] = color_swap[other->corners[6]];
    result.corners[19] = color_swap[other->corners[7]];
    result.corners[20] = color_swap[other->corners[12]];
    result.corners[21] = color_swap[other->corners[13]];
    result.corners[22] = color_swap[other->corners[14]];
    result.corners[23] = color_swap[other->corners[15]];
    return result;
}

cube y_3(cube *other) {
    cube result;
    int color_swap[7] = { 0, 3, 2, 4, 5, 1, 6 };
    result.edges[0] = color_swap[other->edges[1]];
    result.edges[1] = color_swap[other->edges[2]];
    result.edges[2] = color_swap[other->edges[3]];
    result.edges[3] = color_swap[other->edges[0]];
    result.edges[4] = color_swap[other->edges[20]];
    result.edges[5] = color_swap[other->edges[21]];
    result.edges[6] = color_swap[other->edges[22]];
    result.edges[7] = color_swap[other->edges[23]];
    result.edges[8] = color_swap[other->edges[11]];
    result.edges[9] = color_swap[other->edges[8]];
    result.edges[10] = color_swap[other->edges[9]];
    result.edges[11] = color_swap[other->edges[10]];
    result.edges[12] = color_swap[other->edges[4]];
    result.edges[13] = color_swap[other->edges[5]];
    result.edges[14] = color_swap[other->edges[6]];
    result.edges[15] = color_swap[other->edges[7]];
    result.edges[16] = color_swap[other->edges[12]];
    result.edges[17] = color_swap[other->edges[13]];
    result.edges[18] = color_swap[other->edges[14]];
    result.edges[19] = color_swap[other->edges[15]];
    result.edges[20] = color_swap[other->edges[16]];
    result.edges[21] = color_swap[other->edges[17]];
    result.edges[22] = color_swap[other->edges[18]];
    result.edges[23] = color_swap[other->edges[19]];
    result.corners[0] = color_swap[other->corners[1]];
    result.corners[1] = color_swap[other->corners[3]];
    result.corners[2] = color_swap[other->corners[0]];
    result.corners[3] = color_swap[other->corners[2]];
    result.corners[4] = color_swap[other->corners[20]];
    result.corners[5] = color_swap[other->corners[21]];
    result.corners[6] = color_swap[other->corners[22]];
    result.corners[7] = color_swap[other->corners[23]];
    result.corners[8] = color_swap[other->corners[10]];
    result.corners[9] = color_swap[other->corners[8]];
    result.corners[10] = color_swap[other->corners[11]];
    result.corners[11] = color_swap[other->corners[9]];
    result.corners[12] = color_swap[other->corners[4]];
    result.corners[13] = color_swap[other->corners[5]];
    result.corners[14] = color_swap[other->corners[6]];
    result.corners[15] = color_swap[other->corners[7]];
    result.corners[16] = color_swap[other->corners[12]];
    result.corners[17] = color_swap[other->corners[13]];
    result.corners[18] = color_swap[other->corners[14]];
    result.corners[19] = color_swap[other->corners[15]];
    result.corners[20] = color_swap[other->corners[16]];
    result.corners[21] = color_swap[other->corners[17]];
    result.corners[22] = color_swap[other->corners[18]];
    result.corners[23] = color_swap[other->corners[19]];
    return result;
}

cube z_1(cube *other) {
    cube result;
    int color_swap[7] = { 3, 1, 5, 2, 4, 0, 6 };
    result.edges[0] = color_swap[other->edges[23]];
    result.edges[1] = color_swap[other->edges[20]];
    result.edges[2] = color_swap[other->edges[21]];
    result.edges[3] = color_swap[other->edges[22]];
    result.edges[4] = color_swap[other->edges[7]];
    result.edges[5] = color_swap[other->edges[4]];
    result.edges[6] = color_swap[other->edges[5]];
    result.edges[7] = color_swap[other->edges[6]];
    result.edges[8] = color_swap[other->edges[15]];
    result.edges[9] = color_swap[other->edges[12]];
    result.edges[10] = color_swap[other->edges[13]];
    result.edges[11] = color_swap[other->edges[14]];
    result.edges[12] = color_swap[other->edges[3]];
    result.edges[13] = color_swap[other->edges[0]];
    result.edges[14] = color_swap[other->edges[1]];
    result.edges[15] = color_swap[other->edges[2]];
    result.edges[16] = color_swap[other->edges[17]];
    result.edges[17] = color_swap[other->edges[18]];
    result.edges[18] = color_swap[other->edges[19]];
    result.edges[19] = color_swap[other->edges[16]];
    result.edges[20] = color_swap[other->edges[11]];
    result.edges[21] = color_swap[other->edges[8]];
    result.edges[22] = color_swap[other->edges[9]];
    result.edges[23] = color_swap[other->edges[10]];
    result.corners[0] = color_swap[other->corners[22]];
    result.corners[1] = color_swap[other->corners[20]];
    result.corners[2] = color_swap[other->corners[23]];
    result.corners[3] = color_swap[other->corners[21]];
    result.corners[4] = color_swap[other->corners[6]];
    result.corners[5] = color_swap[other->corners[4]];
    result.corners[6] = color_swap[other->corners[7]];
    result.corners[7] = color_swap[other->corners[5]];
    result.corners[8] = color_swap[other->corners[14]];
    result.corners[9] = color_swap[other->corners[12]];
    result.corners[10] = color_swap[other->corners[15]];
    result.corners[11] = color_swap[other->corners[13]];
    result.corners[12] = color_swap[other->corners[2]];
    result.corners[13] = color_swap[other->corners[0]];
    result.corners[14] = color_swap[other->corners[3]];
    result.corners[15] = color_swap[other->corners[1]];
    result.corners[16] = color_swap[other->corners[17]];
    result.corners[17] = color_swap[other->corners[19]];
    result.corners[18] = color_swap[other->corners[16]];
    result.corners[19] = color_swap[other->corners[18]];
    result.corners[20] = color_swap[other->corners[10]];
    result.corners[21] = color_swap[other->corners[8]];
    result.corners[22] = color_swap[other->corners[11]];
    result.corners[23] = color_swap[other->corners[9]];
    return result;
}

cube z_2(cube *other) {
    cube result;
    int color_swap[7] = { 2, 1, 0, 5, 4, 3, 6 };
    result.edges[0] = color_swap[other->edges[10]];
    result.edges[1] = color_swap[other->edges[11]];
    result.edges[2] = color_swap[other->edges[8]];
    result.edges[3] = color_swap[other->edges[9]];
    result.edges[4] = color_swap[other->edges[6]];
    result.edges[5] = color_swap[other->edges[7]];
    result.edges[6] = color_swap[other->edges[4]];
    result.edges[7] = color_swap[other->edges[5]];
    result.edges[8] = color_swap[other->edges[2]];
    result.edges[9] = color_swap[other->edges[3]];
    result.edges[10] = color_swap[other->edges[0]];
    result.edges[11] = color_swap[other->edges[1]];
    result.edges[12] = color_swap[other->edges[22]];
    result.edges[13] = color_swap[other->edges[23]];
    result.edges[14] = color_swap[other->edges[20]];
    result.edges[15] = color_swap[other->edges[21]];
    result.edges[16] = color_swap[other->edges[18]];
    result.edges[17] = color_swap[other->edges[19]];
    result.edges[18] = color_swap[other->edges[16]];
    result.edges[19] = color_swap[other->edges[17]];
    result.edges[20] = color_swap[other->edges[14]];
    result.edges[21] = color_swap[other->edges[15]];
    result.edges[22] = color_swap[other->edges[12]];
    result.edges[23] = color_swap[other->edges[13]];
    result.corners[0] = color_swap[other->corners[11]];
    result.corners[1] = color_swap[other->corners[10]];
    result.corners[2] = color_swap[other->corners[9]];
    result.corners[3] = color_swap[other->corners[8]];
    result.corners[4] = color_swap[other->corners[7]];
    result.corners[5] = color_swap[other->corners[6]];
    result.corners[6] = color_swap[other->corners[5]];
    result.corners[7] = color_swap[other->corners[4]];
    result.corners[8] = color_swap[other->corners[3]];
    result.corners[9] = color_swap[other->corners[2]];
    result.corners[10] = color_swap[other->corners[1]];
    result.corners[11] = color_swap[other->corners[0]];
    result.corners[12] = color_swap[other->corners[23]];
    result.corners[13] = color_swap[other->corners[22]];
    result.corners[14] = color_swap[other->corners[21]];
    result.corners[15] = color_swap[other->corners[20]];
    result.corners[16] = color_swap[other->corners[19]];
    result.corners[17] = color_swap[other->corners[18]];
    result.corners[18] = color_swap[other->corners[17]];
    result.corners[19] = color_swap[other->corners[16]];
    result.corners[20] = color_swap[other->corners[15]];
    result.corners[21] = color_swap[other->corners[14]];
    result.corners[22] = color_swap[other->corners[13]];
    result.corners[23] = color_swap[other->corners[12]];
    return result;
}

cube z_3(cube *other) {
    cube result;
    int color_swap[7] = { 5, 1, 3, 0, 4, 2, 6 };
    result.edges[0] = color_swap[other->edges[13]];
    result.edges[1] = color_swap[other->edges[14]];
    result.edges[2] = color_swap[other->edges[15]];
    result.edges[3] = color_swap[other->edges[12]];
    result.edges[4] = color_swap[other->edges[5]];
    result.edges[5] = color_swap[other->edges[6]];
    result.edges[6] = color_swap[other->edges[7]];
    result.edges[7] = color_swap[other->edges[4]];
    result.edges[8] = color_swap[other->edges[21]];
    result.edges[9] = color_swap[other->edges[22]];
    result.edges[10] = color_swap[other->edges[23]];
    result.edges[11] = color_swap[other->edges[20]];
    result.edges[12] = color_swap[other->edges[9]];
    result.edges[13] = color_swap[other->edges[10]];
    result.edges[14] = color_swap[other->edges[11]];
    result.edges[15] = color_swap[other->edges[8]];
    result.edges[16] = color_swap[other->edges[19]];
    result.edges[17] = color_swap[other->edges[16]];
    result.edges[18] = color_swap[other->edges[17]];
    result.edges[19] = color_swap[other->edges[18]];
    result.edges[20] = color_swap[other->edges[1]];
    result.edges[21] = color_swap[other->edges[2]];
    result.edges[22] = color_swap[other->edges[3]];
    result.edges[23] = color_swap[other->edges[0]];
    result.corners[0] = color_swap[other->corners[13]];
    result.corners[1] = color_swap[other->corners[15]];
    result.corners[2] = color_swap[other->corners[12]];
    result.corners[3] = color_swap[other->corners[14]];
    result.corners[4] = color_swap[other->corners[5]];
    result.corners[5] = color_swap[other->corners[7]];
    result.corners[6] = color_swap[other->corners[4]];
    result.corners[7] = color_swap[other->corners[6]];
    result.corners[8] = color_swap[other->corners[21]];
    result.corners[9] = color_swap[other->corners[23]];
    result.corners[10] = color_swap[other->corners[20]];
    result.corners[11] = color_swap[other->corners[22]];
    result.corners[12] = color_swap[other->corners[9]];
    result.corners[13] = color_swap[other->corners[11]];
    result.corners[14] = color_swap[other->corners[8]];
    result.corners[15] = color_swap[other->corners[10]];
    result.corners[16] = color_swap[other->corners[18]];
    result.corners[17] = color_swap[other->corners[16]];
    result.corners[18] = color_swap[other->corners[19]];
    result.corners[19] = color_swap[other->corners[17]];
    result.corners[20] = color_swap[other->corners[1]];
    result.corners[21] = color_swap[other->corners[3]];
    result.corners[22] = color_swap[other->corners[0]];
    result.corners[23] = color_swap[other->corners[2]];
    return result;
}

cube M_1(cube *other) {
    cube result;
    int color_swap[7] = { 1, 2, 4, 3, 0, 5, 6 };
    result.edges[0] = color_swap[other->edges[18]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[16]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[0]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[2]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[4]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[6]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[10]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[8]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube M_2(cube *other) {
    cube result;
    int color_swap[7] = { 2, 4, 0, 3, 1, 5, 6 };
    result.edges[0] = color_swap[other->edges[8]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[10]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[18]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[16]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[0]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[2]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[6]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[4]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube M_3(cube *other) {
    cube result;
    int color_swap[7] = { 4, 0, 1, 3, 2, 5, 6 };
    result.edges[0] = color_swap[other->edges[4]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[6]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[8]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[10]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[18]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[16]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[2]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[0]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube E_1(cube *other) {
    cube result;
    int color_swap[7] = { 0, 3, 2, 4, 5, 1, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[21]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[23]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[5]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[7]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[13]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[15]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[17]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[19]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube E_2(cube *other) {
    cube result;
    int color_swap[7] = { 0, 4, 2, 5, 1, 3, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[17]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[19]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[21]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[23]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[5]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[7]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[13]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[15]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube E_3(cube *other) {
    cube result;
    int color_swap[7] = { 0, 5, 2, 1, 3, 4, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[13]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[15]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[17]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[19]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[21]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[23]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[5]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[7]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube S_1(cube *other) {
    cube result;
    int color_swap[7] = { 3, 1, 5, 2, 4, 0, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[20]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[22]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[12]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[14]];
    result.edges[12] = color_swap[other->edges[3]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[1]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[11]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[9]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube S_2(cube *other) {
    cube result;
    int color_swap[7] = { 2, 1, 0, 5, 4, 3, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[11]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[9]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[3]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[1]];
    result.edges[12] = color_swap[other->edges[22]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[20]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[14]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[12]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube S_3(cube *other) {
    cube result;
    int color_swap[7] = { 5, 1, 3, 0, 4, 2, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[14]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[12]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[22]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[20]];
    result.edges[12] = color_swap[other->edges[9]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[11]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[1]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[3]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube r_1(cube *other) {
    cube result;
    int color_swap[7] = { 4, 0, 1, 3, 2, 5, 6 };
    result.edges[0] = color_swap[other->edges[4]];
    result.edges[1] = color_swap[other->edges[5]];
    result.edges[2] = color_swap[other->edges[6]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[8]];
    result.edges[5] = color_swap[other->edges[9]];
    result.edges[6] = color_swap[other->edges[10]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[18]];
    result.edges[9] = color_swap[other->edges[19]];
    result.edges[10] = color_swap[other->edges[16]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[15]];
    result.edges[13] = color_swap[other->edges[12]];
    result.edges[14] = color_swap[other->edges[13]];
    result.edges[15] = color_swap[other->edges[14]];
    result.edges[16] = color_swap[other->edges[2]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[0]];
    result.edges[19] = color_swap[other->edges[1]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[5]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[7]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[9]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[11]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[18]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[16]];
    result.corners[12] = color_swap[other->corners[14]];
    result.corners[13] = color_swap[other->corners[12]];
    result.corners[14] = color_swap[other->corners[15]];
    result.corners[15] = color_swap[other->corners[13]];
    result.corners[16] = color_swap[other->corners[3]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[1]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube r_2(cube *other) {
    cube result;
    int color_swap[7] = { 2, 4, 0, 3, 1, 5, 6 };
    result.edges[0] = color_swap[other->edges[8]];
    result.edges[1] = color_swap[other->edges[9]];
    result.edges[2] = color_swap[other->edges[10]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[18]];
    result.edges[5] = color_swap[other->edges[19]];
    result.edges[6] = color_swap[other->edges[16]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[0]];
    result.edges[9] = color_swap[other->edges[1]];
    result.edges[10] = color_swap[other->edges[2]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[14]];
    result.edges[13] = color_swap[other->edges[15]];
    result.edges[14] = color_swap[other->edges[12]];
    result.edges[15] = color_swap[other->edges[13]];
    result.edges[16] = color_swap[other->edges[6]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[4]];
    result.edges[19] = color_swap[other->edges[5]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[9]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[11]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[18]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[16]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[1]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[3]];
    result.corners[12] = color_swap[other->corners[15]];
    result.corners[13] = color_swap[other->corners[14]];
    result.corners[14] = color_swap[other->corners[13]];
    result.corners[15] = color_swap[other->corners[12]];
    result.corners[16] = color_swap[other->corners[7]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[5]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube r_3(cube *other) {
    cube result;
    int color_swap[7] = { 1, 2, 4, 3, 0, 5, 6 };
    result.edges[0] = color_swap[other->edges[18]];
    result.edges[1] = color_swap[other->edges[19]];
    result.edges[2] = color_swap[other->edges[16]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[0]];
    result.edges[5] = color_swap[other->edges[1]];
    result.edges[6] = color_swap[other->edges[2]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[4]];
    result.edges[9] = color_swap[other->edges[5]];
    result.edges[10] = color_swap[other->edges[6]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[13]];
    result.edges[13] = color_swap[other->edges[14]];
    result.edges[14] = color_swap[other->edges[15]];
    result.edges[15] = color_swap[other->edges[12]];
    result.edges[16] = color_swap[other->edges[10]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[8]];
    result.edges[19] = color_swap[other->edges[9]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[18]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[16]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[1]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[3]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[5]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[7]];
    result.corners[12] = color_swap[other->corners[13]];
    result.corners[13] = color_swap[other->corners[15]];
    result.corners[14] = color_swap[other->corners[12]];
    result.corners[15] = color_swap[other->corners[14]];
    result.corners[16] = color_swap[other->corners[11]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[9]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube l_1(cube *other) {
    cube result;
    int color_swap[7] = { 1, 2, 4, 3, 0, 5, 6 };
    result.edges[0] = color_swap[other->edges[18]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[16]];
    result.edges[3] = color_swap[other->edges[17]];
    result.edges[4] = color_swap[other->edges[0]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[2]];
    result.edges[7] = color_swap[other->edges[3]];
    result.edges[8] = color_swap[other->edges[4]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[6]];
    result.edges[11] = color_swap[other->edges[7]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[10]];
    result.edges[17] = color_swap[other->edges[11]];
    result.edges[18] = color_swap[other->edges[8]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[23]];
    result.edges[21] = color_swap[other->edges[20]];
    result.edges[22] = color_swap[other->edges[21]];
    result.edges[23] = color_swap[other->edges[22]];
    result.corners[0] = color_swap[other->corners[19]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[17]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[0]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[2]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[4]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[6]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[10]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[8]];
    result.corners[20] = color_swap[other->corners[22]];
    result.corners[21] = color_swap[other->corners[20]];
    result.corners[22] = color_swap[other->corners[23]];
    result.corners[23] = color_swap[other->corners[21]];
    return result;
}

cube l_2(cube *other) {
    cube result;
    int color_swap[7] = { 2, 4, 0, 3, 1, 5, 6 };
    result.edges[0] = color_swap[other->edges[8]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[10]];
    result.edges[3] = color_swap[other->edges[11]];
    result.edges[4] = color_swap[other->edges[18]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[16]];
    result.edges[7] = color_swap[other->edges[17]];
    result.edges[8] = color_swap[other->edges[0]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[2]];
    result.edges[11] = color_swap[other->edges[3]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[6]];
    result.edges[17] = color_swap[other->edges[7]];
    result.edges[18] = color_swap[other->edges[4]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[22]];
    result.edges[21] = color_swap[other->edges[23]];
    result.edges[22] = color_swap[other->edges[20]];
    result.edges[23] = color_swap[other->edges[21]];
    result.corners[0] = color_swap[other->corners[8]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[10]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[19]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[17]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[0]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[2]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[6]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[4]];
    result.corners[20] = color_swap[other->corners[23]];
    result.corners[21] = color_swap[other->corners[22]];
    result.corners[22] = color_swap[other->corners[21]];
    result.corners[23] = color_swap[other->corners[20]];
    return result;
}

cube l_3(cube *other) {
    cube result;
    int color_swap[7] = { 4, 0, 1, 3, 2, 5, 6 };
    result.edges[0] = color_swap[other->edges[4]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[6]];
    result.edges[3] = color_swap[other->edges[7]];
    result.edges[4] = color_swap[other->edges[8]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[10]];
    result.edges[7] = color_swap[other->edges[11]];
    result.edges[8] = color_swap[other->edges[18]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[16]];
    result.edges[11] = color_swap[other->edges[17]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[2]];
    result.edges[17] = color_swap[other->edges[3]];
    result.edges[18] = color_swap[other->edges[0]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[21]];
    result.edges[21] = color_swap[other->edges[22]];
    result.edges[22] = color_swap[other->edges[23]];
    result.edges[23] = color_swap[other->edges[20]];
    result.corners[0] = color_swap[other->corners[4]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[6]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[8]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[10]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[19]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[17]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[2]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[0]];
    result.corners[20] = color_swap[other->corners[21]];
    result.corners[21] = color_swap[other->corners[23]];
    result.corners[22] = color_swap[other->corners[20]];
    result.corners[23] = color_swap[other->corners[22]];
    return result;
}

cube u_1(cube *other) {
    cube result;
    int color_swap[7] = { 0, 5, 2, 1, 3, 4, 6 };
    result.edges[0] = color_swap[other->edges[3]];
    result.edges[1] = color_swap[other->edges[0]];
    result.edges[2] = color_swap[other->edges[1]];
    result.edges[3] = color_swap[other->edges[2]];
    result.edges[4] = color_swap[other->edges[12]];
    result.edges[5] = color_swap[other->edges[13]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[15]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[16]];
    result.edges[13] = color_swap[other->edges[17]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[19]];
    result.edges[16] = color_swap[other->edges[20]];
    result.edges[17] = color_swap[other->edges[21]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[23]];
    result.edges[20] = color_swap[other->edges[4]];
    result.edges[21] = color_swap[other->edges[5]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[7]];
    result.corners[0] = color_swap[other->corners[2]];
    result.corners[1] = color_swap[other->corners[0]];
    result.corners[2] = color_swap[other->corners[3]];
    result.corners[3] = color_swap[other->corners[1]];
    result.corners[4] = color_swap[other->corners[12]];
    result.corners[5] = color_swap[other->corners[13]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[16]];
    result.corners[13] = color_swap[other->corners[17]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[20]];
    result.corners[17] = color_swap[other->corners[21]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[4]];
    result.corners[21] = color_swap[other->corners[5]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube u_2(cube *other) {
    cube result;
    int color_swap[7] = { 0, 4, 2, 5, 1, 3, 6 };
    result.edges[0] = color_swap[other->edges[2]];
    result.edges[1] = color_swap[other->edges[3]];
    result.edges[2] = color_swap[other->edges[0]];
    result.edges[3] = color_swap[other->edges[1]];
    result.edges[4] = color_swap[other->edges[16]];
    result.edges[5] = color_swap[other->edges[17]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[19]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[20]];
    result.edges[13] = color_swap[other->edges[21]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[23]];
    result.edges[16] = color_swap[other->edges[4]];
    result.edges[17] = color_swap[other->edges[5]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[7]];
    result.edges[20] = color_swap[other->edges[12]];
    result.edges[21] = color_swap[other->edges[13]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[15]];
    result.corners[0] = color_swap[other->corners[3]];
    result.corners[1] = color_swap[other->corners[2]];
    result.corners[2] = color_swap[other->corners[1]];
    result.corners[3] = color_swap[other->corners[0]];
    result.corners[4] = color_swap[other->corners[16]];
    result.corners[5] = color_swap[other->corners[17]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[20]];
    result.corners[13] = color_swap[other->corners[21]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[4]];
    result.corners[17] = color_swap[other->corners[5]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[12]];
    result.corners[21] = color_swap[other->corners[13]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube u_3(cube *other) {
    cube result;
    int color_swap[7] = { 0, 3, 2, 4, 5, 1, 6 };
    result.edges[0] = color_swap[other->edges[1]];
    result.edges[1] = color_swap[other->edges[2]];
    result.edges[2] = color_swap[other->edges[3]];
    result.edges[3] = color_swap[other->edges[0]];
    result.edges[4] = color_swap[other->edges[20]];
    result.edges[5] = color_swap[other->edges[21]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[23]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[9]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[11]];
    result.edges[12] = color_swap[other->edges[4]];
    result.edges[13] = color_swap[other->edges[5]];
    result.edges[14] = color_swap[other->edges[14]];
    result.edges[15] = color_swap[other->edges[7]];
    result.edges[16] = color_swap[other->edges[12]];
    result.edges[17] = color_swap[other->edges[13]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[15]];
    result.edges[20] = color_swap[other->edges[16]];
    result.edges[21] = color_swap[other->edges[17]];
    result.edges[22] = color_swap[other->edges[22]];
    result.edges[23] = color_swap[other->edges[19]];
    result.corners[0] = color_swap[other->corners[1]];
    result.corners[1] = color_swap[other->corners[3]];
    result.corners[2] = color_swap[other->corners[0]];
    result.corners[3] = color_swap[other->corners[2]];
    result.corners[4] = color_swap[other->corners[20]];
    result.corners[5] = color_swap[other->corners[21]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[4]];
    result.corners[13] = color_swap[other->corners[5]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[12]];
    result.corners[17] = color_swap[other->corners[13]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[16]];
    result.corners[21] = color_swap[other->corners[17]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube d_1(cube *other) {
    cube result;
    int color_swap[7] = { 0, 3, 2, 4, 5, 1, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[21]];
    result.edges[6] = color_swap[other->edges[22]];
    result.edges[7] = color_swap[other->edges[23]];
    result.edges[8] = color_swap[other->edges[11]];
    result.edges[9] = color_swap[other->edges[8]];
    result.edges[10] = color_swap[other->edges[9]];
    result.edges[11] = color_swap[other->edges[10]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[5]];
    result.edges[14] = color_swap[other->edges[6]];
    result.edges[15] = color_swap[other->edges[7]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[13]];
    result.edges[18] = color_swap[other->edges[14]];
    result.edges[19] = color_swap[other->edges[15]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[17]];
    result.edges[22] = color_swap[other->edges[18]];
    result.edges[23] = color_swap[other->edges[19]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[22]];
    result.corners[7] = color_swap[other->corners[23]];
    result.corners[8] = color_swap[other->corners[10]];
    result.corners[9] = color_swap[other->corners[8]];
    result.corners[10] = color_swap[other->corners[11]];
    result.corners[11] = color_swap[other->corners[9]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[6]];
    result.corners[15] = color_swap[other->corners[7]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[14]];
    result.corners[19] = color_swap[other->corners[15]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[18]];
    result.corners[23] = color_swap[other->corners[19]];
    return result;
}

cube d_2(cube *other) {
    cube result;
    int color_swap[7] = { 0, 4, 2, 5, 1, 3, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[17]];
    result.edges[6] = color_swap[other->edges[18]];
    result.edges[7] = color_swap[other->edges[19]];
    result.edges[8] = color_swap[other->edges[10]];
    result.edges[9] = color_swap[other->edges[11]];
    result.edges[10] = color_swap[other->edges[8]];
    result.edges[11] = color_swap[other->edges[9]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[21]];
    result.edges[14] = color_swap[other->edges[22]];
    result.edges[15] = color_swap[other->edges[23]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[5]];
    result.edges[18] = color_swap[other->edges[6]];
    result.edges[19] = color_swap[other->edges[7]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[13]];
    result.edges[22] = color_swap[other->edges[14]];
    result.edges[23] = color_swap[other->edges[15]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[18]];
    result.corners[7] = color_swap[other->corners[19]];
    result.corners[8] = color_swap[other->corners[11]];
    result.corners[9] = color_swap[other->corners[10]];
    result.corners[10] = color_swap[other->corners[9]];
    result.corners[11] = color_swap[other->corners[8]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[22]];
    result.corners[15] = color_swap[other->corners[23]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[6]];
    result.corners[19] = color_swap[other->corners[7]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[14]];
    result.corners[23] = color_swap[other->corners[15]];
    return result;
}

cube d_3(cube *other) {
    cube result;
    int color_swap[7] = { 0, 5, 2, 1, 3, 4, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[1]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[3]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[13]];
    result.edges[6] = color_swap[other->edges[14]];
    result.edges[7] = color_swap[other->edges[15]];
    result.edges[8] = color_swap[other->edges[9]];
    result.edges[9] = color_swap[other->edges[10]];
    result.edges[10] = color_swap[other->edges[11]];
    result.edges[11] = color_swap[other->edges[8]];
    result.edges[12] = color_swap[other->edges[12]];
    result.edges[13] = color_swap[other->edges[17]];
    result.edges[14] = color_swap[other->edges[18]];
    result.edges[15] = color_swap[other->edges[19]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[21]];
    result.edges[18] = color_swap[other->edges[22]];
    result.edges[19] = color_swap[other->edges[23]];
    result.edges[20] = color_swap[other->edges[20]];
    result.edges[21] = color_swap[other->edges[5]];
    result.edges[22] = color_swap[other->edges[6]];
    result.edges[23] = color_swap[other->edges[7]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[14]];
    result.corners[7] = color_swap[other->corners[15]];
    result.corners[8] = color_swap[other->corners[9]];
    result.corners[9] = color_swap[other->corners[11]];
    result.corners[10] = color_swap[other->corners[8]];
    result.corners[11] = color_swap[other->corners[10]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[18]];
    result.corners[15] = color_swap[other->corners[19]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[22]];
    result.corners[19] = color_swap[other->corners[23]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[6]];
    result.corners[23] = color_swap[other->corners[7]];
    return result;
}

cube f_1(cube *other) {
    cube result;
    int color_swap[7] = { 3, 1, 5, 2, 4, 0, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[20]];
    result.edges[2] = color_swap[other->edges[21]];
    result.edges[3] = color_swap[other->edges[22]];
    result.edges[4] = color_swap[other->edges[7]];
    result.edges[5] = color_swap[other->edges[4]];
    result.edges[6] = color_swap[other->edges[5]];
    result.edges[7] = color_swap[other->edges[6]];
    result.edges[8] = color_swap[other->edges[15]];
    result.edges[9] = color_swap[other->edges[12]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[14]];
    result.edges[12] = color_swap[other->edges[3]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[1]];
    result.edges[15] = color_swap[other->edges[2]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[11]];
    result.edges[21] = color_swap[other->edges[8]];
    result.edges[22] = color_swap[other->edges[9]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[23]];
    result.corners[3] = color_swap[other->corners[21]];
    result.corners[4] = color_swap[other->corners[6]];
    result.corners[5] = color_swap[other->corners[4]];
    result.corners[6] = color_swap[other->corners[7]];
    result.corners[7] = color_swap[other->corners[5]];
    result.corners[8] = color_swap[other->corners[14]];
    result.corners[9] = color_swap[other->corners[12]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[2]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[3]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[8]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[9]];
    return result;
}

cube f_2(cube *other) {
    cube result;
    int color_swap[7] = { 2, 1, 0, 5, 4, 3, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[11]];
    result.edges[2] = color_swap[other->edges[8]];
    result.edges[3] = color_swap[other->edges[9]];
    result.edges[4] = color_swap[other->edges[6]];
    result.edges[5] = color_swap[other->edges[7]];
    result.edges[6] = color_swap[other->edges[4]];
    result.edges[7] = color_swap[other->edges[5]];
    result.edges[8] = color_swap[other->edges[2]];
    result.edges[9] = color_swap[other->edges[3]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[1]];
    result.edges[12] = color_swap[other->edges[22]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[20]];
    result.edges[15] = color_swap[other->edges[21]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[14]];
    result.edges[21] = color_swap[other->edges[15]];
    result.edges[22] = color_swap[other->edges[12]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[9]];
    result.corners[3] = color_swap[other->corners[8]];
    result.corners[4] = color_swap[other->corners[7]];
    result.corners[5] = color_swap[other->corners[6]];
    result.corners[6] = color_swap[other->corners[5]];
    result.corners[7] = color_swap[other->corners[4]];
    result.corners[8] = color_swap[other->corners[3]];
    result.corners[9] = color_swap[other->corners[2]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[23]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[21]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[14]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[12]];
    return result;
}

cube f_3(cube *other) {
    cube result;
    int color_swap[7] = { 5, 1, 3, 0, 4, 2, 6 };
    result.edges[0] = color_swap[other->edges[0]];
    result.edges[1] = color_swap[other->edges[14]];
    result.edges[2] = color_swap[other->edges[15]];
    result.edges[3] = color_swap[other->edges[12]];
    result.edges[4] = color_swap[other->edges[5]];
    result.edges[5] = color_swap[other->edges[6]];
    result.edges[6] = color_swap[other->edges[7]];
    result.edges[7] = color_swap[other->edges[4]];
    result.edges[8] = color_swap[other->edges[21]];
    result.edges[9] = color_swap[other->edges[22]];
    result.edges[10] = color_swap[other->edges[10]];
    result.edges[11] = color_swap[other->edges[20]];
    result.edges[12] = color_swap[other->edges[9]];
    result.edges[13] = color_swap[other->edges[13]];
    result.edges[14] = color_swap[other->edges[11]];
    result.edges[15] = color_swap[other->edges[8]];
    result.edges[16] = color_swap[other->edges[16]];
    result.edges[17] = color_swap[other->edges[17]];
    result.edges[18] = color_swap[other->edges[18]];
    result.edges[19] = color_swap[other->edges[19]];
    result.edges[20] = color_swap[other->edges[1]];
    result.edges[21] = color_swap[other->edges[2]];
    result.edges[22] = color_swap[other->edges[3]];
    result.edges[23] = color_swap[other->edges[23]];
    result.corners[0] = color_swap[other->corners[0]];
    result.corners[1] = color_swap[other->corners[1]];
    result.corners[2] = color_swap[other->corners[12]];
    result.corners[3] = color_swap[other->corners[14]];
    result.corners[4] = color_swap[other->corners[5]];
    result.corners[5] = color_swap[other->corners[7]];
    result.corners[6] = color_swap[other->corners[4]];
    result.corners[7] = color_swap[other->corners[6]];
    result.corners[8] = color_swap[other->corners[21]];
    result.corners[9] = color_swap[other->corners[23]];
    result.corners[10] = color_swap[other->corners[10]];
    result.corners[11] = color_swap[other->corners[11]];
    result.corners[12] = color_swap[other->corners[9]];
    result.corners[13] = color_swap[other->corners[13]];
    result.corners[14] = color_swap[other->corners[8]];
    result.corners[15] = color_swap[other->corners[15]];
    result.corners[16] = color_swap[other->corners[16]];
    result.corners[17] = color_swap[other->corners[17]];
    result.corners[18] = color_swap[other->corners[18]];
    result.corners[19] = color_swap[other->corners[19]];
    result.corners[20] = color_swap[other->corners[20]];
    result.corners[21] = color_swap[other->corners[3]];
    result.corners[22] = color_swap[other->corners[22]];
    result.corners[23] = color_swap[other->corners[2]];
    return result;
}

cube b_1(cube *other) {
    cube result;
    int color_swap[7] = { 5, 1, 3, 0, 4, 2, 6 };
    result.edges[0] = color_swap[other->edges[13]];
    result.edges[1] = color_swap[other->edges[14]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[12]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[22]];
    result.edges[10] = color_swap[other->edges[23]];
    result.edges[11] = color_swap[other->edges[20]];
    result.edges[12] = color_swap[other->edges[9]];
    result.edges[13] = color_swap[other->edges[10]];
    result.edges[14] = color_swap[other->edges[11]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[19]];
    result.edges[17] = color_swap[other->edges[16]];
    result.edges[18] = color_swap[other->edges[17]];
    result.edges[19] = color_swap[other->edges[18]];
    result.edges[20] = color_swap[other->edges[1]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[3]];
    result.edges[23] = color_swap[other->edges[0]];
    result.corners[0] = color_swap[other->corners[13]];
    result.corners[1] = color_swap[other->corners[15]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[20]];
    result.corners[11] = color_swap[other->corners[22]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[11]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[10]];
    result.corners[16] = color_swap[other->corners[18]];
    result.corners[17] = color_swap[other->corners[16]];
    result.corners[18] = color_swap[other->corners[19]];
    result.corners[19] = color_swap[other->corners[17]];
    result.corners[20] = color_swap[other->corners[1]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[0]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube b_2(cube *other) {
    cube result;
    int color_swap[7] = { 2, 1, 0, 5, 4, 3, 6 };
    result.edges[0] = color_swap[other->edges[10]];
    result.edges[1] = color_swap[other->edges[11]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[9]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[3]];
    result.edges[10] = color_swap[other->edges[0]];
    result.edges[11] = color_swap[other->edges[1]];
    result.edges[12] = color_swap[other->edges[22]];
    result.edges[13] = color_swap[other->edges[23]];
    result.edges[14] = color_swap[other->edges[20]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[18]];
    result.edges[17] = color_swap[other->edges[19]];
    result.edges[18] = color_swap[other->edges[16]];
    result.edges[19] = color_swap[other->edges[17]];
    result.edges[20] = color_swap[other->edges[14]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[12]];
    result.edges[23] = color_swap[other->edges[13]];
    result.corners[0] = color_swap[other->corners[11]];
    result.corners[1] = color_swap[other->corners[10]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[1]];
    result.corners[11] = color_swap[other->corners[0]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[22]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[20]];
    result.corners[16] = color_swap[other->corners[19]];
    result.corners[17] = color_swap[other->corners[18]];
    result.corners[18] = color_swap[other->corners[17]];
    result.corners[19] = color_swap[other->corners[16]];
    result.corners[20] = color_swap[other->corners[15]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[13]];
    result.corners[23] = color_swap[other->corners[23]];
    return result;
}

cube b_3(cube *other) {
    cube result;
    int color_swap[7] = { 3, 1, 5, 2, 4, 0, 6 };
    result.edges[0] = color_swap[other->edges[23]];
    result.edges[1] = color_swap[other->edges[20]];
    result.edges[2] = color_swap[other->edges[2]];
    result.edges[3] = color_swap[other->edges[22]];
    result.edges[4] = color_swap[other->edges[4]];
    result.edges[5] = color_swap[other->edges[5]];
    result.edges[6] = color_swap[other->edges[6]];
    result.edges[7] = color_swap[other->edges[7]];
    result.edges[8] = color_swap[other->edges[8]];
    result.edges[9] = color_swap[other->edges[12]];
    result.edges[10] = color_swap[other->edges[13]];
    result.edges[11] = color_swap[other->edges[14]];
    result.edges[12] = color_swap[other->edges[3]];
    result.edges[13] = color_swap[other->edges[0]];
    result.edges[14] = color_swap[other->edges[1]];
    result.edges[15] = color_swap[other->edges[15]];
    result.edges[16] = color_swap[other->edges[17]];
    result.edges[17] = color_swap[other->edges[18]];
    result.edges[18] = color_swap[other->edges[19]];
    result.edges[19] = color_swap[other->edges[16]];
    result.edges[20] = color_swap[other->edges[11]];
    result.edges[21] = color_swap[other->edges[21]];
    result.edges[22] = color_swap[other->edges[9]];
    result.edges[23] = color_swap[other->edges[10]];
    result.corners[0] = color_swap[other->corners[22]];
    result.corners[1] = color_swap[other->corners[20]];
    result.corners[2] = color_swap[other->corners[2]];
    result.corners[3] = color_swap[other->corners[3]];
    result.corners[4] = color_swap[other->corners[4]];
    result.corners[5] = color_swap[other->corners[5]];
    result.corners[6] = color_swap[other->corners[6]];
    result.corners[7] = color_swap[other->corners[7]];
    result.corners[8] = color_swap[other->corners[8]];
    result.corners[9] = color_swap[other->corners[9]];
    result.corners[10] = color_swap[other->corners[15]];
    result.corners[11] = color_swap[other->corners[13]];
    result.corners[12] = color_swap[other->corners[12]];
    result.corners[13] = color_swap[other->corners[0]];
    result.corners[14] = color_swap[other->corners[14]];
    result.corners[15] = color_swap[other->corners[1]];
    result.corners[16] = color_swap[other->corners[17]];
    result.corners[17] = color_swap[other->corners[19]];
    result.corners[18] = color_swap[other->corners[16]];
    result.corners[19] = color_swap[other->corners[18]];
    result.corners[20] = color_swap[other->corners[10]];
    result.corners[21] = color_swap[other->corners[21]];
    result.corners[22] = color_swap[other->corners[11]];
    result.corners[23] = color_swap[other->corners[23]];
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
x_1,
x_2,
x_3,
y_1,
y_2,
y_3,
z_1,
z_2,
z_3,
M_1,
M_2,
M_3,
E_1,
E_2,
E_3,
S_1,
S_2,
S_3,
r_1,
r_2,
r_3,
l_1,
l_2,
l_3,
u_1,
u_2,
u_3,
d_1,
d_2,
d_3,
f_1,
f_2,
f_3,
b_1,
b_2,
b_3
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
"x",
"x2",
"x'",
"y",
"y2",
"y'",
"z",
"z2",
"z'",
"M",
"M2",
"M'",
"E",
"E2",
"E'",
"S",
"S2",
"S'",
"r",
"r2",
"r'",
"l",
"l2",
"l'",
"u",
"u2",
"u'",
"d",
"d2",
"d'",
"f",
"f2",
"f'",
"b",
"b2",
"b'"
};
