#include "cube3.h"
#include "cube_compression.h"
#include <stdint.h>
#include <assert.h>
int unpack_secret [36] = {0, 3, 0, 4, 5, 1, 5, 0, 3, 0, 0, 2, 0, 5, 0, 1, 3, 4, 1, 2, 4, 0, 0, 0, 3, 0, 5, 2, 0, 0, 4, 0, 1, 0, 2, 0};

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
    corners[0] = unpack_secret[ corners[17] * 6 + corners[20]];
    corners[1] = unpack_secret[ corners[13] * 6 + corners[16]];
    corners[2] = unpack_secret[ corners[21] * 6 + corners[4]];
    corners[3] = unpack_secret[ corners[5] * 6 + corners[12]];
    corners[8] = unpack_secret[ corners[6] * 6 + corners[23]];
    corners[9] = unpack_secret[ corners[14] * 6 + corners[7]];
    corners[10] = unpack_secret[ corners[22] * 6 + corners[19]];
    corners[11] = unpack_secret[ corners[18] * 6 + corners[15]];
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


    
