#ifndef CREDITLISTCLASS_H
#define CREDITLISTCLASS_H

#include "QString"
#include <QtMath>
#include <QDate>
#include <QFile>

class CreditListClass
{
public:
    CreditListClass();

    void SetNumberBook(QString number);
    void SetNumberUser(QString number);
    void SetDataOfIssue(QDate* date);
    void SetReturnDate(QDate* date);
    void SetRealReturnDate(QDate* date);

    QString GetNumberBook();
    QString GetNumberUser();
    QString GetDataOfIssue();
    QString GetReturnDate();
    QString GetRealReturnDate();

    bool GetDelay();


private:
    QString numberBook, numberUser;
    QDate *issueDate, *returnDate, *realDate;
    QFile *CreditList;
};

#endif // CREDITLISTCLASS_H
