#include "cube3.h"
#include "cube3r.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define UNPACK_DIM_LEN 8

int unpack_secret [64] = {-1};
// this means : if you have a corner where left color is X, right color is Y then top color is unpack_secret[X*6 + Y].
// For packing cubes with ghost corners must always use either fully occupied corners or fully empty

void initialize_cube_compression(void) {
    for (int i=0; i<64; i++) {
        unpack_secret[i] = -1;
    }
    int corners_in_proper_order[8][3] = {
         {7, 9, 14}, {8, 6, 23}, {15, 11, 18}, {19, 10, 22}, {3, 5, 12}, {4, 2, 21}, {16, 1, 13}, {0, 17, 20}
    };
    for (int corner_id = 0; corner_id <8; corner_id++) {
        int a = corners_in_proper_order[corner_id][0] / 4;
        int b = corners_in_proper_order[corner_id][1] / 4;
        int c = corners_in_proper_order[corner_id][2] / 4;
        unpack_secret[a * UNPACK_DIM_LEN + b] = c;
        unpack_secret[b * UNPACK_DIM_LEN + c] = a;
        unpack_secret[c * UNPACK_DIM_LEN + a] = b;
    }
    for (int i=0; i<=6; i++) {
        unpack_secret[i * UNPACK_DIM_LEN + i] = i;
    }
    //7 7 0 corner is a special case used for corner orientation
    unpack_secret[7 * UNPACK_DIM_LEN + 7] = 6;
    unpack_secret[7 * UNPACK_DIM_LEN + 6] = 7;
    unpack_secret[6 * UNPACK_DIM_LEN + 7] = 7;
}

int8_t unpack_last_move(__uint128_t compressed) {
    return (int8_t)compressed;
}

void unpack_ce(cube *c, int8_t *last_move, __uint128_t compressed) {
    uint8_t* corners = c->corners;
    uint8_t* edges = c->edges;

    __uint128_t mask = 7;

    last_move[0] = (int8_t)compressed;
    compressed >>= 8;

    for (int i=4; i<8; i++) {
        corners[i] = compressed & mask;
        compressed >>= 3;
    }
    for (int i=12; i<24; i++) {
        corners[i] = compressed & mask;
        compressed >>= 3;
    }
    for (int i=0; i<24; i++) {
        edges[i] = compressed & mask;
        compressed >>= 3;
    }
    corners[0] = unpack_secret[ corners[17] * UNPACK_DIM_LEN + corners[20]];
    corners[1] = unpack_secret[ corners[13] * UNPACK_DIM_LEN + corners[16]];
    corners[2] = unpack_secret[ corners[21] * UNPACK_DIM_LEN + corners[4]];
    corners[3] = unpack_secret[ corners[5] * UNPACK_DIM_LEN + corners[12]];
    corners[8] = unpack_secret[ corners[6] * UNPACK_DIM_LEN + corners[23]];
    corners[9] = unpack_secret[ corners[14] * UNPACK_DIM_LEN + corners[7]];
    corners[10] = unpack_secret[ corners[22] * UNPACK_DIM_LEN + corners[19]];
    corners[11] = unpack_secret[ corners[18] * UNPACK_DIM_LEN + corners[15]];
    
}

__uint128_t pack_ce (cube *c, int8_t last_move) {
    uint8_t* corners = c->corners;
    uint8_t* edges = c->edges;

    __uint128_t retVal = last_move;
    int shift = 8;
    // 0 1 2 3, 8 9 10 11

    for (int i=4; i<8; i++) {
        retVal |= ((__uint128_t)(corners[i])) << shift; shift += 3;
    }
    for (int i=12; i<24; i++) {
        retVal |= ((__uint128_t)(corners[i])) << shift; shift += 3;
    }
    for (int i=0; i<24; i++) {
        retVal |= ((__uint128_t)(edges[i])) << shift; shift += 3;
    }
    assert(shift == 128);
    
    return retVal;
}

void check_packing(cube c, int8_t last_move)
{
    cube other_c;
    int8_t unpacked_last_move;

    __uint128_t packed = pack_ce(&c, last_move);
    unpack_ce(&other_c, &unpacked_last_move, packed);


    if (cube_compare(&c, &other_c) != 0) {
        link(&other_c, "print"); 
        printf("WRONG pack of cube\n");
        exit(0);
    }
    else {
        //printf("ok pack\n");
    }
    if (last_move != unpacked_last_move) {
        printf("WRONG pack of cube last_move\n");
        exit(0);
    }
}
