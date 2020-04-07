#include <stdint.h>

#ifndef CUBE3
#define CUBE3
typedef struct {
    uint8_t edges[24];
    uint8_t corners[24];
} cube;

typedef cube (*t_rotation)(cube*);

#define NO_STICKER 6

int cube_compare(const void *s1, const void *s2);

/**
 * Initializes cube with all stickers in place.
 */
cube full_cube(void);
/**
 * Initializes cube with no stickers except of centers.
 */
cube empty_cube(void);

void link(cube* cc, char* name);

#endif