#ifndef COMPUTER_H
#define COMPUTER_H
#include "asset.h"

/**
 * @brief The Computer class represents a computer in the asset register
 */
class Computer : public Asset {
public:
  Computer(const std::string &id, const std::string &brand, const std::string &model,
           double purchasePrice, const Date &purchaseDate, const std::string &serial,
           const std::string &operatingSystem);
  // TODO: fix the return types of these accessor member functions
  void serialNumber() const;
  void operatingSystem() const;
  void networkIdentifier() const;
  void custodian() const;

  // TODO: Finish implementation of this class.
};

#endif // COMPUTER_H
