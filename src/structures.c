#include "../includes/structures.h"

SceneTree createTable(G3Xhmat Md, Shape *cylinder, Shape *cube) {
    SceneTree paramTable, plat, paramFoot, foot1, foot2, foot3, foot4;
    
    // Parameters for table object
    paramTable = createNode(Md, marron1, createMaterial(.2, .6, .9, 1.), (G3Xvector) {3, 3, 1.}, NULL);
    // Up of table
    plat = createNodeByParent(*paramTable, g3x_Homothetie3d(.5, 1, .04), cube);
    addChild(paramTable, plat);

    // Parameters for table foots.
    paramFoot = createNode(g3x_Mat_x_Mat(paramTable->Md, g3x_Homothetie3d(.30, .30, 1.)), metal, paramTable->mat, paramTable->scale_factor, NULL);
    addNext(plat, paramFoot);

    // Foots of table
    foot1 = createNodeByParent(*paramFoot, g3x_Translation3d(4., 10., -0.5), cylinder);
    addChild(paramFoot, foot1);
    foot2 = createNodeByParent(*paramFoot, g3x_Translation3d(-4., 10., -0.5), cylinder);
    addNext(foot1, foot2);
    foot3 = createNodeByParent(*paramFoot, g3x_Translation3d(4., -10., -0.5), cylinder);
    addNext(foot2, foot3);
    foot4 = createNodeByParent(*paramFoot, g3x_Translation3d(-4, -10, -0.5), cylinder);
    addNext(foot3, foot4);

    return paramTable;
}