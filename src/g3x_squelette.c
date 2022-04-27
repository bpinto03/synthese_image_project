/*=================================================================*/
/*= E.Incerti - eric.incerti@univ-eiffel.fr                       =*/
/*= Université Gustave Eiffel                                     =*/
/*= Code "squelette" pour prototypage avec libg3x.6c              =*/
/*=================================================================*/

#include <g3x.h>
#include <math.h>

#include "../includes/utils.h"
#include "../includes/sphere.h"
#include "../includes/tore.h"
#include "../includes/cube.h"
#include "../includes/cylinder.h"
#include "../includes/node.h"


/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 512, WHEIGHT = 512;

static double step = 5.0;

static Shape sphere, tore, cube, cylinder;

static SceneTree tree;

static void init(void) {
    SceneTree child;
    g3x_SetPerspective(40.,100.,1.);
    g3x_SetCameraSpheric(0.25*PI,+0.25*PI,6.,(G3Xpoint){0.,0.,0.});
    g3x_SetLightAmbient (1.,1.,1.);
    g3x_SetLightDiffuse (1.,1.,1.);
    g3x_SetLightSpecular(1.,1.,1.);
    g3x_SetLightPosition (10.,10.,10.);

    /* Init of shapes */
    init_sphere(&sphere);
    init_tore(&tore);
    init_cube(&cube);
    init_cylinder(&cylinder);

    /* tree init */
    tree = createNode(g3x_Identity(), G3Xm, createMaterial(.2, .6, .9, 1.), (G3Xvector) {step, step, 1}, NULL);
    child = createNodeByParent(*tree, g3x_Homothetie3d(.5, 1, .04), &cube);
    addChild(tree, child);
    addNext(child, createNode(g3x_Mat_x_Mat(tree->Md, g3x_Mat_x_Mat(g3x_Translation3d(.35, .85, -0.5), g3x_Homothetie3d(.2, .2, 1.))), G3Xr, createMaterial(.2, .6, .9, 1.), (G3Xvector) {step, step, 1}, &cylinder));
}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void) {
    g3x_CreateScrollv_d("stepx", &step, 1, 10, 1, "Pas de rendu");
}

/* la fonction de dessin : appelée en boucle */
static void draw(void) {
    glPointSize(3);
    drawTree(tree, step);
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