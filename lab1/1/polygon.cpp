#include "polygon.h"

Polygon::Polygon()
{

}
void Polygon::SetColor(QColor color)
{
    Color = color;
}
void Polygon::SetNewPolygon( QVector < QPair <double, double> > NewPolygon)
{
    Number_of_Corners = NewPolygon.size();
    for(int i = 0; i < NewPolygon.size(); i++)
    {
        vector.push_back(NewPolygon[i]);
    }
    ViewPolygon();
}

void Polygon::ViewPolygon()
{
    QPolygon poly;
    for(int i = 0; i < Number_of_Corners; i++)
    {
        poly << QPoint(vector[i].first, vector[i].second);
    }
    scene->addPolygon(poly,QPen(Qt::black), Color);
}

void Polygon::FlushPolygon()
{
    QPolygon poly;
    for(int i = 0; i < Number_of_Corners; i++)
    {
        poly << QPoint(vector[i].first, vector[i].second);
    }
    scene->addPolygon(poly,QPen(Qt::white),Qt::white);
}


void Polygon::RotatePolygon(double degree, int pointX, int pointY)
{
    FlushPolygon();
    degree = degree / 180 * M_PI;
    for(int i = 0; i < Number_of_Corners; i++)
    {
        double x = vector[i].first, y = vector[i].second;
        vector[i].first = (x - pointX) * cos(degree) - (y - pointY) * sin(degree) + pointX;
        vector[i].second = (x - pointX) * sin(degree) + (y - pointY) * cos(degree) + pointY;
    }
    ViewPolygon();
}


