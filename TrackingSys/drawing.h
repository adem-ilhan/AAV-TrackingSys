#ifndef DRAWING_H
#define DRAWING_H

#include <QObject>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QColor>
#include <QDebug>
#include <QMouseEvent>
#include <QVector>
class Drawing : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit Drawing(QWidget *parent = nullptr);
    QVector<double>x,y;
   // QVector<int>AVV;

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w , int h) override;
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    void qColorToRGB(const QColor &C,float &r, float &g, float &b) const;
    float normalize_0_1(float val, float min, float max) const;
    int a=0,b=0;

signals:

};

#endif // DRAWING_H
