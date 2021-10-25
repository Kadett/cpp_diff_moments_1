#pragma once

#include <iostream>

class PhoneNumber {
public:
    int country_code{}, city_code{}, extension_number{};

    std::string number;

    PhoneNumber(int countryCode, int cityCode, std::string number);

    PhoneNumber(int countryCode, int cityCode, std::string number, int extensionNumber);

    friend std::ostream &operator<<(std::ostream &out, const PhoneNumber &pn);

};

