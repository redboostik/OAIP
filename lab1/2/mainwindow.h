#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QEvent>
#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWidget>
#include "circleclass.h"
#include "polygonclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void AnimCircle();

    void AnimPolygon();

    void on_Start_Build_Figure_clicked();

    void on_Start_Change_Degree_clicked();

    void on_pushButton_3_clicked();

    void on_Start_Move_Center_clicked();

    void on_Paint_Figure_clicked();

    void on_Start_Zoom_clicked();

private:
    Ui::MainWindow *ui;
    double Rad, StepDegree, tkx, tky;
    bool Flag_Figure{0};
    CircleClass circle;
    PolygonClass polygon;
    int IteratorCricle{100}, IteratorPolygon{100};
    double lastDegree{0}, Point{0}, ShiftX{0}, ShiftY{0}, MoveCenterX{0}, MoveCenterY;
    bool Flag_move_Center{0};
    bool Flag_move_Node{0};
    bool Flag_paint_Figure{0};
    int Number_of_move_node{0};
    QVector < QPair <double, double> > NewVector;
protected:
    void FlushData();
    bool eventFilter(QObject *watched, QEvent *event) override;
};
#endif // MAINWINDOW_H
