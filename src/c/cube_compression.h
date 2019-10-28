#include <stdint.h>
#include "cube3.h"
#ifndef CUBE_COMPRESION
#define CUBE_COMPRESION

void unpack_ce(cube *c, int8_t *last_move, __uint128_t compressed);
__uint128_t pack_ce (cube *c, int8_t last_move);

int8_t unpack_last_move(__uint128_t compressed);
#endif