#include "polygonclass.h"

PolygonClass::PolygonClass()
{

}

void PolygonClass::SetZoom(double zoom)
{
    Zoom  = zoom;
    ViewPolygon();
}

double PolygonClass::GetX()
{
    return X;
}

double PolygonClass::GetZoom()
{
    return Zoom;
}

double PolygonClass::GetY()
{
    return Y;
}

double PolygonClass::GetNodeX(int it)
{
    return vector[it].first;
}

double PolygonClass::GetNodeY(int it)
{
    return vector[it].second;
}

int PolygonClass::GetNumberOfCorners()
{
    return Number_of_Corners;
}

void PolygonClass::Flushdata()
{
    vector.clear();
    X = 250;
    Y = 150;
    Number_of_Corners = 0;
    Zoom = 1;
}

void PolygonClass::SetDefaultPoint()
{
    X = 250;
    Y = 150;
    while(vector.size() < Number_of_Corners)vector.push_back({0,0});
    for(int i = 0; i < Number_of_Corners; i++)
    {
        vector[i].first = X + (50 * sin( M_PI * 2 / Number_of_Corners * (i + 1)));
        vector[i].second = Y + (50 * cos( M_PI * 2 / Number_of_Corners * (i + 1)));
    }
}


void PolygonClass::SetNewCenter(double ShiftX, double ShiftY)
{
    X += ShiftX;
    Y += ShiftY;
    for(int i = 0; i < Number_of_Corners; i++) vector[i].first += ShiftX, vector[i].second += ShiftY;
    ViewPolygon();
}


void PolygonClass::SetNewPositionNode(int it, double x, double y)
{
    vector[it].first = (x);
    vector[it].second =(y);
    CalculateCenter();
    ViewPolygon();
}

void PolygonClass::SetNewPolygon( QVector < QPair <double, double> > NewPolygon)
{
    Number_of_Corners = NewPolygon.size();
    for(int i = 0; i < NewPolygon.size(); i++)
    {
        vector.push_back(NewPolygon[i]);
    }
    CalculateCenter();
    ViewPolygon();
}

void PolygonClass::ViewPolygon()
{
    QPolygon poly;
    for(int i = 0; i < Number_of_Corners; i++)
    {
        poly << QPoint(vector[i].first * Zoom - X * Zoom + X,vector[i].second * Zoom - Y * Zoom + Y);
    }

    scene->clear();
    scene->addPolygon(poly);
    scene->addEllipse(X - 5 ,Y - 5, 10, 10);
    QColor color2;
    color2.setRgb(100,100,100);
    scene->addEllipse(X - 3 ,Y - 3, 6, 6, QPen(Qt::black),color2);
    for(int i = 0; i < Number_of_Corners; i++)scene->addEllipse(vector[i].first * Zoom + X - X * Zoom - 5 ,vector[i].second * Zoom + Y - Y * Zoom - 5, 10, 10,QPen(Qt::red));
    OutputArea();
    OutputPerimeter();
    OutputCenterOfMass();
}


void PolygonClass::RotatePolygon(double degree)
{
    degree = degree / 180 * M_PI;
    for(int i = 0; i < Number_of_Corners; i++)
    {
        double x = vector[i].first, y = vector[i].second;
        vector[i].first = (x - X) * cos(degree) - (y - Y) * sin(degree) + X;
        vector[i].second = (x - X) * sin(degree) + (y - Y) * cos(degree) + Y;
    }
    ViewPolygon();
}

void PolygonClass::CalculateCenter()
{
    double Area = 0, BackX, BackY, NextX, NextY;
    double CenterX = 0, CenterY = 0;
    for(int i = 0; i < Number_of_Corners ; i++)
    {
        BackX = vector[i].first;
        BackY = vector[i].second;
        NextY = vector[(i + 1) % Number_of_Corners].second;
        NextX = vector[(i + 1) % Number_of_Corners].first;
        double a = BackX * NextY - NextX * BackY;
        Area += a;
        CenterX += (BackX + NextX) * a;
        CenterY += (BackY + NextY) * a;
    }
    Area /= 2;
    CenterX /= Area * 6;
    CenterY /= Area * 6;
    X = CenterX;
    Y = CenterY;
}

void PolygonClass::OutputCenterOfMass()
{

    output_center_of_mass->setText("");
    QString s;
    s = QString::number(X) + " " + QString::number(Y);
    output_center_of_mass->setText(s);
}


void PolygonClass::OutputPerimeter()
{
    double res = 0;
    for(int i = 1; i < Number_of_Corners; i++)res +=sqrt( (vector[i - 1].first - vector[i].first) * (vector[i - 1].first - vector[i].first) +
                                                          (vector[i - 1].second - vector[i].second) * (vector[i - 1].second - vector[i].second));
    output_perimeter->setText("");
    QString s;
    s = QString::number(res);
    output_perimeter->setText(s);
}


void PolygonClass::OutputArea()
{
    double res = 0;

    for(int i = 0; i < Number_of_Corners - 1; i++)
        res += (vector[i].second + vector[i + 1].second +2000) / 2 * (vector[i + 1].first - vector[i].first);
    res += (vector[Number_of_Corners - 1].second + vector[0].second + 2000) / 2 * (-vector[Number_of_Corners - 1].first + vector[0].first);

    output_area->setText("");
    QString s;
    s = QString::number(fabs(res));
    output_area->setText(s);
}


void PolygonClass::SetNumbersOfCorners(int corners)
{
    Number_of_Corners = corners;
}

