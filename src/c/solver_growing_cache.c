#include "solver_growing_cache.h"
#include <stdlib.h>
#include <stdio.h>

const int initial_cache_size = 1024*16;

void init_growing_cache(growing_cache* cache) {
    cache->array = malloc(initial_cache_size * sizeof(solver_cube_packed));
    cache->used = 0;
    cache->size = initial_cache_size;
}

void resize_growing_cache(growing_cache* cache) {
    if (cache->used > cache->size - 1) {
        uint64_t new_size = cache->size * 2;
        //info("regrowing cache to %d, as it's too small", new_size);
        solver_cube_packed* bigger = realloc(cache->array, new_size * sizeof(solver_cube_packed));
        if (bigger == NULL) {
            printf("ERROR: not enough memory\n");
            exit(0);
        }
        cache->size = cache->size * 2;
        cache->array = bigger;
    }
}