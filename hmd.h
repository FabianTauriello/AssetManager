#ifndef HMD_H
#define HMD_H
#include <memory>
#include <iomanip>
#include <iostream>
#include "asset.h"
#include "custodian.h"

/**
 * @brief The HMD class represents a Head Mounted Display in the asset register. It is a derived class of the Asset base class
 */
class HMD : public Asset {
public:
   /**
     * @brief HMD constructor for the HMD class
     * @param id the unique identifier for this asset
     * @param brand the brand for this hmd
     * @param model the model for this hmd
     * @param purchasePrice the purchasePrice for this hmd
     * @param purchaseDate the purchaseDate for this hmd
     * @param serialNumber the serial number for this hmd
     */
    HMD(const std::string &id, const std::string &brand, const std::string &model,
        double purchasePrice, const Date &purchaseDate, const std::string &serialNumber);

    /**
     * @brief serialNumber retrieve the serial number for a hmd
     * @return the serial number
     */
    const std::string &serialNumber() const;

    /**
     * @brief custodian retrieve the custodian for a hmd
     * @return the custodian for this hmd
     */
    const std::shared_ptr<Custodian> &custodian() const;

    /**
     * @brief setCustodian assign a hmd with a custodian
     * @param custodian the custodian to assign
     */
    void setCustodian(std::shared_ptr<Custodian> custodian);

    /**
     * @brief calculateDepreciation calculate depreciation of a hmd
     * @param date the date to calculate depreciation against
     * @return the calculated depreciation
     */
    double calculateDepreciation(const Date &date) const;

    /**
     * @brief display contents of hmd
     */
    void display() const;


private:
    std::string _serialNumber;
    std::shared_ptr<Custodian> _custodian;
};

#endif // HMD_H
