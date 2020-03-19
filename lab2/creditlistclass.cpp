#include "creditlistclass.h"

CreditListClass::CreditListClass()
{

}

void CreditListClass::SetNumberBook(QString number)
{
    numberBook = number;
}

void CreditListClass::SetNumberUser(QString number)
{
    numberUser = number;
}

void CreditListClass::SetReturnDate(QDate *date)
{
    returnDate = date;
}

void CreditListClass::SetDataOfIssue(QDate *date)
{
    issueDate = date;
}

void CreditListClass::SetRealReturnDate(QDate *date)
{
    realDate = date;
}

QString CreditListClass::GetNumberBook()
{
    return numberBook;
}

QString CreditListClass::GetNumberUser()
{
    return numberUser;
}

QString CreditListClass::GetDataOfIssue()
{
    return QString::number(issueDate->day()) + " " + QString::number(issueDate->month()) + " " + QString::number(issueDate->year());
}

QString CreditListClass::GetReturnDate()
{
    return QString::number(returnDate->day()) + " " + QString::number(returnDate->month()) + " " + QString::number(returnDate->year());
}

QString CreditListClass::GetRealReturnDate()
{
    return QString::number(realDate->day()) + " " + QString::number(realDate->month()) + " " + QString::number(realDate->year());
}

bool CreditListClass::GetDelay()
{
    return 10 < returnDate->daysTo(*realDate);
}
