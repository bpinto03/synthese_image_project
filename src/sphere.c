#include "../includes/sphere.h"


void draw_points_sphere(Shape *sphere, G3Xvector scale_factor){
    int stepx = scale_factor.x, stepy = scale_factor.y, k = 0;
    glBegin(GL_POINTS);
    for (int i = 0; i < sphere->n1; i += stepx) {
            for(int j = 0; j < sphere->n2; j += stepy){
                k = i * sphere->n1 + j;
                NormalVertex3dv(sphere->vrtx[k]);
            }
    }
    glEnd();
}

void draw_faces_sphere(Shape *sphere, G3Xvector scale_factor) {
    int stepx = scale_factor.x, stepy = scale_factor.y, k = 0;
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < sphere->n1; i += stepx) {
        for(int j = 0; j < sphere->n2; j += stepy){
            k = i * sphere->n1 + min(j + stepy, sphere->n2 - 1);
            NormalVertex3dv(sphere->vrtx[k]);
            k = (min(i + stepx, sphere->n1) % sphere->n1) * sphere->n1 + min(j + stepy, sphere->n2 - 1);
            NormalVertex3dv(sphere->vrtx[k]);
            k = i * sphere->n1 + j;
            NormalVertex3dv(sphere->vrtx[k]);

            k = i * sphere->n1 + j;
            NormalVertex3dv(sphere->vrtx[k]);
            k = (min(i + stepx, sphere->n1) % sphere->n1) * sphere->n1 + min(j + stepy, sphere->n2 - 1);
            NormalVertex3dv(sphere->vrtx[k]);
            k = (min(i + stepx, sphere->n1) % sphere->n1) * sphere->n1 + j;
            NormalVertex3dv(sphere->vrtx[k]);

        }
    }
    glEnd();
}

void init_sphere(Shape *s)
{
    int k = 0;
    double theta, phi;

    s->n1 = MAXRES;
    s->n2 = MAXRES;
    s->vrtx = (G3Xpoint*) calloc(s->n1 * s->n2, sizeof(G3Xpoint));
    s->norm = (G3Xvector*) calloc(s->n1 * s->n2, sizeof(G3Xvector));
    s->draw_faces = draw_faces_sphere;
    s->draw_points = draw_points_sphere;

    theta = 2 * PI / s->n1;
    phi = PI / s->n2;

    for (int i = 0; i < s->n1 ; i++) {
        for (int j = 0; j < s->n2; j++) {
            s->vrtx[i * s->n1 + j] = g3x_Point(R * cos(i * theta) * sin(j * phi),
                           R * sin(i * theta) * sin(j * phi),
                           R * cos(j * phi));
            s->norm[i * s->n1 + j] = (G3Xvector) { R * cos(i * theta) * sin(j * phi),
                           R * sin(i * theta) * sin(j * phi),
                           R * cos(j * phi)};
        }
    }
}