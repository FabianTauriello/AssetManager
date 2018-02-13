#ifndef ASSET_H
#define ASSET_H
#include "date.h"
#include <string>

/**
 * @brief The Asset class the abstract base class for an asset in the asset register.
 */
class Asset {
public:
  /**
   * @brief id retrieve the unique identifier for this asset.
   * @return the unique identifier
   */
  const std::string &id() const;
  /**
   * @brief purchaseDate
   * @return the date on which this asset was purchased.
   */
  const Date &purchaseDate() const;

  // TODO: fix return types of these accessor member functions
  void disposalDate() const;
  void brand() const;
  void model() const;
  void purchasePrice() const;

protected:
  /**
   * @brief Asset constructor for the base class asset
   * @param id the unique identifier for this asset
   * @param brand
   * @param model
   * @param purchasePrice
   * @param purchaseDate
   */
  Asset(const std::string &id, const std::string &brand, const std::string &model,
        double purchasePrice, const Date &purchaseDate);

private:
  std::string _id;    /**< a unique identifier for the asset */
  Date _purchaseDate; /**< the date on which the asset was purchased */
};

#endif // ASSET_H
