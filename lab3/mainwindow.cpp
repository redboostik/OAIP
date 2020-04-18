#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool get_int(QString s)
{
    for(int i = 0; i < s.size(); i++)
    if((s[i] < '0' or s[i] > '9'))
    {
        return 0;
    }
    return 1;
}

void MainWindow::on_AddBook_clicked()
{
    BookClass* newBook = new BookClass;
    QString sCode;
    QString sAuthor;
    QString sTitle;
    QString sYear;
    QString sPublishing;
    QString sPages;

    sCode = ui->AddCodeBook->text();
    sTitle = ui->AddTitle->text();
    sAuthor = ui->AddAuthor->text();
    sYear = ui->AddYearOfCreated->text();
    sPublishing = ui->AddPublishing->text();
    sPages = ui->AddNumberOfPages->text();

    if(get_int(sYear) and get_int(sPages));else return;

    ui->AddCodeBook->clear();
    ui->AddTitle->clear();
    ui->AddAuthor->clear();
    ui->AddYearOfCreated->clear();
    ui->AddPublishing->clear();
    ui->AddNumberOfPages->clear();

    newBook->Code = sCode;
    newBook->Title = sTitle;
    newBook->Author = sAuthor;
    newBook->publicationDate = sYear;
    newBook->Publishing = sPublishing;
    newBook->Pages = sPages;

    if(First == NULL)First = newBook; else
        Last->nextList = newBook;
    Last = newBook;
}

void MainWindow::on_ViewBooks_clicked()
{
    ui->plainTextEdit->clear();
    BookClass* now = First;
    int i = 0;
    while(now->nextList != NULL)
    {
        i++;
        QString s;
        s = QString::number(i) + " Book:\nCode: " + now->Code + "\nTitle: " + now->Title + "\nAuthor: " + now->Author + "\nPublishing" + now->Publishing +
            "\nYear of creating: " + now->publicationDate + "\nNumber of pages: " + now->Pages + "\n\n";
        now = now->nextList;
        ui->plainTextEdit->insertPlainText(s);
    }
    i++;
    QString s;
    s = QString::number(i) + " Book:\nCode: " + now->Code + "\nTitle: " + now->Title + "\nAuthor: " + now->Author + "\nPublishing: " + now->Publishing +
        "\nYear of creating: " + now->publicationDate + "\nNumber of pages: " + now->Pages + "\n\n";
    ui->plainTextEdit->insertPlainText(s);
}

void MainWindow::on_FindBooks_clicked()
{
    bool flagCode = 0;
    bool flagAuthor = 0;
    bool flagTitle = 0;
    bool flagYear = 0;

    QString sCode = ui->FindCode->text();
    QString sAuthor = ui->FindAuthor->text();
    QString sTitle = ui->FindTitle->text();
    QString sYear = ui->FindYearOfCreated->text();


    ui->FindCode->clear();
    ui->FindTitle->clear();
    ui->FindAuthor->clear();
    ui->FindYearOfCreated->clear();

    if(sCode == "-")flagCode = 1;
    if(sAuthor == "-")flagAuthor = 1;
    if(sTitle == "-")flagTitle = 1;
    if(sYear == "-")flagYear = 1;

    ui->plainTextEdit->clear();
    BookClass* now = First;
    int i = 0;
    while(now->nextList != NULL)
    {
        i++;
        if((flagCode or sCode == now->Code) and (flagAuthor or sAuthor == now->Author) and (flagTitle or sTitle == now->Title) and (flagYear or sYear == now->publicationDate))
        {
            QString s;
            s = QString::number(i) + " Book:\nCode: " + now->Code + "\nTitle: " + now->Title + "\nAuthor: " + now->Author + "\nPublishing" + now->Publishing +
                "\nYear of creating: " + now->publicationDate + "\nNumber of pages: " + now->Pages + "\n\n";
            ui->plainTextEdit->insertPlainText(s);
        }
        now = now->nextList;
    }
    i++;
    if((flagCode or sCode == now->Code) and (flagAuthor or sAuthor == now->Author) and (flagTitle or sTitle == now->Title) and (flagYear or sYear == now->publicationDate))
    {
        QString s;
        s = QString::number(i) + " Book:\nCode: " + now->Code + "\nTitle: " + now->Title + "\nAuthor: " + now->Author + "\nPublishing" + now->Publishing +
            "\nYear of creating: " + now->publicationDate + "\nNumber of pages: " + now->Pages + "\n\n";
        ui->plainTextEdit->insertPlainText(s);
    }
}

void MainWindow::on_DeleteBook_clicked()
{
    QString s = ui->DeleteCode->text();
    int i = 0;
    ui->plainTextEdit->clear();
    ui->DeleteCode->clear();
    BookClass* now = First, *preNow = NULL,*del;
    while(now->nextList != NULL)
    {
        i++;
        if(now->Code == s)
        {
            if(preNow != NULL)
            {
                del = now;
                preNow->nextList = now->nextList;
                now = now->nextList;
                delete (del);
            } else
            {
                First = now->nextList;
                delete now;
                now = First;
            }

        }else
        {
            if(preNow != NULL)preNow = preNow->nextList;else preNow = First;
            now = now->nextList;
        }
    }

    i++;
    if(now->Code == s)
    {
        Last = preNow;
        if(preNow != NULL)
        {
            del = now;
            preNow->nextList = now->nextList;
            now = now->nextList;
            delete (del);
        } else
        {
            First = now->nextList;
            delete now;
            now = First;
        }

    }else
    {
        preNow = preNow->nextList;
        now = now->nextList;
    }
}
