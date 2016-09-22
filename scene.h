#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <vector>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QTimer>


using namespace std;

class Scene : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit Scene(QWidget* parent = 0);
    ~Scene();
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
private:
    int vertexAttr;
    int matrixUniform;
    int colorAttr;
    float hRot;
    QMatrix4x4 matrix;
    vector<float> vertices;
    vector<float> colors;
    QOpenGLShaderProgram program;
    QTimer timer;
};

#endif // SCENE_H
