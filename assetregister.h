#ifndef ASSETREGISTER_H
#define ASSETREGISTER_H
#include "asset.h"
#include <map>
#include <memory>
#include <iostream>
#include <vector>
#include "computer.h"
#include "phone.h"
#include "hmd.h"
#include "television.h"

/* NOTE: to students - DO NOT modify or remove existing members of this class.
 * If required, you may add methods to this class. */

/**
 * @brief The AssetRegister class represents the data store for the asset management system.
 * AssetRegister follows the singleton design pattern - which allows only one
 * instance of a class through hiding the class constructor and creating and accessing
 * the static class instance through a static member function.
 */
class AssetRegister {
public:
  /**
   * @brief instance retrieve the one and only instance of the AssetRegister class.
   * @return the static instance of the AssetRegister class
   */
  static AssetRegister &instance();

  /**
   * @brief retrieveAsset Retrieve an asset from the asset register by asset id.
   * @param assetId the asset id to search for.
   * @return a shared pointer to the asset or a nullptr if the asset does not exist.
   */
  std::shared_ptr<Asset> retrieveAsset(const std::string &assetId);

  /**
   * @brief storeAsset Store an asset in the asset register.
   * @param asset the asset to store.
   * @return true if the asset was stored, false if the asset id is not unique.
   */
  bool storeAsset(std::shared_ptr<Asset> asset);

  /**
   * @brief assets retriece the a map of all assets in the register
   * @return the assets map
   */
  const std::map<std::string, std::shared_ptr<Asset>> &assets() const;

  /**
   * @brief computerCounter retrieve a vector of computers in the asset register
   * @return the computer vector
   */
  std::vector<Computer> &computerCounter();

  /**
   * @brief phoneCounter retrieve a vector of phones in the asset register
   * @return the phone vector
   */
  std::vector<Phone> &phoneCounter();

  /**
   * @brief televisionCounter retrieve a vector of televisions in the asset register
   * @return the television vector
   */
  std::vector<Television> &televisionCounter();

  /**
   * @brief hmdCounter retrieve a vector of HMDs in the asset register
   * @return the HMD vector
   */
  std::vector<HMD> &hmdCounter();

private:
  std::map<std::string, std::shared_ptr<Asset>> _assets; /**< stores all the assets, by asset id*/
  std::vector<Computer> _computerCounter;                /**< stores all computers in the asset register */
  std::vector<Phone> _phoneCounter;                      /**< stores all phones in the asset register */
  std::vector<Television> _televisionCouter;             /**< stores all televisions in the asset register */
  std::vector<HMD> _hmdCounter;                          /**< stores all hmds in the asset register */

  // Private constructor for singleton pattern.
  AssetRegister();
  // Remove copy constructor and assignment operator
  AssetRegister(const AssetRegister &) = delete;
  void operator=(const AssetRegister &) = delete;
};

#endif // ASSETREGISTER_H
