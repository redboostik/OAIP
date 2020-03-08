#ifndef POLYGONCLASS_H
#define POLYGONCLASS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QLineEdit>
#include <QtMath>
#include <QGraphicsItem>
#include <QPen>
#include <QColor>
#include <QVector>

class PolygonClass
{
public:

    PolygonClass();
    void Flushdata();

    void OutputArea();
    void OutputPerimeter();
    void OutputCenterOfMass();

    void SetZoom(double zoom);
    void SetNewCenter(double x, double y);
    void SetNewPositionNode(int it, double x, double y);
    void SetDefaultPoint();
    void SetNumbersOfCorners(int corners);
    void SetNewPolygon(QVector < QPair <double, double> > NewPolygon);
    void RotatePolygon(double degree);
    void CalculateCenter();

    int GetNumberOfCorners();
    double GetZoom();
    double GetNodeX(int it);
    double GetNodeY(int it);
    double GetX();
    double GetY();

    void ViewPolygon();

    QGraphicsScene *scene;
    QLineEdit *output_area, *output_perimeter, *output_center_of_mass;
    QVector<QPair<double, double> > vector;
private:
    double X = 250, Y = 150, Zoom = 1;
    int Number_of_Corners;

};

#endif // POLYGONCLASS_H
