#include "scene.h"

Scene::Scene(QWidget *parent) : QOpenGLWidget(parent){
    connect(&timer,SIGNAL(timeout()),this,SLOT(update()));
}

Scene::~Scene(){

}

void Scene::initializeGL(){
   QOpenGLShader vShader(QOpenGLShader::Vertex);
   vShader.compileSourceFile(":/vShader.glsl");

   QOpenGLShader fShader(QOpenGLShader::Fragment);
   fShader.compileSourceFile(":/fShader.glsl");

   program.addShader(&vShader);
   program.addShader(&fShader);

   program.link();

   vertexAttr = program.attributeLocation("vertexAttr");
   colorAttr = program.attributeLocation("colorAttr");
   matrixUniform = program.uniformLocation("matrix");

   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

   vertices.resize(12);
   vertices[0] = 0;
   vertices[1] = 0;
   vertices[2] = 0;

   vertices[3] = 0;
   vertices[4] = 1;
   vertices[5] = 0;

   vertices[6] = 1;
   vertices[7] = 1;
   vertices[8] = 0;

   vertices[9] = 1;
   vertices[10] = 0;
   vertices[11] = 0;

   for (int i = 0; i < 4; i++)
   {
       colors.push_back(0.0f);
       colors.push_back(1.0f);
       colors.push_back(1.0f);
   }

   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glEnable(GL_DEPTH_TEST);
   hRot = 0.0f;
   timer.start();
}

void Scene::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    program.bind();

    matrix.setToIdentity();
    matrix.ortho(-2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f);
    matrix.translate(0.0f, -0.5f, 0.0f);
    matrix.rotate(-20.0f, 1.0f, 0.0f, 0.0f);
    matrix.rotate(hRot, 0.0f, 1.0f, 0.0f);

    program.setUniformValue(matrixUniform, matrix);

    program.setAttributeArray(colorAttr, colors.data(), 3);
    program.setAttributeArray(vertexAttr, vertices.data(), 3);

    program.enableAttributeArray(colorAttr);
    program.enableAttributeArray(vertexAttr);

    glDrawArrays(GL_QUADS, 0, vertices.size()/3);



    program.disableAttributeArray(colorAttr);
    program.disableAttributeArray(vertexAttr);


    program.release();

    if (hRot > 360)
    {
        hRot = 0;
    }
    hRot += 0.5f;

}

void Scene::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}
