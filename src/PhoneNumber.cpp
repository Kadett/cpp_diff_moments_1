#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(int countryCode, int cityCode, std::string number,
                         std::optional<int> extensionNumber) : country_code(
        countryCode), city_code(cityCode), number(std::move(number)), extension_number(extensionNumber) {}

std::ostream &operator<<(std::ostream &out, const PhoneNumber &pn) {
    out << "+" << pn.country_code << '(' << pn.city_code << ')' << pn.number;
    if (pn.extension_number) {
        out << ' ' << pn.extension_number.value();
    }
    return out;
}

bool operator<(const PhoneNumber &p1, const PhoneNumber &p2) {
    return std::tie(p1.country_code, p1.city_code, p1.number, p1.extension_number) < std::tie(p2.country_code, p2.city_code, p2.number, p2.extension_number);
}


