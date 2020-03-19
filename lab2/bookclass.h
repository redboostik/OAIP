#ifndef BOOKCLASS_H
#define BOOKCLASS_H

#include "QString"
#include <QtMath>
#include <QDate>
#include <QFile>

class BookClass
{
public:
    BookClass();

    void SetNumber(QString number);
    void SetTitle(QString title);
    void SetAuthor(QString author);
    void SetPublicationDate(QDate* date);
    void SetLocalization(QString localization);

    QString GetTitle();
    QString GetAuthor();
    QString GetNumber();
    QString GetPublicationDate();
    QString GetLocalization();

private:
    QString Title, Author, Number, Localization;
    QDate* publicationDate;
    QFile BookList;
};

#endif // BOOKCLASS_H
