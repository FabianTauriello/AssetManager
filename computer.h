#ifndef COMPUTER_H
#define COMPUTER_H
#include <memory>
#include "asset.h"
#include "custodian.h"
#include <iostream>
#include <iomanip>

/**
 * @brief The Computer class represents a computer in the asset register
 */
class Computer : public Asset {
public:
  /**
   * @brief Computer constructor for the derived class Computer
   * @param id the unique identifier for this computer
   * @param brand the brand for this computer
   * @param model the model for this computer
   * @param purchasePrice the purchase price for this computer
   * @param purchaseDate the purchase date for this computer
   * @param serialNumber the serial number for this computer
   * @param operatingSystem the operating system for this computer
   * @param laptop boolean flag for whether computer is a laptop or not
   */
  Computer(const std::string &id, const std::string &brand, const std::string &model,
           double purchasePrice, const Date &purchaseDate, const std::string &serialNumber,
           const std::string &operatingSystem, bool laptop);

  /**
   * @brief serialNumber retrieve the serial number of a computer
   * @return the serial number a computers serial number
   */
  const std::string &serialNumber() const;

  /**
   * @brief operatingSystem retrieve the operating system of a computer
   * @return the operating system operating system the computer runs on
   */
  const std::string &operatingSystem() const;

  /**
   * @brief networkIdentifier retrieve the network identifier of a computer
   * @return the network identifier a computers network identifier
   */
  const std::string &networkIdentifier() const;

  /**
   * @brief custodian retrieve the custodian to which the computer belongs
   * @return a custodian a computers custodian
   */
  const std::shared_ptr<Custodian> &custodian() const;

  /**
   * @brief setOperatingSystem set the operating system of a computer
   * @param operatingSystem the operating system to set a computer with
   */
  void setOperatingSystem(std::string operatingSystem);

  /**
   * @brief setCustodian assign a custodian to a computer
   * @param custodian a custodian
   */
  void setCustodian(const std::shared_ptr<Custodian> &custodian);
  void setNetworkIdentifier(const std::string networkIdentifier);

  /**
   * @brief calculateDepreciation calculate depreciation of a computer
   * @param date the date to calculate depreciation against
   * @return the calculated depreciation
   */
  double calculateDepreciation(const Date &date) const;

  /**
   * @brief display display contents of computer
   */
  void display() const;

private:
  std::string _serialNumber;                /**< the serial number of a computer */
  std::string _operatingSystem;             /**< the operating system of a computer */
  std::string _networkIdentifier;           /**< the network identifier of a computer */
  std::shared_ptr<Custodian> _custodian;    /**< shared pointer to a custodian object */
  bool _laptop;                             /**< boolean flag for determining if the computer is a laptop */
};

#endif // COMPUTER_H
