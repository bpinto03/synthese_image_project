#ifndef __structure__
#define __structure__

#include <g3x.h>
#include "shape.h"
#include "node.h"

static G3Xcolor marron1={0.30,0.20,0.10,0.00};
static G3Xcolor marron2={0.50,0.40,0.20,0.00};
static G3Xcolor rouge  ={1.00,0.00,0.00,0.00};
static G3Xcolor vert   ={0.00,1.00,0.00,0.00};
static G3Xcolor bleu   ={0.00,0.00,1.00,0.00};
static G3Xcolor jaune  ={1.00,1.00,0.00,0.00};
static G3Xcolor cyan   ={0.00,1.00,1.00,0.00};
static G3Xcolor orange ={0.75,0.50,0.00,0.00};
static G3Xcolor vert2  ={0.50,0.75,0.00,0.00};
static G3Xcolor metal  ={0.60,0.75,0.95,0.00};
static G3Xcolor glass  ={0.90,0.90,1.00,0.00};

SceneTree createTable(G3Xhmat Md, Shape *cylinder, Shape *cube);
#endif