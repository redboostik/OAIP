#ifndef CIRCLECLASS_H
#define CIRCLECLASS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QLineEdit>
#include <QtMath>
#include <QGraphicsItem>
#include <QPen>
#include <QColor>
class CircleClass
{
public:

    CircleClass();

    void OutputArea();
    void OutputPerimeter();
    void OutputCenterOfMass();

    void SetNewCenter(double x, double y);
    void SetNewRadius(double radius);
    void SetZoom(double zoom);

    void ViewCircle();

    double GetRadius();
    double GetZoom();
    double GetX();
    double GetY();
    QGraphicsScene *scene;
    QLineEdit *output_area, *output_perimeter, *output_center_of_mass;

private:
    double Radius = 50;
    double Zoom = 2;
    double X = 250, Y = 150;

};

#endif // CIRCLECLASS_H
