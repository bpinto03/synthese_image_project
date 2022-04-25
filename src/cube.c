#include "../includes/cube.h"

void draw_points_cube(Shape *cube, G3Xvector scale_factor){
    int stepx = scale_factor.x, stepy = scale_factor.y, k = 0;
    glBegin(GL_POINTS);
    for(int f = 0; f < 6; f++) {
        for (int i = 0; i < cube->n1; i += stepx) {
                for(int j = 0; j < cube->n1; j += stepy){
                    k = i * cube->n1 + j;
                    NormalVertex3dv(cube->vrtx[k + (cube->n1 * cube->n1 * f)]);
                }
        }
    }
    glEnd();
}

void draw_faces_cube(Shape *cube, G3Xvector scale_factor) {
    int stepx = scale_factor.x, stepy = scale_factor.y;
    glBegin(GL_QUADS);
    for(int f = 0; f < 6; f++) {
        for (int i = 0; i < cube->n1; i += stepx) {
                for(int j = 0; j < cube->n1; j += stepy){
                    int k;
                    k = (i)*cube->n1 + (j);
                    NormalVertex3dv(cube->vrtx[k + (cube->n1 * cube->n1 * f)]);

                    k = (i)*cube->n1 + min(j + stepy, cube->n1 - 1);
                    NormalVertex3dv(cube->vrtx[k + (cube->n1 * cube->n1 * f)]);

                    k = min(i + stepx, cube->n1 - 1) * cube->n1 + min(j + stepy, cube->n1 - 1);
                    NormalVertex3dv(cube->vrtx[k + (cube->n1 * cube->n1 * f)]);

                    k = min(i + stepx, cube->n1 - 1) * cube->n1 + (j);
                    NormalVertex3dv(cube->vrtx[k + (cube->n1 * cube->n1 * f)]);
                }
        }
    }
    glEnd();
}

void init_cube(Shape *s){
    int k = 0;

    s->n1 = MAXRES;
    s->vrtx = (G3Xpoint*) calloc(s->n1 * s->n1 * 6, sizeof(G3Xpoint));
    s->norm = (G3Xvector*) calloc(s->n1 * s->n1 * 6, sizeof(G3Xvector));
    s-> draw_points = draw_points_cube;
    s->draw_faces = draw_faces_cube;

    double y, x, dy = 2. / (s->n1 - 1), dx = 2. / (s->n1 - 1);
    int i;
    int j;
    for (i = 0; i < s->n1 - 1; i++)
    {
        for (j = 0; j < s->n1 - 1; j++)
        {
            s->vrtx[i * s->n1 + j] = (G3Xpoint){(-1. + j * dx), (-1. + i * dy), 1.};
            s->vrtx[(s->n1 * s->n1) + (i * s->n1 + j)] = (G3Xpoint){(-1. + j * dx), (-1. + i * dy), -1.};

            s->vrtx[(s->n1 * s->n1)*2 + (i * s->n1 + j)] = (G3Xpoint){(-1. + j * dx), 1., (-1. + i * dy)};
            s->vrtx[(s->n1 * s->n1)*3 + (i * s->n1 + j)] = (G3Xpoint){(-1. + j * dx), -1., (-1. + i * dy)};

            s->vrtx[(s->n1 * s->n1)*4 + (i * s->n1 + j)] = (G3Xpoint){1., (-1. + i * dy), (-1. + j * dx)};
            s->vrtx[(s->n1 * s->n1)*5 + (i * s->n1 + j)] = (G3Xpoint){-1., (-1. + i * dy), (-1. + j * dx)};
        }
        j = s->n1 - 1;
        s->vrtx[i * s->n1 + j] = (G3Xpoint){+1, (-1. + i * dy), 1.};
        s->vrtx[(s->n1 * s->n1) + (i * s->n1 + j)] = (G3Xpoint){+1, (-1. + i * dy), -1.};

        s->vrtx[(s->n1 * s->n1)*2 + (i * s->n1 + j)] = (G3Xpoint){+1, 1., (-1. + i * dy)};
        s->vrtx[(s->n1 * s->n1)*3 + (i * s->n1 + j)] = (G3Xpoint){+1, -1., (-1. + i * dy)};

        s->vrtx[(s->n1 * s->n1)*4 + (i * s->n1 + j)] = (G3Xpoint){1., (-1. + i * dy), +1};
        s->vrtx[(s->n1 * s->n1)*5 + (i * s->n1 + j)] = (G3Xpoint){-1., (-1. + i * dy), +1};
    }

    i = s->n1 - 1;

    for (j = 0; j < s->n1 - 1; j++)
    {
        s->vrtx[i * s->n1 + j] = (G3Xpoint){(-1. + j * dx), +1, 1.};
        s->vrtx[(s->n1 * s->n1) + (i * s->n1 + j)] = (G3Xpoint){(-1. + j * dx), +1, -1.};

        s->vrtx[(s->n1 * s->n1)*2 + (i * s->n1 + j)] = (G3Xpoint){(-1. + j * dx), 1., +1};
        s->vrtx[(s->n1 * s->n1)*3 + (i * s->n1 + j)] = (G3Xpoint){(-1. + j * dx), -1., +1};

        s->vrtx[(s->n1 * s->n1)*4 + (i * s->n1 + j)] = (G3Xpoint){1., +1, (-1. + j * dx)};
        s->vrtx[(s->n1 * s->n1)*5 + (i * s->n1 + j)] = (G3Xpoint){-1., +1, (-1. + j * dx)};
    }
    j = s->n1 - 1;
    s->vrtx[i * s->n1 + j] = (G3Xpoint){+1, +1, 1.};
    s->vrtx[(s->n1 * s->n1) + (i * s->n1 + j)] = (G3Xpoint){+1, +1, -1.};

    s->vrtx[(s->n1 * s->n1)*2 + (i * s->n1 + j)] = (G3Xpoint){+1, 1., +1};
    s->vrtx[(s->n1 * s->n1)*3 + (i * s->n1 + j)] = (G3Xpoint){+1, -1., +1};

    s->vrtx[(s->n1 * s->n1)*4 + (i * s->n1 + j)] = (G3Xpoint){1., +1, +1};
    s->vrtx[(s->n1 * s->n1)*5 + (i * s->n1 + j)] = (G3Xpoint){-1., +1, +1};
}