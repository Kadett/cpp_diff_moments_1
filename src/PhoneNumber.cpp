#include "PhoneNumber.h"

#include <utility>

PhoneNumber::PhoneNumber(int countryCode, int cityCode, std::string number) :
        country_code(countryCode), city_code(cityCode), number(std::move(number)) {}


PhoneNumber::PhoneNumber(int countryCode, int cityCode,std::string number, int extensionNumber ) : country_code(
        countryCode), city_code(cityCode), number(std::move(number)), extension_number(extensionNumber) {}

std::ostream &operator<<(std::ostream &out, const PhoneNumber &pn) {
    out << '+' << pn.country_code <<  '(' << pn.city_code << ')' << pn.number;
    if (pn.extension_number) {
        out << ' ' << pn.extension_number;
    }
    return out;
}
