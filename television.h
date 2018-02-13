#ifndef TELEVISION_H
#define TELEVISION_H
#include "asset.h"
#include <iostream>
#include <iomanip>

/**
 * @brief The Television class represents a television in the asset register.
 */
class Television : public Asset {
public:
    /**
     * @brief Television constructor for the derived clas Television
     * @param id the unique identifier for this Television
     * @param brand brand the brand for this Television
     * @param model model the model for this Television
     * @param purchasePrice the purchase price for this Television
     * @param purchaseDate the purchase date for this Television
     * @param serialNumber the serial number for this Television
     * @param location the location for this Television
     */
    Television(const std::string &id, const std::string &brand, const std::string &model,
               double purchasePrice, const Date &purchaseDate,
               const std::string &serialNumber, const std::string &location);

    /**
     * @brief serialNumber retrieve the serial number for this television
     * @return a serial number
     */
    const std::string &serialNumber() const;

    /**
     * @brief location retrieve the location for this television
     * @return a location
     */
    const std::string &location() const;

    /**
     * @brief setLocation assign this television with a location
     * @param location the location to set
     */
    void setLocation(std::string location);

    /**
     * @brief calculateDepreciation calculate depreciation of a television
     * @param date the date to calculate depreciation against
     * @return the calculated depreciation
     */
    double calculateDepreciation(const Date &date) const;

    /**
     * @brief display contents of television
     */
    void display() const;

private:
    std::string _serialNumber;      /**< the serial number of a television */
    std::string _location;          /**< the location of a television */

};

#endif // TELEVISION_H
