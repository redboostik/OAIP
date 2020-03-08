#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *Scene = new QGraphicsScene(this);
    Scene->setSceneRect(0,0,500,300);
    ui->graphicsView->setScene(Scene);
    ui->graphicsView->scene()->update();
    dump.AddScene(ui->graphicsView->scene());
    dump.ViewDump();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    dump.Change(0, -position + lastdegree,100,300);
    lastdegree = position;
}
