#include "cube3.h"
#include <stdio.h>
#include <assert.h>

int cube_compare(const void *s1, const void *s2)
    {
      cube *c1 = (cube *)s1;
       cube *c2 = (cube *)s2;
      for (int i=0; i<24; i++) {
          if (c1->edges[i] != c2->edges[i]) {
              return c1->edges[i] - c2->edges[i];
          }
      }
      for (int i=0; i<24; i++) {
                    if (c1->corners[i] != c2->corners[i]) {
              return c1->corners[i] - c2->corners[i];
          }
      }
      return 0;
    }

void pp1(cube* cc) {
   cube c = *cc;
   char x[] = "wgyrboz";
   fprintf(stderr,"http://software.rubikscube.info/icube/icube.php?size=100&stickers=");
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c", x[c.corners[0]], x[c.edges[0]], x[c.corners[1]], x[c.edges[3]], 'w', x[c.edges[1]], x[c.corners[2]], x[c.edges[2]], x[c.corners[3]]);
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c", x[c.corners[4]], x[c.edges[4]], x[c.corners[5]], x[c.edges[7]], 'g', x[c.edges[5]], x[c.corners[6]], x[c.edges[6]], x[c.corners[7]]);
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c", x[c.corners[12]], x[c.edges[12]], x[c.corners[13]], x[c.edges[15]], 'r', x[c.edges[13]], x[c.corners[14]], x[c.edges[14]], x[c.corners[15]]);
}
void pp2(cube* cc) {
   cube c = *cc;
   char x[] = "wgyrboz";
   fprintf(stderr,"http://software.rubikscube.info/icube/icube.php?size=100&m=xy&fl=");
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c", x[c.corners[9]], x[c.edges[9]], x[c.corners[11]], x[c.edges[8]], 'y', x[c.edges[10]], x[c.corners[8]], x[c.edges[11]], x[c.corners[10]]);
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c", x[c.corners[23]], x[c.edges[22]], x[c.corners[22]], x[c.edges[21]], 'o', x[c.edges[23]], x[c.corners[21]], x[c.edges[20]], x[c.corners[20]]);
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c", x[c.corners[19]], x[c.edges[18]], x[c.corners[18]], x[c.edges[17]], 'b', x[c.edges[19]], x[c.corners[17]], x[c.edges[16]], x[c.corners[16]]);
}

void pp3(cube* cc) {
   char x[] = "wgyrboz";
   cube c = *cc;
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c ", x[c.corners[0]], x[c.edges[0]], x[c.corners[1]], x[c.edges[3]], 'w', x[c.edges[1]], x[c.corners[2]], x[c.edges[2]], x[c.corners[3]]);
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c ", x[c.corners[4]], x[c.edges[4]], x[c.corners[5]], x[c.edges[7]], 'g', x[c.edges[5]], x[c.corners[6]], x[c.edges[6]], x[c.corners[7]]);
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c ", x[c.corners[12]], x[c.edges[12]], x[c.corners[13]], x[c.edges[15]], 'r', x[c.edges[13]], x[c.corners[14]], x[c.edges[14]], x[c.corners[15]]);
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c ", x[c.corners[9]], x[c.edges[9]], x[c.corners[11]], x[c.edges[8]], 'y', x[c.edges[10]], x[c.corners[8]], x[c.edges[11]], x[c.corners[10]]);
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c ", x[c.corners[23]], x[c.edges[22]], x[c.corners[22]], x[c.edges[21]], 'o', x[c.edges[23]], x[c.corners[21]], x[c.edges[20]], x[c.corners[20]]);
    fprintf(stderr,"%c%c%c%c%c%c%c%c%c\n", x[c.corners[19]], x[c.edges[18]], x[c.corners[18]], x[c.edges[17]], 'b', x[c.edges[19]], x[c.corners[17]], x[c.edges[16]], x[c.corners[16]]);
}

void link(cube* cc, char* name) {
    fprintf(stderr,"<br><img src=\"");
    pp1(cc);
    fprintf(stderr,"\" />\n");
    fprintf(stderr,"<img src=\"");
    pp2(cc);
    fprintf(stderr,"\" /> %s <br> \n", name);
}

/**
 * Initializes cube with all stickers in place.
 */
cube full_cube(void) {
    cube c;
    for (int i = 0; i< 24; i++) {
        c.edges[i] = c.corners[i] = i/4;
    }
    return c;
}
/**
 * Initializes cube with no stickers except of centers.
 */
cube empty_cube(void){
    cube c;
    for (int i = 0; i< 24; i++) {
        c.edges[i] = c.corners[i] = NO_STICKER;
    }
    return c;
}


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

int cross_edges[8] = {
    8, 6,
    9, 14,
    10, 18,
    11, 22
};

//slot[] = corner, corner, corner, edge, edge
int slot1[5] = { 7, 9, 14, 5, 15 };
int slot2[5] = { 8, 6, 23, 21, 7 };
int slot3[5] = { 11, 15, 18, 13, 19 };
int slot4[5] = { 10, 19, 22, 17, 23 };

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
/**
 * Adds all stickers to F2L pieces.
 */
cube add_f2l(cube c) {
    cube cc = c;
    cc = add_cross(cc);
    for (int i=1; i<=4; i++) {
        cc = add_slot(cc, i);
    }
    return cc;
}
/**
 * Adds all stickers to cross pieces (on the bottom).
 */
cube add_cross(cube c) {
    cube cc = c;
    for (int i = 0; i < 8; i++) {
        int e = cross_edges[i];
        cc.edges[e] = e/4;
    }   
    return cc;
}

cube add_cross_piece(cube c, int i) {
    cube cc = c;
    for (int k = 0; k < 2; k++) {
        int e = cross_edges[2 * i + k];
        cc.edges[e] = e/4;
    }
    return cc;
}
/**
 * Adds all stickers to a given F2L slot.
 */
cube add_slot(cube c, int ii) {
    cube cc = c;
    int *slot;
    assert(ii >=1 && ii <=4);
    if (ii == 1) slot = slot1;
    if (ii == 2) slot = slot2;
    if (ii == 3) slot = slot3;
    if (ii == 4) slot = slot4;
    for (int i=0; i<3; i++) {
        int x = slot[i];
        cc.corners[x] = x/4;
    }
    for (int i=3; i<5; i++) {
        int x = slot[i];
        cc.edges[x] = x/4;
    }
    return cc;
}


