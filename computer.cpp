#include "computer.h"

Computer::Computer(const std::string &id, const std::string &brand, const std::string &model,
                   double purchasePrice, const Date &purchaseDate, const std::string &serialNumber,
                   const std::string &operatingSystem, bool laptop)
    : Asset{id, brand, model, purchasePrice, purchaseDate},
      _serialNumber{serialNumber},
      _operatingSystem{operatingSystem},
      _networkIdentifier{""},
      _custodian{nullptr},
      _laptop{laptop} {
}

const std::string &Computer::serialNumber() const {
    return _serialNumber;
}

const std::string &Computer::operatingSystem() const {
    return _operatingSystem;
}

const std::string &Computer::networkIdentifier() const {
    return _networkIdentifier;
}

const std::shared_ptr<Custodian> &Computer::custodian() const {
    return _custodian;
}

void Computer::setOperatingSystem(std::string operatingSystem) {
    _operatingSystem = operatingSystem;
}

void Computer::setCustodian(const std::shared_ptr<Custodian> &custodian)
{
    _custodian = custodian;
}

void Computer::setNetworkIdentifier(const std::string networkIdentifier) {
    _networkIdentifier = networkIdentifier;
}

double Computer::calculateDepreciation(const Date &date) const {
    double effectiveLifeSpan;
    // determine the effective life span based on the computer type
    if (_laptop) {
        effectiveLifeSpan = 3;
    } else {
        effectiveLifeSpan = 4;
    }
    double a = purchaseDate().differenceInDays(date) / 365;
    double b = 1 / effectiveLifeSpan;
    double result = purchasePrice() * a * b;
    return result;
}

void Computer::display() const {
    std::cout << std::endl;
    std::cout << std::left << std::setw(20) << "Asset ID:" << this->id() << std::endl;
    std::cout << std::left << std::setw(20) << "Brand:" << this->brand() << std::endl;
    std::cout << std::left << std::setw(20) << "Model:" << this->model() << std::endl;
    std::cout << std::left << std::setw(20) << "Purchase Price:" << "$" << std::setprecision(2) << std::fixed << this->purchasePrice() << std::endl;
    std::cout << std::left << std::setw(20) << "Purchase Date:" << this->purchaseDate().format() << std::endl;
    std::cout << std::left << std::setw(20) << "Depreciated Value:" /*<< this->calculateDepreciation()*/ << std::endl;
    std::cout << std::left << std::setw(20) << "Serial Number:" << this->serialNumber() << std::endl;
    std::cout << std::left << std::setw(20) << "Network Identifier:" << this->networkIdentifier() << std::endl;
    std::cout << std::left << std::setw(20) << "Operating System:" << this->operatingSystem() << std::endl;
    std::cout << std::left << std::setw(20) << "Custodian:" << this->custodian()->name() << std::endl;
    std::cout << std::left << std::setw(20) << "Last Maintenance:" << this->custodian()->name() << std::endl;
    std::cout << std::endl;
}

