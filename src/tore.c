#include "../includes/tore.h"

void draw_points_tore(Shape *tore, G3Xvector scale_factor){
    int stepx = scale_factor.x, stepy = scale_factor.y, k = 0;
    glBegin(GL_POINTS);
    for (int i = 0; i < tore->n1; i += stepx) {
            for(int j = 0; j < tore->n2; j += stepy){
                k = i * tore->n1 + j;
                NormalVertex3dv(tore->vrtx[k]);
            }
    }
    glEnd();
}

void draw_faces_tore(Shape *tore, G3Xvector scale_factor){
    int stepx = scale_factor.x, stepy = scale_factor.y, k = 0;

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < tore->n1; i += stepx) {
        for(int j = 0; j < tore->n2; j += stepy){
            k = i * tore->n1 + min(j + stepy, tore->n2 - 1);
            NormalVertex3dv(tore->vrtx[k]);
            k = (min(i + stepx, tore->n1) % tore->n1) * tore->n1 + min(j + stepy, tore->n2);
            NormalVertex3dv(tore->vrtx[k]);
            k = i * tore->n1 + j;
            NormalVertex3dv(tore->vrtx[k]);

            k = i * tore->n1 + j;
            NormalVertex3dv(tore->vrtx[k]);
            k = (min(i + stepx, tore->n1) % tore->n1) * tore->n1 + min(j + stepy, tore->n2);
            NormalVertex3dv(tore->vrtx[k]);
            k = (min(i + stepx, tore->n1) % tore->n1) * tore->n1 + j;
            NormalVertex3dv(tore->vrtx[k]);

        }
    }
    glEnd();
}

void init_tore(Shape *s)
{
    int k = 0;
    double theta, phi, RI = 0.5, R = 1.0;

    s->n1 = MAXRES;
    s->n2 = MAXRES;
    s->vrtx = (G3Xpoint*) calloc(s->n1 * s->n2, sizeof(G3Xpoint));
    s->norm = (G3Xvector*) calloc(s->n1 * s->n2, sizeof(G3Xvector));
    s-> draw_faces = draw_faces_tore;
    s-> draw_points = draw_points_tore;

    theta = 2 * PI / s->n1;
    phi = 2 * PI / s->n2;

    for (int i = 0; i < s->n1 ; i++) {
        for (int j = 0; j < s->n2; j++) {
            s->vrtx[i * s->n1 + j] = g3x_Point(g3x_Radcos(i * theta) * (R + RI * g3x_Radcos(j * phi)),
                                   -1 * g3x_Radsin(i * theta) * (R + RI * g3x_Radcos(j * phi)),
                                   RI * g3x_Radsin(j * phi));
        }
    }
}