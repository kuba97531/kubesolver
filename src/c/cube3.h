#include <stdint.h>

#ifndef CUBE3
#define CUBE3
typedef struct {
    uint8_t edges[24];
    uint8_t corners[24];
} cube;

typedef cube (*t_rotation)(cube*);

int cube_compare(const void *s1, const void *s2);

cube empty_cube(void);
cube empty_cube_oll(void);
cube empty_cube_f2l(void);
cube empty_cube_cross(void);
cube init_slot(cube c, int i);
void link(cube* cc, char* name);

#endif