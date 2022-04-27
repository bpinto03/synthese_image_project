#include "../includes/node.h"

Material createMaterial(float ambi, float diff, float spec, float shine) {
    Material mat;

    mat.ambi  =  ambi;
    mat.diff  = diff;
    mat.spec  = spec;
    mat.shine = shine;
    
    return mat;
}

SceneTree createNode(G3Xhmat Md, G3Xcolor col, Material mat, G3Xvector scale_factor, Shape *instance){
    SceneTree newNode;
    newNode = (SceneTree) malloc(sizeof(Node));

    newNode->Md           = Md;
    newNode->col          = col;
    newNode->mat          = mat;
    newNode->scale_factor = scale_factor;
    newNode->instance     = instance;
    newNode->down         = NULL;
    newNode->next         = NULL;
    return newNode;
}

SceneTree createNodeByParent(Node parentNode, G3Xhmat Md, Shape *instance){
    SceneTree newNode;
    newNode = (SceneTree) malloc(sizeof(Node));

    newNode->Md           = g3x_Mat_x_Mat(parentNode.Md, Md);
    newNode->col          = parentNode.col;
    newNode->mat          = parentNode.mat;
    newNode->scale_factor = parentNode.scale_factor;
    newNode->instance     = instance;
    newNode->down         = NULL;
    newNode->next         = NULL;

    return newNode;
}

void addChild(SceneTree tree, SceneTree child){
    tree->down = child;
}

void addNext(SceneTree tree, SceneTree next){
    tree->next = next;
}

void drawTree(SceneTree tree, int step) {
    if(tree == NULL) {
        return;
    }

    g3x_Material(tree->col, tree->mat.ambi, tree->mat.diff, tree->mat.spec, tree->mat.shine, 1);
    glPushMatrix();
    glMultMatrixd(tree->Md.m);

    if(tree->instance != NULL) {
        tree->scale_factor = (G3Xvector) {step, step, 1};
        tree->instance->draw_faces(tree->instance, tree->scale_factor);
    }

    drawTree(tree->down, step);
    glPopMatrix();
    drawTree(tree->next, step);
}