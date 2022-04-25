#ifndef __shape__
#define __shape__

#include <g3x.h>

#define MAXRES 100

typedef struct _shape_
{
    int n1, n2, n3;
    G3Xpoint *vrtx;
    G3Xvector *norm;

    void (*draw_points)(struct _shape_*, G3Xvector scale_factor);
    void (*draw_faces)(struct _shape_*, G3Xvector scale_factor);
} Shape;


#endif