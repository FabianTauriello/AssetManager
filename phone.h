#ifndef PHONE_H
#define PHONE_H
#include <memory>
#include <iomanip>
#include <iostream>
#include "asset.h"
#include "custodian.h"

/**
 * @brief The Phone class represents a phone in the asset register. It is a derived class of the Asset base class
 */
class Phone : public Asset {
public:
    /**
     * @brief Phone constructor for the derived class Phone
     * @param id the unique identifier for this phone
     * @param brand the brand for this phone
     * @param model the model for this phone
     * @param purchasePrice the purchase price for this phone
     * @param purchaseDate the purchase date for this phone
     * @param serialNumber the serial number for this phone
     * @param operatingSystem the operating system for this phone
     * @param billingIdentifier the billing identifier for this phone
     * @param phoneNumber the phone number for this phone
     */
    Phone(const std::string &id, const std::string &brand, const std::string &model,
          double purchasePrice, const Date &purchaseDate, const std::string &serialNumber,
          const std::string &operatingSystem, const std::string &billingIdentifier,
          const std::string &phoneNumber);


    /**
     * @brief serialNumber retrieve the serial number for this phone
     * @return the serial number
     */
    const std::string &serialNumber() const;

    /**
     * @brief operatingSystem retrieve the operating system for this phone
     * @return the operating system
     */
    const std::string &operatingSystem() const;

    /**
     * @brief phoneNumber retrieve the phone number for this phone
     * @return the phone number for this phone
     */
    const std::string &phoneNumber() const;

    /**
     * @brief billingIdentifier retrieve the billing identifier for this phone
     * @return the billing identifier
     */
    const std::string &billingIdentifier() const;

    /**
     * @brief custodian retrieve the custodian for this phone
     * @return the custodian
     */
    const std::shared_ptr<Custodian> &custodian() const;

    /**
     * @brief setOperatingSystem set the operating system of a phone
     * @param operatingSystem the operating system to set a phone with
     */
    void setOperatingSystem(std::string operatingSystem);

    /**
     * @brief setPhoneNumber assign a phone number to a phone
     * @param phoneNumber a phone number
     */
    void setPhoneNumber(std::string phoneNumber);

    /**
     * @brief setBillingIdentifier assign a billing identifier to a phone
     * @param billingIdentifier a billing identifier
     */
    void setBillingIdentifier(std::string billingIdentifier);

    /**
     * @brief setCustodian assign a custodian to a phone
     * @param custodian a custodian
     */
    void setCustodian(std::shared_ptr<Custodian> custodian);

    /**
     * @brief calculateDepreciation calculate depreciation of a computer
     * @param date the date to calculate depreciation against
     * @return the calculated depreciation
     */
    double calculateDepreciation(const Date &date) const;

    /**
     * @brief display contents of phone
     */
    void display() const;

private:
    std::string _serialNumber;                /**< the serial number of a phone */
    std::string _operatingSystem;             /**< the operating system of a phone */
    std::string _billingIdentifier;           /**< the billing identifier of a phone */
    std::string _phoneNumber;                 /**< the phone number of a phone */
    std::shared_ptr<Custodian> _custodian;    /**< the custodian of a phone */
};

#endif // PHONE_H
