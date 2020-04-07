#include <string.h>
#include <stdio.h>
#include "cube3r.h"

int oll_corners_colors[3] = {
    3/4, 12/4, 5/4
};

int corners[24] = {
    3, 12, 5,
    1, 16, 13,
    0, 20, 17,
    2, 4, 21,
    10, 19, 22,
    11, 15, 18,
    9, 7, 14,
    8, 23, 6
};

/* edges where first of two numbers is a face correctly oriented up in LRUD gen */
int edges[24] = {
    1, 12,
    0, 16,
    3, 20,
    2, 4,
    5, 15,
    19, 13,
    17, 23,
    7, 21,
    8, 6,
    9, 14,
    11, 22,
    10, 18
};


void get_edge_stickers_by_name(int* out, char *s) {
    for (int i=0; i<12; i++) {
        for (int j=0; j<2; j++) {
            if (!strcmp(s,edges_by_names[i][j])) { 
                    out[0] = edges_by_name_indexes[i][0];
                    out[1] = edges_by_name_indexes[i][1];
                return;
            }
        }
    }
    out[0] = -1;
    out[1] = -1;
    return;
}

cube add_edge(cube c, char* edge_name) {
    int edge[2];
    get_edge_stickers_by_name(edge, edge_name);
    cube cc = c;
    if (edge[0] != -1) {
        cc.edges[edge[0]] = edge[0] / 4;
        cc.edges[edge[1]] = edge[1] / 4;
    }
    return cc;    
}

void get_corner_stickers_by_name(int* out, char *s) {
    for (int i=0; i<8; i++) {
        for (int j=0; j<6; j++) {
            if (!strcmp(s, corners_by_names[i][j])) { 
                    out[0] = corners_by_name_indexes[i][0];
                    out[1] = corners_by_name_indexes[i][1];
                    out[2] = corners_by_name_indexes[i][2];
                return;
            }
        }
    }
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    return;
}

cube add_corner(cube c, char* corner_name) {
    int corner[3];
    get_corner_stickers_by_name(corner, corner_name);
    cube cc = c;
    if (corner[0] != -1) {
        cc.corners[corner[0]] = corner[0] / 4;
        cc.corners[corner[1]] = corner[1] / 4;
        cc.corners[corner[2]] = corner[2] / 4;
    }
    return cc;    
}

/**
 * Adds corner orientation stickers to corners which aren't stickered yet.
 * Implementation detail: in theory we could only color one sticker of a corner and leave others NO_STICKER
 * But to fit cube packed representation in 128 bits we forget colors of the stickers in the top layer because they can be guessed,
 * but this only works if seeing two sides of a corner determines the color of the third.
 * And if for corner orientation we would only color one sticker, than NO_STICKER, NO_STICKER, ? would be ambigous.
 */
cube add_missing_corner_orientation(cube c) {
    cube cc = c;
    for (int i=0; i<24; i+=3) {
        if (c.corners[corners[i]] == NO_STICKER) {
            for (int k=0; k<3; k++) {
                cc.corners[corners[i + k]] = oll_corners_colors[k];
            }
        }
    }
    return cc;
}
/**
 * Adds all stickers to all corners.
 */
cube add_missing_corners(cube c) {
    cube cc = c;
    for (int i=0; i<24; i+=3) {
        if (c.corners[corners[i]] == NO_STICKER) {
            for (int k=0; k<3; k++) {
                cc.corners[corners[i + k]] = corners[i + k] / 4;
            }
        }
    }
    return cc;
}

/**
 * Adds edges orientation stickers to edges which aren't stickered yet. (so that the edges that can be solved with RULD)
 */
cube add_missing_edges_orientation(cube c) {
    cube cc = c;
    for (int i=0; i<24; i+=2) {
        if (c.edges[edges[i]] == NO_STICKER) {
            cc.edges[edges[i]] = 0;
        }
    }
    return cc;
}

/**
 * Adds all stickers to edges.
 */
cube add_missing_edges(cube c) {
    cube cc = c;
    for (int i=0; i<24; i+=2) {
        if (c.edges[edges[i]] == NO_STICKER) {
            cc.edges[edges[i]] = edges[i] / 4;
            cc.edges[edges[i + 1]] = edges[i + 1] / 4;
        }
    }
    return cc;
}
