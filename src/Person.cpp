#include <tuple>
#include "Person.h"

std::ostream &operator<<(std::ostream &out, const Person &person) {
    out << person.surname << " " << person.name << " " << (person.patronymic.empty() ? "???" : person.patronymic);
    return out;
}

bool operator<(const Person &p1, const Person &p2) {

    return std::tie(p1.surname, p1.name, p1.patronymic) < std::tie(p2.surname, p2.name, p2.patronymic);
}

bool operator==(const Person &p1, const Person &p2) {

    return std::tie(p1.surname, p1.name, p1.patronymic) == std::tie(p2.surname, p2.name, p2.patronymic);
}

Person::Person(std::string surname, std::string name) :
        surname(std::move(surname)), name(std::move(name)) {}

Person::Person(std::string surname, std::string name, std::string patronymic) :
        surname(std::move(surname)), name(std::move(name)), patronymic(std::move(patronymic)) {}
