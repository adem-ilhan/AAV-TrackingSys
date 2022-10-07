#include "drawing.h"

Drawing::Drawing(QWidget *parent)
    : QOpenGLWidget{parent}
{

}

void Drawing::initializeGL()
{
    float r,g,b;
       qColorToRGB(Qt::white,r,g,b);
       initializeOpenGLFunctions();
       glClearColor(r,g,b,1.0f);
       glEnable(GL_DEPTH_TEST);
       glEnable(GL_LIGHT0);
       glEnable(GL_LIGHTING);
       glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
       glEnable(GL_COLOR_MATERIAL);

}

void Drawing::paintGL()
{
    float r,g,b;
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glBegin(GL_LINES);
       qColorToRGB(Qt::red,r,g,b);
       glColor3f(r,g,b);
       glVertex3f(-1.0,1.0,1.0);
       glVertex3f(1.0,-1.0,-1.0);
       glEnd();
       glBegin(GL_LINES);
       qColorToRGB(Qt::green,r,g,b);
       glColor3f(r,g,b);
       glVertex3f(1.0,1.0,1.0);
       glVertex3f(-1.0,-1.0,-1.0);
       glEnd();
}

void Drawing::resizeGL(int w, int h)
{
    glViewport(a,b,w,h);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
}

void Drawing::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug() << Q_FUNC_INFO << "Not implemented yet!";
}

void Drawing::qColorToRGB(const QColor &C, float &r, float &g, float &b) const
{
    int red = C.red();
     int green = C.green();
     int blue = C.blue();
     r = normalize_0_1(red , 1.0,255.0);
     g = normalize_0_1(green,1.0,255.0);
     b = normalize_0_1(blue,1.0,255.0);
}

float Drawing::normalize_0_1(float val, float min, float max) const
{
    return (val -min) / (max -min);


}
