#include "bookclass.h"

BookClass::BookClass()
{

}

void BookClass::SetAuthor(QString author)
{
    Author = author;
}

void BookClass::SetTitle(QString title)
{
    Title = title;
}

void BookClass::SetNumber(QString number)
{
    Number = number;
}

void BookClass::SetPublicationDate(QDate *date)
{
    publicationDate = date;
}

void BookClass::SetLocalization(QString localization)
{
    Localization = localization;
}

QString BookClass::GetAuthor()
{
    return Author;
}

QString BookClass::GetTitle()
{
    return Title;
}

QString BookClass::GetNumber()
{
    return Number;
}

QString BookClass::GetPublicationDate()
{
   return QString::number(publicationDate->day()) + " " + QString::number(publicationDate->month()) + " " + QString::number(publicationDate->year());
}

QString BookClass::GetLocalization()
{
    return Localization;
}
