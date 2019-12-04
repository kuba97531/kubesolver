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
/**
 * Adds corner orientation stickers to corners which aren't stickered yet.
 */
cube add_missing_corner_orientation(cube c);
/**
 * Adds all stickers to all corners.
 */
cube add_missing_corners(cube c);
/**
 * Adds edges orientation stickers to edges which aren't stickered yet. (so that the edges that can be solved with RULD)
 */
cube add_missing_edges_orientation(cube c);
/**
 * Adds all stickers to edges.
 */
cube add_missing_edges(cube c);
/**
 * Adds all stickers to F2L pieces.
 */
cube add_f2l(cube c);
/**
 * Adds all stickers to cross pieces (on the bottom).
 */
cube add_cross(cube c);

/**
 * Adds stickers to a single cross edge piece.
 */
cube add_cross_piece(cube c, int i);

/**
 * Adds all stickers to a given F2L slot.
 */
cube add_slot(cube c, int i);

void link(cube* cc, char* name);

#endif