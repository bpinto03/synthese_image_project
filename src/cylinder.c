#include "../includes/cylinder.h"

void draw_points_cylinder(Shape *cylinder, G3Xvector scale_factor){
    int stepx = scale_factor.x, stepy = scale_factor.y, k = 0;
    glBegin(GL_POINTS);
    for (int i = 0; i < cylinder->n1; i += stepx) {
            for(int j = 0; j < cylinder->n1; j += stepy){
                k = i * cylinder->n1 + j;
                NormalVertex3dv(cylinder->vrtx[k]);
            }
    }
    glEnd();
}

void draw_faces_cylinder(Shape *cylinder, G3Xvector scale_factor){
    int stepx = scale_factor.x, stepy = scale_factor.y, k = 0, l = 0;
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < cylinder->n1; i += stepx) {
        for (int j = 0; j < cylinder->n1; j += stepy) {
            k = i * cylinder->n1 + min(j + stepy, cylinder->n1 - 1);
            NormalVertex3dv(cylinder->vrtx[k]);
            k = (min(i + stepx, cylinder->n1) % cylinder->n1) * cylinder->n1 + min(j + stepy, cylinder->n1 - 1);
            NormalVertex3dv(cylinder->vrtx[k]);
            k = i * cylinder->n1 + j;
            NormalVertex3dv(cylinder->vrtx[k]);

            k = i * cylinder->n1 + j;
            NormalVertex3dv(cylinder->vrtx[k]);
            k = (min(i + stepx, cylinder->n1) % cylinder->n1) * cylinder->n1 + min(j + stepy, cylinder->n1 - 1);
            NormalVertex3dv(cylinder->vrtx[k]);
            k = (min(i + stepx, cylinder->n1) % cylinder->n1) * cylinder->n1 + j;
            NormalVertex3dv(cylinder->vrtx[k]);
            
        }
        
       /* for (int j = 0; j < cylinder->n2; j += stepy) {
            l = i * cylinder->n1 + min(j + stepy, cylinder->n2 - 1);
            NormalVertex3dv(cylinder->vrtx[l + k]);
            l = (min(i + stepx, cylinder->n1) % cylinder->n1) * cylinder->n1 + min(j + stepy, cylinder->n2 - 1);
            NormalVertex3dv(cylinder->vrtx[l + k]);
            l = i * cylinder->n1 + j;
            NormalVertex3dv(cylinder->vrtx[l + k]);

            l = i * cylinder->n1 + j;
            NormalVertex3dv(cylinder->vrtx[l + k]);
            l = (min(i + stepx, cylinder->n1) % cylinder->n1) * cylinder->n2 + min(j + stepy, cylinder->n2 - 1);
            NormalVertex3dv(cylinder->vrtx[l + k]);
            l = (min(i + stepx, cylinder->n1) % cylinder->n1) * cylinder->n2 + j;
            NormalVertex3dv(cylinder->vrtx[l + k]);
        }
        for (int j = 0; j < cylinder->n2; j += stepy) {


            NormalVertex3dv(cylinder->vrtx[i][min(j + step, NBC - 1)]);
            NormalVertex3dv(cylinder->vrtx[min(i + step, NBM) % NBM][min(j + step, NBC - 1)]);
            NormalVertex3dv(cylinder->vrtx[i][j]);

            NormalVertex3dv(cylinder->vrtx[i][j]);
            NormalVertex3dv(cylinder->vrtx[min(i + step, NBM) % NBM][min(j + step, NBC - 1)]);
            NormalVertex3dv(cylinder->vrtx[min(i + step, NBM) % NBM][j]);
        }*/
    }
    glEnd();
}


void init_cylinder(Shape *s){
    int k = 0, l = 0;
    double theta = 2 * PI / MAXRES;

    s->n1 = MAXRES;
    s->n2 = MAXCIRCLES;
    double t = H / (s->n1 - 1);
    double r = RCYL / (s->n2 - 1);
    s->vrtx = (G3Xpoint*) calloc(s->n1 * (s->n1 + 2 * s->n2), sizeof(G3Xpoint));
    s->norm = (G3Xvector*) calloc(s->n1 * (s->n1 + 2 * s->n2), sizeof(G3Xvector));
    s->draw_points = draw_points_cylinder;
    s->draw_faces = draw_faces_cylinder;

    // Base
    for (int i = 0; i < s->n1; i++) {
        for (int j = 0; j < s->n1; j++) {
            k = i * s->n1 + j;
            s->vrtx[k] = g3x_Point(RCYL * cos(i * theta),
                                               RCYL * sin(i * theta),
                                               (j * t) - (H / 2.));
        }

        for (int j = 0; j < s->n2; j++) {
            l = i * s->n1 + j;
            // Haut
            s->vrtx[l + k] = g3x_Point((j * r) * cos(i * theta),
                                    (j * r) * sin(i * theta),
                                    H / 2.);

            // Bas
            s->vrtx[l + k + s->n2 - 1] = g3x_Point((j * r) * cos(i * theta),
                                            (j * r) * sin(i * theta),
                                            -H / 2.);
        }
    }
}