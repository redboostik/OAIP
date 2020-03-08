#ifndef DUMP_H
#define DUMP_H
#include<polygon.h>

class Dump
{
public:
    Dump();
    void AddScene(QGraphicsScene* Scene);
    void AddPolygon(QVector < QPair <double, double> > poly, QColor color);
    void ViewDump();
    void Change(int iterator, double degree, double pointX, double PointY);
private:
    QVector< Polygon* > vector;
    int lastPolygon;
    QGraphicsScene* scene;
};

#endif // DUMP_H
