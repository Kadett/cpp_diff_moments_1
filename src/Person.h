#pragma once

#include <iostream>
#include <tuple>
#include <optional>

class Person {
public:
    std::string surname{}, name{};
    std::optional<std::string> patronymic{};

    Person(std::string surname, std::string name, std::optional<std::string> patronymic = std::nullopt);

    std::string getSurname();

    friend std::ostream &operator<<(std::ostream &out, const Person &person);

    friend bool operator<(const Person &p1, const Person &p2);
    friend bool operator==(const Person &p1, const Person &p2);
};

