#include <QCoreApplication>
#include "Person.h"
#include <QDebug>
#include <QMetaEnum>
#include <QMetaObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject classroom;
    QMetaEnum metaEnum = QMetaEnum::fromType<Person::personType> ();

    for (int i(0); i < 10; i++)
    {
        Person::personType role = Person::personType::STUDENT;
        if(i == 0)
            role = Person::personType::PRINCIPAL;
        else if(i == 1)
            role = Person::personType::TEACHER;

        Person *p = Person::build(role);
        p->setParent(&classroom);
    }

    foreach(QObject *obj, classroom.children())
    {
        Person *p = qobject_cast<Person *>(obj);

        if(p)
        {
            qInfo() << p << "is a " << metaEnum.valueToKey(p->GetRole());
        }
    }

    return a.exec();
}
