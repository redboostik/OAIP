#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include "bookclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void AddNewBook();
    void DeleteBook(QString Code);

private slots:
    void on_AddBook_clicked();

    void on_ViewBooks_clicked();

    void on_FindBooks_clicked();

    void on_DeleteBook_clicked();

private:
    Ui::MainWindow *ui;
    BookClass *First = NULL, *Last = NULL;
};
#endif // MAINWINDOW_H
