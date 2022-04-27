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

SceneTree createNodeByParent(Node parentNode, Shape *instance){
    SceneTree newNode;
    newNode = (SceneTree) malloc(sizeof(Node));

    newNode->Md           = parentNode.Md;
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