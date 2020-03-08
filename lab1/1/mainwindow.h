#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dump.h"
#include <QMainWindow>

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
    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    Dump dump;
    double lastdegree{0};
};
#endif // MAINWINDOW_H
