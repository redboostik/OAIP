#ifndef USERSCLASS_H
#define USERSCLASS_H

#include "QString"
#include <QtMath>
#include <QFile>

class UsersClass
{
public:
    UsersClass();
    void SetNumber(QString number);
    void SetName(QString name);
    void SetPhone(QString phone);
    void SetAddress(QString address);

    QString GetName();
    QString GetNumber();
    QString GetPhone();
    QString GetAddress();

private:
    QString Number, Name, Phone, Address;
    QFile* Userlist;
};

#endif // USERSCLASS_H
