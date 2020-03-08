#include "dump.h"

Dump::Dump()
{

}
void Dump::AddScene(QGraphicsScene *Scene)
{
    scene = Scene;
}
void Dump::AddPolygon(QVector < QPair <double, double> > poly, QColor color)
{
    Polygon *polygon = new Polygon;
    polygon->scene = scene;
    polygon->SetColor(color);
    polygon->SetNewPolygon(poly);

    vector.push_back(polygon);
    lastPolygon++;
}

void Dump::Change(int iterator, double degree, double pointX, double PointY)
{
    vector[iterator]->RotatePolygon(degree,pointX,PointY);
}
void Dump::ViewDump()
{
    QColor color;
    QVector < QPair <double, double> > poly;
    color.setRgb(255, 179, 20);
    //truck
    poly.push_back( {50,250} );
    poly.push_back( {100,300} );
    poly.push_back( {300,300} );
    poly.push_back( {300,200} );
    poly.push_back( {100,200} );
    AddPolygon( poly,color);
    poly.clear();

    // Head
    color.setRgb(240, 230, 140);
    poly.push_back( {300, 350} );
    poly.push_back( {450,350} );
    poly.push_back( {450,300} );
    poly.push_back( {425,275} );
    poly.push_back( {375,275} );
    poly.push_back( {375,225} );
    poly.push_back( {300,225} );
    AddPolygon( poly,color);
    poly.clear();
    //Door
    poly.push_back( {325,325} );
    poly.push_back( {350,325} );
    poly.push_back( {370,300} );
    poly.push_back( {370,240} );
    poly.push_back( {325,240} );
    AddPolygon( poly,color);
    poly.clear();
    //body
    color.setRgb(128,128,128);
    poly.push_back( {100,300} );
    poly.push_back( {100,350} );
    poly.push_back( {250,350} );
    poly.push_back( {250,300} );
    AddPolygon( poly,color);
    poly.clear();
    //gas tank
    color.setRgb(211,211,211);
    poly.push_back( {250,350} );
    poly.push_back( {250,300} );
    poly.push_back( {300,300} );
    poly.push_back( {300,350} );
    AddPolygon( poly,color);
    poly.clear();
    //Door Window
    color.setRgb(153,204,211);
    poly.push_back( {365,245} );
    poly.push_back( {365,270} );
    poly.push_back( {335,270} );
    poly.push_back( {335,245} );
    AddPolygon( poly,color);
    poly.clear();
    //Front Window
    poly.push_back( {375,275} );
    poly.push_back( {375,225} );
    poly.push_back( {400,275} );
    AddPolygon( poly,color);
    poly.clear();
    // Left Second Wheel
    scene->addEllipse(100,325,60,60,QColor(0,0,0),QColor(0,0,0));
    scene->addEllipse(110,335,40,40,QColor(0,0,0),QColor(211,211,211));
    // Left First Wheel
    scene->addEllipse(160,325,60,60,QColor(0,0,0),QColor(0,0,0));
    scene->addEllipse(170,335,40,40,QColor(0,0,0),QColor(211,211,211));
    // Right Wheel
    scene->addEllipse(360,325,60,60,QColor(0,0,0),QColor(0,0,0));
    scene->addEllipse(370,335,40,40,QColor(0,0,0),QColor(211,211,211));

}
