#ifndef __cylinder__
#define __cylinder__

#define MAXCIRCLES 50                    // Nombre de cercles sur les bases

#include <g3x.h>
#include "shape.h"
#include <math.h>

static double H = 1;              // Hauteur du cylindre
static double RCYL = .5;             // Rayon du cylindre

void init_cylinder(Shape *s);

#endif