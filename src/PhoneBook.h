#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Person.h"
#include "PhoneNumber.h"

class PhoneBook {
public:
    std::vector<std::pair<Person, PhoneNumber>> persons;
    explicit PhoneBook(std::ifstream &input);

    friend std::ostream &operator<<(std::ostream &out, const PhoneBook &pBook);

    void SortByName();
    void SortByPhone();
    std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string& surname);
    void ChangePhoneNumber(Person person, PhoneNumber number);
};
