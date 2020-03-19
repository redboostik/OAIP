#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bookclass.h"
#include "usersclass.h"
#include "creditlistclass.h"

#include <QMainWindow>
#include <QFile>
#include <QtMath>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QVector>
#include <QtAlgorithms>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void RewriteBookList();
    void RewriteDeptList();
    void RewriteIssuedBooksList();
    void RewriteUsersList();

private slots:
    void on_AddBook_clicked();

    void on_AddUser_clicked();

    void on_AddList_clicked();

    void on_DeleteBook_clicked();

    void on_DeleteUser_clicked();

    void on_DeleteList_clicked();

    void on_BooksFromFile_clicked();

    void on_SortUsers_clicked();

    void on_UsersFormFile_clicked();

    void on_ListFromFile_clicked();

    void on_SortBooks_clicked();

    void on_FindBook_clicked();

    void on_FindUser_clicked();

    void on_ViewBooks_clicked();

    void on_ViewList_clicked();

    void on_ViewUsers_clicked();

    void on_ViewDelay_clicked();

private:
    Ui::MainWindow *ui;
    QVector <BookClass*> bookList;
    QVector <UsersClass*> userList;
    QVector <CreditListClass*> creditList, delayList;
    QPlainTextEdit* ViewList = new QPlainTextEdit;
    QFile BookListTXT, DebtListTXT, IssuedBooksListTXT, UsersListTXT;
    bool FlagBook = 1, FlagUsers = 1, FlagList = 1;

};
#endif // MAINWINDOW_H
