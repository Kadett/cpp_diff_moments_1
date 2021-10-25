#pragma once

#include <iostream>

class Person {
    std::string surname{}, name{}, patronymic{};
public:

    Person(std::string surname, std::string name);

    Person(std::string surname, std::string name, std::string patronymic);

    friend std::ostream &operator<<(std::ostream &out, const Person &person);

    friend bool operator<(const Person &p1, const Person &p2);
    friend bool operator==(const Person &p1, const Person &p2);
};

