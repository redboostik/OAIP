#include "circleclass.h"

CircleClass::CircleClass()
{

}

void CircleClass::SetZoom( double zoom)
{
    Zoom = zoom;
    ViewCircle();
}

double CircleClass::GetZoom()
{
    return Zoom;
}

void CircleClass::ViewCircle()
{
    scene->clear();
    scene -> addEllipse(X  - Radius / 2 * Zoom , Y - Radius / 2 * Zoom, Radius * Zoom, Radius * Zoom, QPen(Qt::black));
    scene->addEllipse(X - 5 ,Y - 5, 10, 10);
    QColor color2;
    color2.setRgb(100,100,100);
    scene->addEllipse(X - 3 ,Y - 3, 6, 6, QPen(Qt::black),color2);
    OutputArea();
    OutputPerimeter();
    OutputCenterOfMass();

}
void CircleClass::SetNewRadius(double radius)
{
    Radius = radius;
}

void CircleClass::SetNewCenter(double x, double y)
{
    X = x;
    Y = y;
    ViewCircle();
}

void CircleClass::OutputArea()
{
    output_area->setText("");
    double area = M_PI * Radius * Radius;
    output_area->setText(QString::number(area));

}

void CircleClass::OutputPerimeter()
{
    output_perimeter->setText("");
    double perimeter = 4 * M_PI * Radius;
    QString::number(perimeter);
    output_perimeter->setText(QString::number(perimeter));
}

void CircleClass::OutputCenterOfMass()
{
    output_center_of_mass->setText("");
    QString s1, s2;
    s1 = QString::number(X + Radius / 2);
    s1.insert(s1.size()," ");
    s2 = QString::number(Y + Radius / 2);
    s1 = s1 + s2;
    output_center_of_mass->setText(s1);
}

double CircleClass::GetRadius()
{
    return Radius;
}

double CircleClass::GetX()
{
    return X;
}
double CircleClass::GetY()
{
    return Y;
}
