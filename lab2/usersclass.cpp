#include "usersclass.h"

UsersClass::UsersClass()
{

}

void UsersClass::SetName(QString name)
{
    Name = name;
}

void UsersClass::SetPhone(QString phone)
{
    Phone = phone;
}

void UsersClass::SetNumber(QString number)
{
    Number = number;
}

void UsersClass::SetAddress(QString address)
{
    Address = address;
}

QString UsersClass::GetName()
{
    return  Name;
}

QString UsersClass::GetNumber()
{
    return Number;
}

QString UsersClass::GetAddress()
{
    return Address;
}

QString UsersClass::GetPhone()
{
    return  Phone;
}
