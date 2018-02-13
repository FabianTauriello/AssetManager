#include "custodian.h"

Custodian::Custodian(const std::string &name, const std::string &department,
                     const std::string &phoneNumber, const Date &employmentStartDate)
    : _name{name}, _department{department}, _phoneNumber{phoneNumber}, _employmentStartDate{employmentStartDate} {
}

const std::string &Custodian::name() const {
    return _name;
}

const std::string &Custodian::department() const {
    return _department;
}

const std::string &Custodian::phoneNumber() const {
    return _phoneNumber;
}

const Date &Custodian::employmentStart() const {
    return _employmentStartDate;
}

void Custodian::setDepartment(std::string &department) {
    _department = department;
}

void Custodian::setPhoneNumber(std::string &phoneNumber) {
    _phoneNumber = phoneNumber;
}
