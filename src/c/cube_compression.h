#include <stdint.h>
#include "cube3.h"
#ifndef CUBE_COMPRESION
#define CUBE_COMPRESION

typedef struct 
{
    __uint128_t packed; 
} solver_cube_packed;

typedef struct 
{
    cube cube; 
    int8_t last_move;
} solver_cube_unpacked;

void initialize_cube_compression(void);

void unpack_ce(cube *c, int8_t *last_move, __uint128_t compressed);
__uint128_t pack_ce (cube *c, int8_t last_move);

int8_t unpack_last_move(__uint128_t compressed);

void check_packing(cube c, int8_t last_move);
#endif