#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
public:
    enum personType {PRINCIPAL, TEACHER, STUDENT};
    Q_ENUM(personType)

    static Person* build(personType role);
    personType GetRole() const;

    explicit Person(QObject *parent = nullptr);

signals:

public slots:

private:
    personType  m_type;
};

#endif // PERSON_H
