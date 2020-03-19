#ifndef BOOKCLASS_H
#define BOOKCLASS_H

#include "QString"
#include <QtMath>
#include <QDate>

class BookClass
{
public:
    BookClass();
    bool get_int(QString s, char ch);
    QString Title, Author, Code, Pages, Publishing;
    QString publicationDate;
    BookClass *nextList = NULL;
};

#endif // BOOKCLASS_H
