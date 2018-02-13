#include "television.h"


Television::Television(const std::string &id, const std::string &brand, const std::string &model,
                       double purchasePrice, const Date &purchaseDate,
                       const std::string &serialNumber, const std::string &location)
    : Asset{id, brand, model, purchasePrice, purchaseDate},
      _serialNumber{serialNumber},
      _location{location} {

}

const std::string &Television::serialNumber() const {
    return _serialNumber;
}

const std::string &Television::location() const {
    return _location;
}

void Television::setLocation(std::string location) {
    _location = location;
}

double Television::calculateDepreciation(const Date &date) const {
    double effectiveLifeSpan = 6;
    double a = purchaseDate().differenceInDays(date) / 365;
    double b = 1 / effectiveLifeSpan;
    double result = purchasePrice() * a * b;
    return result;
}

void Television::display() const {
    std::cout << std::endl;
    std::cout << std::left << std::setw(20) << "Asset ID:" << this->id() << std::endl;
    std::cout << std::left << std::setw(20) << "Brand:" << this->brand() << std::endl;
    std::cout << std::left << std::setw(20) << "Model:" << this->model() << std::endl;
    std::cout << std::left << std::setw(20) << "Purchase Price:" << "$" << std::setprecision(2) << std::fixed << this->purchasePrice() << std::endl;
    std::cout << std::left << std::setw(20) << "Purchase Date:" << this->purchaseDate().format() << std::endl;
    std::cout << std::left << std::setw(20) << "Depreciated Value:" /*<< this->calculateDepreciation()*/ << std::endl;
    std::cout << std::left << std::setw(20) << "Serial Number:" << this->serialNumber() << std::endl;
    std::cout << std::left << std::setw(20) << "Location:" << this->location() << std::endl;
    std::cout << std::endl;
}


