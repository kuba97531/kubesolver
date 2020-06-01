#include "solver_cube_compression.h"
#ifndef SOLVER_GROWING_CACHE
#define SOLVER_GROWING_CACHE

typedef struct {
  solver_cube_packed *array;
  uint64_t used;
  uint64_t size;
} growing_cache;

void init_growing_cache(growing_cache* cache);
void resize_growing_cache(growing_cache* cache);

#endif