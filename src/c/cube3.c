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

