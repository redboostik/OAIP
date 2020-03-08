#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    QGraphicsScene *Scene = new QGraphicsScene(this);
    Scene->setSceneRect(0,0,500,300);
    ui->graphicsView->setScene(Scene);
    ui->graphicsView->scene()->update();
    polygon.scene = ui->graphicsView->scene();
    circle.scene = ui->graphicsView->scene();
    circle.output_area = ui->Output_Area;
    circle.output_perimeter = ui->Output_Perimeter;
    circle.output_center_of_mass = ui->Output_Center_Of_Mass;

    polygon.output_area = ui->Output_Area;
    polygon.output_perimeter = ui->Output_Perimeter;
    polygon.output_center_of_mass = ui->Output_Center_Of_Mass;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow:: FlushData()
{
    Flag_move_Node = 0;
    Number_of_move_node = 0;
    Flag_move_Center = 0;
    Flag_Figure = 0;
    IteratorCricle = 100;
    IteratorPolygon = 100;
    lastDegree = 0;
    Point = 0;
    ShiftX = 0;
    ShiftY = 0;
    MoveCenterX = 0;
    MoveCenterY = 0;
    Flag_move_Center = 0;
    Flag_move_Node = 0;
    Flag_paint_Figure = 0;
    Number_of_move_node = 0;
    NewVector.clear();
    ui->graphicsView->scene()->clear();
    polygon.Flushdata();

}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseMove and Flag_move_Center)
    {
        QMouseEvent *MouseEvent = static_cast<QMouseEvent *>(event);
        int x = MouseEvent->x();
        int y = MouseEvent->y();

        if(Flag_Figure)polygon.SetNewCenter(x - polygon.GetX(), y - polygon.GetY());
        else circle.SetNewCenter(x, y);

    }

    if(event->type() == QEvent::MouseMove and Flag_move_Node)
    {
        QMouseEvent *MouseEvent = static_cast<QMouseEvent *>(event);
        int x = MouseEvent->x();
        int y = MouseEvent->y();

        if(Flag_Figure)polygon.SetNewPositionNode(Number_of_move_node, x / polygon.GetZoom() + polygon.GetX() - polygon.GetX() * polygon.GetZoom() , y / polygon.GetZoom() + polygon.GetY() - polygon.GetY() * polygon.GetZoom());
    }

    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *MouseEvent = static_cast<QMouseEvent *>(event);
        if(MouseEvent->buttons() == Qt::LeftButton)
        {
            double x = MouseEvent->x();
            double y = MouseEvent->y();

            if(Flag_Figure)
            {
                if ((polygon.GetX() + 10 > x and polygon.GetX() - 10 < x) and
                    (polygon.GetY() + 10 > y and polygon.GetY() - 10 < y))
                {
                    Flag_move_Center = Flag_move_Center == 0;
                }
                for(int i = 0;  i < polygon.GetNumberOfCorners(); i++ )
                if(polygon.GetNodeX(i) + 10 > x / polygon.GetZoom() + polygon.GetX() - polygon.GetX() * polygon.GetZoom() and polygon.GetNodeX(i) - 10 < x / polygon.GetZoom() + polygon.GetX() - polygon.GetX() * polygon.GetZoom() and
                   polygon.GetNodeY(i) + 10 > y / polygon.GetZoom() + polygon.GetY() - polygon.GetY() * polygon.GetZoom() and polygon.GetNodeY(i) - 10 < y / polygon.GetZoom() + polygon.GetY() - polygon.GetY() * polygon.GetZoom())
                {
                    Flag_move_Node = Flag_move_Node == 0;
                    Number_of_move_node = i;
                    break;
                }
            }else
            {
                if ((circle.GetX() + 10 > x and circle.GetX() - 10 < x) and
                    (circle.GetY() + 10 > y and circle.GetY() - 10 < y))
                {
                    Flag_move_Center = Flag_move_Center == 0;
                }
            }
            if(Flag_paint_Figure and x > 20 and x < 500 and y > 20 and y < 300)
            {
                if(NewVector.size() == 0 or (fabs(NewVector[NewVector.size() - 1].first - x) > 5 or
                   fabs(NewVector[NewVector.size() - 1].second - y) > 5))NewVector.push_back({x, y});
                ui->graphicsView->scene()->addEllipse(x - 5 ,y - 5, 10, 10,QPen(Qt::red));
            }
        }

    }

    QObject::eventFilter( watched, event);
}


void MainWindow::on_Start_Build_Figure_clicked()
{
    FlushData();
    QString s = ui->Input_Corners->text();
    int k = s.toInt();

    if(k!=2)
    {
        ui->Input_Change_Node->setEnabled(1);
        ui->Start_Change_Degree->setEnabled(1);
        ui->pushButton_3->setEnabled(1);
        ui->Input_Change_Center->setEnabled(1);
        ui->Start_Move_Center->setEnabled(1);
        ui->Input_Zoom->setEnabled(1);
        ui->Start_Zoom->setEnabled(1);


        if(k == 0)
        {
            ui->Input_Degree->setEnabled(1);
            ui->Dinamic_Label->setText("Set radius");
            ui->pushButton_3->setText("Set radius");
            Flag_Figure = 0;
            circle.ViewCircle();
        } else
        {
            ui->Input_Degree->setEnabled(1);
            ui->pushButton_3->setEnabled(1);
            ui->Dinamic_Label->setText("Num point and x y");
            ui->pushButton_3->setText("Move point");
            Flag_Figure = 1;
            polygon.SetNumbersOfCorners(k);
            polygon.SetDefaultPoint();
            polygon.ViewPolygon();
        }

    }

}

void MainWindow::on_Start_Change_Degree_clicked()
{
    if(Flag_Figure)
    {
        QString s = ui->Input_Degree->text();
        double k = s.toDouble();
        double RotateDegree = k - lastDegree;
        lastDegree = k;
        IteratorPolygon = 1;
        StepDegree = RotateDegree / 100;
        AnimPolygon();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(Flag_Figure)
    {
        QString s = ui->Input_Change_Node->text();
        QStringList ss = s.split(' ');
        Point = ss[0].toInt() - 1;
        int PointX = ss[1].toDouble(), PointY = ss[2].toDouble();
        ShiftX = (PointX - polygon.GetNodeX(Point)) / 100;
        ShiftY = (PointY - polygon.GetNodeY(Point)) / 100;
        IteratorPolygon = 1;
        AnimPolygon();
    }else
    {
        QString s = ui->Input_Change_Node->text();
        QStringList ss = s.split(' ');

        double k1 = ss[0].toDouble();
        double sdvig = circle.GetRadius() - k1;
        Rad = - sdvig / 100;
        IteratorCricle = 1;
        AnimCircle();
    }
}

void MainWindow::on_Start_Move_Center_clicked()
{
    if(Flag_Figure)
    {
        QString s = ui->Input_Change_Center->text();
        QStringList ss = s.split(' ');
        MoveCenterX = (ss[0].toDouble() - polygon.GetX()) / 100;
        MoveCenterY = (ss[1].toDouble() - polygon.GetY()) / 100;
        AnimPolygon();
    }else
    {
        QString s = ui->Input_Change_Center->text();
        QStringList ss = s.split(' ');
        tkx = (ss[0].toInt() - circle.GetX()) / 100;
        tky = (ss[1].toInt() - circle.GetY()) / 100;
        IteratorCricle = 1;
        QTimer::singleShot(10, this, SLOT(AnimCircle()));
    }
}

void MainWindow::AnimCircle()
{
    if(IteratorCricle > 100)
    {
        tkx = 0;
        tky = 0;
        Rad = 0;
        return;
    }
    QTimer::singleShot(10, this, SLOT(AnimCircle()));
    circle.SetNewRadius(circle.GetRadius() + Rad);
    circle.SetNewCenter(tkx + double(circle.GetX()) ,
                        tky + double(circle.GetY()) );
    circle.scene->clear();
    circle.ViewCircle();
    IteratorCricle++;
}

void MainWindow::AnimPolygon()
{
    if(IteratorPolygon > 100)
    {
        StepDegree = 0;
        ShiftX = 0;
        ShiftY = 0;
        MoveCenterX = 0;
        MoveCenterY = 0;
        return;
    }
    polygon.RotatePolygon(StepDegree);
    polygon.SetNewPositionNode(Point, polygon.GetNodeX(Point) + ShiftX,
                                      polygon.GetNodeY(Point) + ShiftY);
    polygon.SetNewCenter(MoveCenterX, MoveCenterY);
    IteratorPolygon++;
    QTimer::singleShot(10, this, SLOT(AnimPolygon()));
}


void MainWindow::on_Paint_Figure_clicked()
{
    if(!Flag_paint_Figure)FlushData();

    ui->Start_Move_Center->setEnabled(0);
    ui->Start_Build_Figure->setEnabled(0);
    ui->Start_Change_Degree->setEnabled(0);
    ui->pushButton_3->setEnabled(0);
    ui->Input_Degree->setEnabled(0);
    ui->Input_Corners->setEnabled(0);
    ui->Input_Change_Node->setEnabled(0);
    ui->Input_Change_Center->setEnabled(0);
    ui->Input_Zoom->setEnabled(0);
    ui->Start_Zoom->setEnabled(0);

    if(Flag_paint_Figure)
    {
        Flag_paint_Figure = 0;

        ui->Start_Move_Center->setEnabled(1);
        ui->Start_Build_Figure->setEnabled(1);
        ui->Start_Change_Degree->setEnabled(1);
        ui->pushButton_3->setEnabled(1);
        ui->Input_Degree->setEnabled(1);
        ui->Input_Corners->setEnabled(1);
        ui->Input_Change_Node->setEnabled(1);
        ui->Input_Change_Center->setEnabled(1);
        ui->Input_Zoom->setEnabled(1);
        ui->Start_Zoom->setEnabled(1);
        ui->Dinamic_Label->setText("Node X Y");
        ui->pushButton_3->setText("Move");

        polygon.SetNewPolygon(NewVector);
        Flag_Figure = 1;
        return;
    }
    Flag_paint_Figure = 1;
}

void MainWindow::on_Start_Zoom_clicked()
{
    QString s = ui->Input_Zoom->text();
    if(!Flag_Figure)circle.SetZoom(s.toDouble()); else
    polygon.SetZoom(s.toDouble());
}
