#include "Person.h"

Person *Person::build(Person::personType role)
{
    Person *p = new Person(nullptr);
    p->m_type = role;

    return p;
}

Person::personType Person::GetRole() const
{
    return m_type;
}

Person::Person(QObject *parent) : QObject(parent)
{

}
