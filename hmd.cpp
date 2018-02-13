#include "hmd.h"

HMD::HMD(const std::string &id, const std::string &brand, const std::string &model,
         double purchasePrice, const Date &purchaseDate, const std::string &serialNumber)
    : Asset{id, brand, model, purchasePrice, purchaseDate},
      _serialNumber{serialNumber},
      _custodian{nullptr} {
}

const std::string &HMD::serialNumber() const {
    return _serialNumber;
}

void HMD::setCustodian(std::shared_ptr<Custodian> custodian) {
    _custodian = custodian;
}

const std::shared_ptr<Custodian> &HMD::custodian() const {
    return _custodian;
}

double HMD::calculateDepreciation(const Date &date) const {
    double effectiveLifeSpan = 2.5;
    double a = purchaseDate().differenceInDays(date) / 365;
    double b = 1 / effectiveLifeSpan;
    double result = purchasePrice() * a * b;
    return result;
}

void HMD::display() const {
    std::cout << std::endl;
    std::cout << std::left << std::setw(20) << "Asset ID:" << this->id() << std::endl;
    std::cout << std::left << std::setw(20) << "Brand:" << this->brand() << std::endl;
    std::cout << std::left << std::setw(20) << "Model:" << this->model() << std::endl;
    std::cout << std::left << std::setw(20) << "Purchase Price:" << "$" << std::setprecision(2) << std::fixed << this->purchasePrice() << std::endl;
    std::cout << std::left << std::setw(20) << "Purchase Date:" << this->purchaseDate().format() << std::endl;
    std::cout << std::left << std::setw(20) << "Depreciated Value:" /*<< this->calculateDepreciation()*/ << std::endl;
    std::cout << std::left << std::setw(20) << "Serial Number:" << this->serialNumber() << std::endl;
    std::cout << std::left << std::setw(20) << "Custodian:" << this->custodian()->name() << std::endl;
    //std::cout << std::left << std::setw(20) << "Last Maintenance:" << this->custodian()->name() << std::endl;
    std::cout << std::endl;
}
