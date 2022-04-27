/*=================================================================*/
/*= E.Incerti - eric.incerti@univ-eiffel.fr                       =*/
/*= Université Gustave Eiffel                                     =*/
/*= Code "squelette" pour prototypage avec libg3x.6c              =*/
/*=================================================================*/

#include <g3x.h>
#include <math.h>

#include "../includes/utils.h"
#include "../includes/sphere.h"
#include "../includes/torus.h"
#include "../includes/cube.h"
#include "../includes/cylinder.h"
#include "../includes/node.h"
#include "../includes/structures.h"


/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 512, WHEIGHT = 512;

static double step = 3.0;

static Shape sphere, torus, cube, cylinder;

static SceneTree table1, table2;

static void init(void) {
    g3x_SetPerspective(40.,100.,1.);
    g3x_SetCameraSpheric(0.25*PI,+0.25*PI,6.,(G3Xpoint){0.,0.,0.});
    g3x_SetLightAmbient (1.,1.,1.);
    g3x_SetLightDiffuse (1.,1.,1.);
    g3x_SetLightSpecular(1.,1.,1.);
    g3x_SetLightPosition (10.,10.,10.);

    /* Init of shapes */
    init_sphere(&sphere);
    init_torus(&torus);
    init_cube(&cube);
    init_cylinder(&cylinder);

    /* tree init */
    table1 = createTable(g3x_Translation3d(0., 0., 0.), &cylinder, &cube);
    table2 = createTable(g3x_Translation3d(0., 0., 1.), &cylinder, &cube);

}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void) {
    g3x_CreateScrollv_d("stepx", &step, 1, 10, 1, "Pas de rendu");
}

/* la fonction de dessin : appelée en boucle */
static void draw(void) {
    glPointSize(3);
    drawTree(table1);
    //drawTree(table2);
}

/* la fonction d'animation (facultatif) */
static void anim(void) {
}

/* la fonction de sortie  (facultatif) -- atexit() */
static void quit(void) {
}

/***************************************************************************/
/* La fonction principale : NE CHANGE JAMAIS ou presque                    */
/***************************************************************************/
int main(int argc, char **argv) {
    /* creation de la fenetre - titre et tailles (pixels) */
    g3x_InitWindow(*argv, WWIDTH, WHEIGHT);

    g3x_SetInitFunction(init); /* fonction d'initialisation */
    g3x_SetCtrlFunction(ctrl); /* fonction de contrôle      */
    g3x_SetDrawFunction(draw); /* fonction de dessin        */
    g3x_SetAnimFunction(anim); /* fonction d'animation      */
    g3x_SetExitFunction(quit); /* fonction de sortie        */

    /* lancement de la boucle principale */
    return g3x_MainStart();
    /* RIEN APRES CA */
}