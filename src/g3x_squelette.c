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
    init_sphere(&sphere);
    init_tore(&tore);
    init_cube(&cube);
    init_cylinder(&cylinder);
    printf("%p\n", tree);
    tree = createNode(g3x_Identity(), G3Xr, createMaterial(1., 1., 1., 1.), (G3Xvector) {step, step, 1}, NULL);
    addChild(tree, createNodeByParent(*tree, &sphere));
}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void) {
    g3x_CreateScrollv_d("stepx", &step, 1, 10, 1, "Pas de rendu");
}

/* la fonction de dessin : appelée en boucle */
static void draw(void) {
    glPointSize(3);
    g3x_Material(G3Xr, .2, .6, .9, 1, 1);

    tree->down->instance->draw_faces(tree->down->instance, tree->down->scale_factor);
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