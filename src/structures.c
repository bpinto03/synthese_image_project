#include "../includes/structures.h"

/* Soucis de décalage quand la matrice de base n'es pas l'identité. */
/*SceneTree createTable(G3Xhmat Md, Shape *cylinder, Shape *cube) {
    SceneTree paramTable, plat, paramFoot, foot1, foot2, foot3, foot4;
    G3Xpoint centerOfObject;
    
    centerOfObject = g3x_Mat_x_Point(Md, (G3Xpoint) {0, 0, 0.});
    // Parameters for table object
    printf("ParamTable\n");
    paramTable = createNode(Md, marron1, createMaterial(.2, .6, .9, 1.), (G3Xvector) {3, 3, 1.}, NULL);
    // Up of table
    printf("plat\n");
    plat = createNodeByParent(*paramTable, g3x_Homothetie3d(.5, 1, .04), cube);
    addChild(paramTable, plat);

    // Parameters for table foots.
    printf("paramfoot\n");
    paramFoot = createNode(g3x_Mat_x_Mat(paramTable->Md, g3x_Homothetie3d(.30, .30, 1.)), metal, paramTable->mat, paramTable->scale_factor, NULL);
    addNext(plat, paramFoot);

    // Foots of table
    printf("Foot1\n");
    foot1 = createNodeByParent(*paramFoot, g3x_Translation3d(centerOfObject.x - 8. * 0.3, -(10 + centerOfObject.y), -(0.5 + centerOfObject.z)), cylinder);
    addChild(paramFoot, foot1);
    printf("Foot2\n");
    foot2 = createNodeByParent(*paramFoot, g3x_Translation3d(centerOfObject.x + 8. * 0.3,  -(10 + centerOfObject.y), -(0.5 + centerOfObject.z)), cylinder);
    addNext(foot1, foot2);
    printf("Foot3\n");
    foot3 = createNodeByParent(*paramFoot, g3x_Translation3d(-(4. + centerOfObject.x), -(-10 + centerOfObject.y), -(0.5 + centerOfObject.z)), cylinder);
    addNext(foot2, foot3);
    printf("Foot4\n");
    foot4 = createNodeByParent(*paramFoot, g3x_Translation3d(-(-4. + centerOfObject.x), -(-10 + centerOfObject.y), -(0.5 + centerOfObject.z)), cylinder);
    addNext(foot3, foot4);

    return paramTable;
}*/

SceneTree createTable1(Shape *cube, Shape *cylinder) {
    SceneTree paramTable, plat, paramFoot, foot1, foot2, foot3, foot4;

    G3Xpoint centerOfObject;

    // Parameters for table object
    // g3x_Mat_x_Mat(, g3x_RotationZ(30))
    paramTable = createNode(g3x_Mat_x_Mat(g3x_Translation3d(0., 0., .5), g3x_RotationZ(-30)), marron1, createMaterial(.2, .6, .9, 1.), (G3Xvector) {2., 2., 1.}, NULL);
    
    // Up of table
    plat = createNodeByParent(*paramTable, g3x_Homothetie3d(.5, 1, .1), cube);
    addChild(paramTable, plat);

    // Parameters for table foots.
    paramFoot = createNode(g3x_Mat_x_Mat(paramTable->Md, g3x_Homothetie3d(.30, .30, 1.)), metal, paramTable->mat, paramTable->scale_factor, NULL);
    addNext(plat, paramFoot);

    // Foots of table
    foot1 = createNodeByParent(*paramFoot,g3x_Translation3d(9., 6., -1.), cylinder);
    addChild(paramFoot, foot1);
    foot2 = createNodeByParent(*paramFoot, g3x_Translation3d(10., -3, -1.), cylinder);
    addNext(foot1, foot2);
    foot3 = createNodeByParent(*paramFoot, g3x_Translation3d(-10., 3, -1.), cylinder);
    addNext(foot2, foot3);
    foot4 = createNodeByParent(*paramFoot, g3x_Translation3d(-9., -6., -1.), cylinder);
    addNext(foot3, foot4);

    return paramTable;
}

SceneTree createTable2(Shape *cube, Shape *cylinder) {
    SceneTree paramTable, plat, paramFoot, foot1, foot2, foot3, foot4;

    G3Xpoint centerOfObject;

    // Parameters for table object
    // g3x_Mat_x_Mat(, g3x_RotationZ(30))
    paramTable = createNode(g3x_Mat_x_Mat(g3x_Translation3d(2.5, 8, .5), g3x_RotationZ(60)), marron1, createMaterial(.2, .6, .9, 1.), (G3Xvector) {2., 2., 1.}, NULL);

    // Up of table
    plat = createNodeByParent(*paramTable, g3x_Homothetie3d(.5, 1, .1), cube);
    addChild(paramTable, plat);

    // Parameters for table foots.
    paramFoot = createNode(g3x_Mat_x_Mat(paramTable->Md, g3x_Homothetie3d(.30, .30, 1.)), metal, paramTable->mat, paramTable->scale_factor, NULL);
    addNext(plat, paramFoot);

    // Foots of table
    foot1 = createNodeByParent(*paramFoot,g3x_Translation3d(22., 31., -1.), cylinder);
    addChild(paramFoot, foot1);
    foot2 = createNodeByParent(*paramFoot, g3x_Translation3d(17., 13, -1.), cylinder);
    addNext(foot1, foot2);
    foot3 = createNodeByParent(*paramFoot, g3x_Translation3d(9., 15, -1.), cylinder);
    addNext(foot2, foot3);
    foot4 = createNodeByParent(*paramFoot, g3x_Translation3d(14., 32., -1.), cylinder);
    addNext(foot3, foot4);

    return paramTable;
}

SceneTree createGround(Shape *cube){
    SceneTree whiteGround, greyGround, ground1, ground2, ground3, ground4, ground5, ground6;

    // Parameters of ground
    whiteGround = createNode(g3x_Mat_x_Mat(g3x_Homothetie3d(1., 1., 0.01), g3x_Translation3d(0., 0., -0.5)),
                             blanc, createMaterial(.2, .6, .9, 1.), (G3Xvector) {2., 2., 1.}, NULL);
    greyGround = createNode(whiteGround->Md, gris, whiteGround->mat, whiteGround->scale_factor, NULL);
    addNext(whiteGround, greyGround);

    // White grounds
    ground1 = createNodeByParent(*whiteGround, g3x_Translation3d(-1, -1, 0.), cube);
    addChild(whiteGround, ground1);
    ground2 = createNodeByParent(*whiteGround, g3x_Translation3d(1., 1., 0.), cube);
    addNext(ground1, ground2);
    ground6 = createNodeByParent(*whiteGround, g3x_Translation3d(3., -1., 0.), cube);
    addNext(ground2, ground6);

    // Grey grounds
    ground3 = createNodeByParent(*greyGround, g3x_Translation3d(-1, 1, 0.), cube);
    addChild(greyGround, ground3);
    ground4 = createNodeByParent(*greyGround, g3x_Translation3d(1., -1., 0.), cube);
    addNext(ground3, ground4);
    ground5 = createNodeByParent(*greyGround, g3x_Translation3d(3., 1., 0.), cube);
    addNext(ground4, ground5);

    return whiteGround;
}

SceneTree createStool1(Shape *cube, Shape *cylinder) {
    SceneTree paramStool, paramFoot, flat, foot1, foot2, foot3, foot4;

    // g3x_Mat_x_Mat(g3x_Translation3d(2.5, 8, .5), g3x_RotationZ(60))
    paramStool = createNode(g3x_Translation3d(0., 0.25, .57), marron2, createMaterial(.2, .6, .9, 1.), (G3Xvector) {2., 2., 2.}, NULL);

    // Up of table
    flat = createNodeByParent(*paramStool, g3x_Homothetie3d(1., 1., .1), cylinder);
    addChild(paramStool, flat);

    // Parameters for table foots.
    paramFoot = createNode(g3x_Mat_x_Mat(paramStool->Md, g3x_Homothetie3d(.20, .20, .75)), metal, paramStool->mat, (G3Xvector) {5., 5., 2.}, NULL);
    addNext(flat, paramFoot);

    // Foots of table
    foot1 = createNodeByParent(*paramFoot,g3x_Translation3d(7, 7, .33), cube);
    addChild(paramFoot, foot1);
    foot2 = createNodeByParent(*paramFoot, g3x_Translation3d(-7., -7., .33), cube);
    addNext(foot1, foot2);
    foot3 = createNodeByParent(*paramFoot, g3x_Translation3d(7., -7., .33), cube);
    addNext(foot2, foot3);
    foot4 = createNodeByParent(*paramFoot, g3x_Translation3d(-7., 7., .33), cube);
    addNext(foot3, foot4);

    return paramStool;
}

SceneTree createStool2(Shape *cube, Shape *cylinder) {
    SceneTree paramStool, paramFoot, flat, foot1, foot2, foot3, foot4;

    // g3x_Mat_x_Mat(g3x_Translation3d(2.5, 8, .5), g3x_RotationZ(60))
    paramStool = createNode(g3x_Translation3d(0., 1., .40), marron2, createMaterial(.2, .6, .9, 1.), (G3Xvector) {2., 2., 2.}, NULL);

    // Up of table
    flat = createNodeByParent(*paramStool, g3x_Homothetie3d(1., 1., .1), cylinder);
    addChild(paramStool, flat);

    // Parameters for table foots.
    paramFoot = createNode(g3x_Mat_x_Mat(paramStool->Md, g3x_Homothetie3d(.20, .20, .65)), metal, paramStool->mat, (G3Xvector) {5., 5., 2.}, NULL);
    addNext(flat, paramFoot);

    // Foots of table
    foot1 = createNodeByParent(*paramFoot,g3x_Translation3d(7, 2, -1.6), cube);
    addChild(paramFoot, foot1);
    foot2 = createNodeByParent(*paramFoot, g3x_Translation3d(-7., -10., -1.6), cube);
    addNext(foot1, foot2);
    foot3 = createNodeByParent(*paramFoot, g3x_Translation3d(7., -10., -1.6), cube);
    addNext(foot2, foot3);
    foot4 = createNodeByParent(*paramFoot, g3x_Translation3d(-7., 2., -1.6), cube);
    addNext(foot3, foot4);

    return paramStool;
}