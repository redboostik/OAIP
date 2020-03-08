#ifndef POLYGON_H
#define POLYGON_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QLineEdit>
#include <QtMath>
#include <QGraphicsItem>
#include <QPen>
#include <QColor>
#include <QVector>

class Polygon
{
public:

    Polygon();
    void SetNewPolygon(QVector < QPair <double, double> > NewPolygon);
    void RotatePolygon(double degree, int pointX, int pointY);
    void SetColor(QColor color);
    void FlushPolygon();
    void ViewPolygon();

    QGraphicsScene *scene;
private:
    QVector<QPair<double, double> > vector;
    double X = 250, Y = 150;
    int Number_of_Corners;
    QColor Color;
};

#endif // POLYGON_H
