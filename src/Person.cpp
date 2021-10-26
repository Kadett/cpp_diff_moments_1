
#include "Person.h"

std::ostream &operator<<(std::ostream &out, const Person &person) {
    out.width(10);
    out.setf(std::ios::right);
    out << person.surname;
    out.width(10);
    out.setf(std::ios::right);
    out << person.name;
    out.width(16);
    out.setf(std::ios::right);
    if (person.patronymic) out << person.patronymic.value();
    return out;
}

bool operator<(const Person &p1, const Person &p2) {

    return std::tie(p1.surname, p1.name, p1.patronymic) < std::tie(p2.surname, p2.name, p2.patronymic);
}

bool operator==(const Person &p1, const Person &p2) {

    return std::tie(p1.surname, p1.name, p1.patronymic) == std::tie(p2.surname, p2.name, p2.patronymic);
}

Person::Person(std::string surname, std::string name, std::optional<std::string> patronymic) :
        surname(std::move(surname)), name(std::move(name)), patronymic(std::move(patronymic)) {}

std::string Person::getSurname() {
    return surname;
}


