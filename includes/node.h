#ifndef __node__
#define __node__

#include "shape.h"
#include <g3x.h>

typedef struct _material{
    float ambi, diff, spec, shine;
} Material;

typedef struct _node_t{
    struct _node_t *down, *next; // chaînage
    G3Xhmat Md;                 // Matrice de transformation directe
    G3Xcolor col;               // couleur RGBA
    Material mat;               // 4 réels dans [0,1] : (ambi, diff, spec, shine)
    G3Xvector scale_factor;     // facteurs d'échelles locaux en x, y, z
    Shape *instance;            // une eventuelle instance d'objet
} Node, *SceneTree;

Material createMaterial(float ambi, float diff, float spec, float shine);

SceneTree createNode(G3Xhmat Md, G3Xcolor col, Material mat, G3Xvector scale_factor, Shape *instance);

SceneTree createNodeByParent(Node parentNode, G3Xhmat Md, Shape *instance);

void addChild(SceneTree tree, SceneTree child);

void addNext(SceneTree tree, SceneTree next);

void drawTree(SceneTree tree, int step);

#endif