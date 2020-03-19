#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    BookListTXT.setFileName("BookList.txt");
    DebtListTXT.setFileName("DebtList.txt");
    IssuedBooksListTXT.setFileName("IssuedBooksList.txt");
    UsersListTXT.setFileName("UsersList.txt");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool BookComparator(BookClass* l, BookClass* r)
{
    return l->GetTitle() < r->GetTitle();
}

bool UserComparator(UsersClass* l, UsersClass* r)
{
    return l->GetName() < r->GetName();
}

void MainWindow::on_AddBook_clicked()
{
    BookClass* book = new BookClass;

    book->SetNumber(ui->FirstAddLine->text());
    ui->FirstAddLine->clear();
    book->SetTitle(ui->SecondAddLine->text());
    ui->SecondAddLine->clear();
    book->SetAuthor(ui->ThirdAddLine->text());
    ui->ThirdAddLine->clear();
    book->SetLocalization(ui->FifthAddLine->text());
    ui->FifthAddLine->clear();

    QString s = ui->FourthAddLine->text();
    ui->FourthAddLine->clear();
    QStringList ss = s.split(' ');
    QDate* date = new QDate;
    date->setDate(ss[2].toInt(), ss[1].toInt(), ss[1].toInt());
    book->SetPublicationDate(date);
    bookList.push_back(book);

    if(FlagBook)RewriteBookList();

}

void MainWindow::on_AddUser_clicked()
{
    UsersClass* user = new UsersClass;

    user->SetNumber(ui->FirstAddLine->text());
    ui->FirstAddLine->clear();
    user->SetName(ui->SecondAddLine->text());
    ui->SecondAddLine->clear();
    user->SetPhone(ui->ThirdAddLine->text());
    ui->ThirdAddLine->clear();
    user->SetAddress(ui->FourthAddLine->text());
    ui->FourthAddLine->clear();

    userList.push_back(user);

    if(FlagUsers)RewriteUsersList();
}

void MainWindow::on_AddList_clicked()
{
    CreditListClass* credit = new CreditListClass;

    credit->SetNumberBook(ui->FirstAddLine->text());
    ui->FirstAddLine->clear();
    credit->SetNumberUser(ui->SecondAddLine->text());
    ui->SecondAddLine->clear();

    QString s = ui->ThirdAddLine->text();
    ui->ThirdAddLine->clear();
    QStringList ss = s.split(' ');
    QDate* date = new QDate;
    date->setDate(ss[2].toInt(), ss[1].toInt(), ss[1].toInt());
    credit->SetDataOfIssue(date);

    s = ui->FourthAddLine->text();
    ui->FourthAddLine->clear();
    ss = s.split(' ');
    date = new QDate;
    date->setDate(ss[2].toInt(), ss[1].toInt(), ss[1].toInt());
    credit->SetReturnDate(date);

    s = ui->FifthAddLine->text();
    ui->FifthAddLine->clear();
    ss = s.split(' ');
    date = new QDate;
    date->setDate(ss[2].toInt(), ss[1].toInt(), ss[1].toInt());
    credit->SetRealReturnDate(date);
    creditList.push_back(credit);

    if(FlagList)RewriteIssuedBooksList();
}

void MainWindow::on_DeleteBook_clicked()
{
    QString s = ui->DeleteLine->text();
    ui->DeleteLine->clear();
    for(QVector <BookClass*>::iterator i = bookList.begin(); i != bookList.end(); i++)
    {
        if((*i)->GetNumber() == s)
        {
            bookList.erase(i);
            break;
        }
    }
    RewriteBookList();
}

void MainWindow::on_DeleteUser_clicked()
{
    QString s = ui->DeleteLine->text();
    ui->DeleteLine->clear();
    for(QVector <UsersClass*>::iterator i = userList.begin(); i != userList.end(); i++)
    {
        if((*i)->GetNumber() == s)
        {
            userList.erase(i);
            break;
        }
    }
    RewriteUsersList();
}

void MainWindow::on_DeleteList_clicked()
{
    QString s = ui->DeleteLine->text();
    ui->DeleteLine->clear();
    for(QVector <CreditListClass*>::iterator i = creditList.begin(); i != creditList.end(); i++)
    {
        QString check = (*i)->GetNumberBook() + " " + (*i)->GetNumberUser();
        if(check == s)
        {
            creditList.erase(i);
            break;
        }
    }
    RewriteIssuedBooksList();
    RewriteDeptList();
}

void MainWindow::on_BooksFromFile_clicked()
{
    FlagBook = 0;
    bookList.clear();
    BookListTXT.open(QIODevice::ReadOnly);
    QString s = BookListTXT.readAll();
    BookListTXT.close();
    QStringList ss = s.split('\n');
    for(int i = 0; i < ss.size() / 6; i++)
    {
        int j = 0;
        while(ss[i * 6 + 1 + i][j]!=' ')j++;
        j++;
        QString pushstring = "";
        for(; j < ss[i * 6 + 1 + i].size(); j ++) pushstring += ss[i * 6 + 1 + i][j];
        ui->FirstAddLine->setText(pushstring);

        j = 0;
        while(ss[i * 6 + 2 + i][j]!=' ')j++;
        j++;
         pushstring = "";
        for(; j < ss[i * 6 + 2 + i].size(); j ++) pushstring += ss[i * 6 + 2 + i][j];
        ui->SecondAddLine->setText(pushstring);

        j = 0;
        while(ss[i * 6 + 3 + i][j]!=' ')j++;
        j++;
         pushstring = "";
        for(; j < ss[i * 6 + 3 + i].size(); j ++) pushstring += ss[i * 6 + 3 + i][j];
        ui->ThirdAddLine->setText(pushstring);

        j = 0;
        while(ss[i * 6 + 4 + i][j]!=' ')j++;
        j++;
         pushstring = "";
        for(; j < ss[i * 6 + 4 + i].size(); j ++) pushstring += ss[i * 6 + 4 + i][j];
        ui->FourthAddLine->setText(pushstring);

        j = 0;
        while(ss[i * 6 + 5 + i][j]!=' ')j++;
        j++;
         pushstring = "";
        for(; j < ss[i * 6 + 5 + i].size(); j ++) pushstring += ss[i * 6 + 5 + i][j];
        ui->FifthAddLine->setText(pushstring);

        on_AddBook_clicked();
        int k = 0;
    }
    FlagBook = 1;
    RewriteBookList();
}

void MainWindow::on_UsersFormFile_clicked()
{
    FlagUsers = 0;
    userList.clear();
    UsersListTXT.open(QIODevice::ReadOnly);
    QString s = UsersListTXT.readAll();
    UsersListTXT.close();
    QStringList ss = s.split('\n');
    for(int i = 0; i < ss.size() / 5; i++)
    {
        int j = 0;
        while(ss[i * 5 + 1 + i][j]!=' ')j++;
        j++;
        QString pushstring = "";
        for(; j < ss[i * 5 + 1 + i].size(); j ++) pushstring += ss[i * 5 + 1 + i][j];
        ui->FirstAddLine->setText(pushstring);

        j = 0;
        while(ss[i * 5 + 2 + i][j]!=' ')j++;
        j++;
         pushstring = "";
        for(; j < ss[i * 5 + 2 + i].size(); j ++) pushstring += ss[i * 5 + 2 + i][j];
        ui->SecondAddLine->setText(pushstring);

        j = 0;
        while(ss[i * 5 + 3 + i][j]!=' ')j++;
        j++;
         pushstring = "";
        for(; j < ss[i * 5 + 3 + i].size(); j ++) pushstring += ss[i * 5 + 3 + i][j];
        ui->ThirdAddLine->setText(pushstring);

        j = 0;
        while(ss[i * 5 + 4 + i][j]!=' ')j++;
        j++;
         pushstring = "";
        for(; j < ss[i * 5 + 4 + i].size(); j ++) pushstring += ss[i * 5 + 4 + i][j];
        ui->FourthAddLine->setText(pushstring);

        on_AddUser_clicked();
    }
    FlagUsers = 1;
    RewriteUsersList();
}

void MainWindow::on_ListFromFile_clicked()
{
    FlagList = 0;
    creditList.clear();
    IssuedBooksListTXT.open(QIODevice::ReadOnly);
    QString s = IssuedBooksListTXT.readAll();
    IssuedBooksListTXT.close();
    QStringList ss = s.split('\n');
    for(int i = 0; i < ss.size() / 6; i++)
    {
        int j = 0;
        while(ss[i * 6 + 1 + i][j]!=' ')j++;
        j++;
        QString pushstring = "";
        for(; j < ss[i * 6 + 1 + i].size(); j ++) pushstring += ss[i * 6 + 1 + i][j];
        ui->FirstAddLine->setText(pushstring);

        j = 0;
        while(ss[i * 6 + 2 + i][j]!=' ')j++;
        j++;
         pushstring = "";
        for(; j < ss[i * 6 + 2 + i].size(); j ++) pushstring += ss[i * 6 + 2 + i][j];
        ui->SecondAddLine->setText(pushstring);

        j = 0;
        while(ss[i * 6 + 3 + i][j]!=' ')j++;
        j++;
         pushstring = "";
        for(; j < ss[i * 6 + 3 + i].size(); j ++) pushstring += ss[i * 6 + 3 + i][j];
        ui->ThirdAddLine->setText(pushstring);

        j = 0;
        while(ss[i * 6 + 4 + i][j]!=' ')j++;
        j++;
         pushstring = "";
        for(; j < ss[i * 6 + 4 + i].size(); j ++) pushstring += ss[i * 6 + 4 + i][j];
        ui->FourthAddLine->setText(pushstring);

        j = 0;
        while(ss[i * 6 + 5 + i][j]!=' ')j++;
        j++;
         pushstring = "";
        for(; j < ss[i * 6 + 5 + i].size(); j ++) pushstring += ss[i * 6 + 5 + i][j];
        ui->FifthAddLine->setText(pushstring);

        on_AddList_clicked();
        int k = 0;
    }
    FlagList = 1;
    RewriteIssuedBooksList();
    RewriteDeptList();
}

void MainWindow::on_SortBooks_clicked()
{
    std::sort(bookList.begin(),bookList.end(),BookComparator);
    RewriteBookList();
}

void MainWindow::on_SortUsers_clicked()
{
    std::sort(userList.begin(),userList.end(),UserComparator);
    RewriteUsersList();
}


void MainWindow::on_FindBook_clicked()
{
    QString title = ui->BookFindTitle->text();
    QString author = ui->BookFindAuthor->text();
    ui->BookFindTitle->clear();
    ui->BookFindAuthor->clear();
    bool flagTitle = 0, flagAuthor = 0;
    if(title == "-")flagTitle = 1;
    if(author == "-")flagAuthor = 1;
    ui->ViewList_2->clear();
    for(int i = 0; i < bookList.size(); i++) if((flagTitle or title == bookList[i]->GetTitle()) and (flagAuthor or author == bookList[i]->GetAuthor()))
    {
        QString s = QString::number(i + 1) + " Book :\ncode: " + bookList[i]->GetNumber() + "\nTitle: " + bookList[i]->GetTitle() + "\nAuthor: " + bookList[i]->GetAuthor() +
                    "\nPublication date: " + bookList[i]->GetPublicationDate() + "\nLocalization: " + bookList[i]->GetLocalization() + "\n\n";
        ui->ViewList_2->insertPlainText(s);
    }

}

void MainWindow::on_FindUser_clicked()
{
    QString userName = ui->UserFindName->text();
    ui->ViewList_2->clear();
    for(int i = 0; i < userList.size(); i++)if(userName == userList[i]->GetName())
    {
        QString s = QString::number(i + 1) + " User :\ncode: " + userList[i]->GetNumber() + "\nName: " + userList[i]->GetName() + "/nPhone: " + userList[i]->GetPhone() +
                   "\nLocalization: " + userList[i]->GetAddress() + "\n\n";
        ui->ViewList_2->insertPlainText(s);
    }
}

void MainWindow::on_ViewBooks_clicked()
{
    ui->ViewList_2->clear();
    for(int i = 0; i < bookList.size(); i++)
    {
        QString s = QString::number(i + 1) + " Book :\ncode: " + bookList[i]->GetNumber() + "\nTitle: " + bookList[i]->GetTitle() + "\nAuthor: " + bookList[i]->GetAuthor() +
                    "\nPublication date: " + bookList[i]->GetPublicationDate() + "\nLocalization: " + bookList[i]->GetLocalization() + "\n\n";
        ui->ViewList_2->insertPlainText(s);
    }
}

void MainWindow::on_ViewList_clicked()
{
    ui->ViewList_2->clear();
    for(int i = 0; i < creditList.size(); i++)
    {
        QString s = QString::number(i + 1) + "::\ncode book: " + creditList[i]->GetNumberBook() + "\ncode user: " + creditList[i]->GetNumberUser() +
                    "\nissue date: " + creditList[i]->GetDataOfIssue() + "\nreturn date: " + creditList[i]->GetReturnDate() + "\nreal date: " + creditList[i]->GetRealReturnDate() + "\n\n";
        ui->ViewList_2->insertPlainText(s);
    }
}

void MainWindow::on_ViewUsers_clicked()
{
    ui->ViewList_2->clear();
    for(int i = 0; i < userList.size(); i++)
    {
        QString s = QString::number(i + 1) + "User :\ncode: " + userList[i]->GetNumber() + "\nName: " + userList[i]->GetName() + "/nPhone: " + userList[i]->GetPhone() +
                   "\nLocalization: " + userList[i]->GetAddress() + "\n\n";
        ui->ViewList_2->insertPlainText(s);
    }
}

void MainWindow::on_ViewDelay_clicked()
{
    ui->ViewList_2->clear();
    for(int i = 0; i < creditList.size(); i++) if(creditList[i]->GetDelay())
    {
        QString s = QString::number(i + 1) + "::\ncode book: " + creditList[i]->GetNumberBook() + "\ncode user: " + creditList[i]->GetNumberUser() +
                    "\nissue date: " + creditList[i]->GetDataOfIssue() + "\nreturn date: " + creditList[i]->GetReturnDate() + "\nreal date: " + creditList[i]->GetRealReturnDate() + "\n\n";
        ui->ViewList_2->insertPlainText(s);
    }
}

void MainWindow::RewriteBookList()
{
    BookListTXT.open(QIODevice::WriteOnly);
    for(int i = 0; i < bookList.size(); i++)
    {
        QString s = QString::number(i + 1) + "_Book:\ncode: " + bookList[i]->GetNumber() + "\nTitle: " + bookList[i]->GetTitle() + "\nAuthor: " + bookList[i]->GetAuthor() +
                    "\nPublication_date: " + bookList[i]->GetPublicationDate() + "\nLocalization: " + bookList[i]->GetLocalization() + "\n\n";
        BookListTXT.write(s.toUtf8());
    }
    BookListTXT.close();
}

void MainWindow::RewriteUsersList()
{
    UsersListTXT.open(QIODevice::WriteOnly);
    for(int i = 0; i < userList.size(); i++)
    {
        QString s = QString::number(i + 1) + "_User:\ncode: " + userList[i]->GetNumber() + "\nName: " + userList[i]->GetName() + "\nPhone: " + userList[i]->GetPhone() +
                   "\nLocalization: " + userList[i]->GetAddress() + "\n\n";
        UsersListTXT.write(s.toUtf8());
    }
    UsersListTXT.close();
}

void MainWindow::RewriteIssuedBooksList()
{

    IssuedBooksListTXT.open(QIODevice::WriteOnly);
    for(int i = 0; i < creditList.size(); i++)
    {
        QString s = QString::number(i + 1) + "::\ncode_book: " + creditList[i]->GetNumberBook() + "\ncode_user: " + creditList[i]->GetNumberUser() + "\nissue_date: " +
                    creditList[i]->GetDataOfIssue() + "\nreturn_date: " + creditList[i]->GetReturnDate() + "\nreal_date: " + creditList[i]->GetRealReturnDate() + "\n\n";
        IssuedBooksListTXT.write(s.toUtf8());
    }
    IssuedBooksListTXT.close();
}

void MainWindow::RewriteDeptList()
{
    DebtListTXT.open(QIODevice::WriteOnly);
    for(int i = 0; i < creditList.size(); i++) if(creditList[i]->GetDelay())
    {
        QString s = QString::number(i + 1) + "::\ncode_book: " + creditList[i]->GetNumberBook() + "\ncode_user: " + creditList[i]->GetNumberUser() + "\nissue_date: " +
                creditList[i]->GetDataOfIssue() + "\nreturn_date: " + creditList[i]->GetReturnDate() + "\nreal_date: " + creditList[i]->GetRealReturnDate() + "\n\n";
        DebtListTXT.write(s.toUtf8());
    }
    DebtListTXT.close();
}
