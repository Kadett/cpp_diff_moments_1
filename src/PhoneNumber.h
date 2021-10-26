#pragma once

#include <iostream>
#include <optional>
#include <tuple>

class PhoneNumber {
public:
    int country_code{}, city_code{};
    std::optional<int> extension_number{};

    std::string number;

    PhoneNumber() = default;

    PhoneNumber(int countryCode, int cityCode, std::string number, std::optional<int> extensionNumber = std::nullopt);

    friend std::ostream &operator<<(std::ostream &out, const PhoneNumber &pn);
    friend bool operator<(const PhoneNumber &p1, const PhoneNumber &p2);

};

