#include "PhoneBook.h"
#include <utility>
PhoneBook::PhoneBook(std::ifstream &input) {


    while (!input.eof()) {
        std::string tmp_surname{}, tmp_name{}, tmp_patronymic{}, tmp_number{}, tmp_extension_number_str{};;
        int tmp_country_code{}, tmp_city_code{};
        std::optional<int> tmp_extension_number{std::nullopt};

        input >> tmp_surname >> tmp_name >> tmp_patronymic >> tmp_country_code >> tmp_city_code >> tmp_number;
        input >> tmp_extension_number_str;
        input.get();

        if (tmp_extension_number_str != "-") tmp_extension_number = std::stoi(tmp_extension_number_str);
        if (tmp_patronymic == "-") tmp_patronymic = "";

        persons.emplace_back(Person(tmp_surname, tmp_name, tmp_patronymic),
                             PhoneNumber(tmp_country_code, tmp_city_code, tmp_number, tmp_extension_number));

    }

}

std::ostream &operator<<(std::ostream &out, const PhoneBook &pBook) {
    for (auto &[person, number] : pBook.persons) {
        out << person << '\t';
        out << number << '\n';
    }
    return out;
}

void PhoneBook::SortByName() {
    std::sort(persons.begin(), persons.end(),
              [](const std::pair<Person, PhoneNumber> &p1, const std::pair<Person, PhoneNumber> &p2) {
                  return p1.first < p2.first;
              });
}

void PhoneBook::SortByPhone() {
    std::sort(persons.begin(), persons.end(),
              [](const std::pair<Person, PhoneNumber> &p1, const std::pair<Person, PhoneNumber> &p2) {
                  return p1.second < p2.second;
              });
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string &surname) {

    int count{};
    std::string str{};
    PhoneNumber tmp_phone{};
    for_each(persons.begin(), persons.end(), [&](const std::pair<Person, PhoneNumber> &pair) mutable {

        if (pair.first.surname == surname) {
            tmp_phone = pair.second;
            ++count;
        }
    });
    if (count == 0) str = "not found";
    else if(count == 1) str = "";
    else if(count > 1) str = "found more than 1";
    return std::make_tuple(str, tmp_phone);
}

void PhoneBook::ChangePhoneNumber(Person person, PhoneNumber number) {
    auto it = find_if(persons.begin(), persons.end(), [&person](std::pair<Person, PhoneNumber> &pair) -> bool {
        return person == pair.first;
    });
    it->second.country_code = number.country_code;
    it->second.city_code = number.city_code;
    it->second.number = number.number;
    it->second.extension_number = number.extension_number;

}




