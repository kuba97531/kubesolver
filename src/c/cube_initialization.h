#include "cube3r.h"
#ifndef CUBE_INITIALIZATION


/**
 * Adds stickers to a particular edge described as two upcase letters. e.g. LB
 */
cube add_edge(cube c, char* edge_name);
/**
 * Adds stickers to a particular corner described as three upcase letters. e.g. RFU
 */
cube add_corner(cube c, char* corner_name);
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

cube add_domino_elements(cube c);
#endif