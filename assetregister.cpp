#include "assetregister.h"


AssetRegister &AssetRegister::instance() {
  static AssetRegister s_instance;
  return s_instance;
}

std::shared_ptr<Asset> AssetRegister::retrieveAsset(const std::string &assetId) {
  auto assetIt = _assets.find(assetId);
  if (assetIt != _assets.end()) {
    return assetIt->second;
  }
  return nullptr;
}

bool AssetRegister::storeAsset(std::shared_ptr<Asset> asset) {
  if (!_assets.count(asset->id())) {
    _assets[asset->id()] = std::shared_ptr<Asset>{asset};
    return true;
  }
  return false;
}

const std::map<std::string, std::shared_ptr<Asset> > &AssetRegister::assets() const {
    return _assets;
}

std::vector<Computer> &AssetRegister::computerCounter() {
    return _computerCounter;
}

std::vector<Phone> &AssetRegister::phoneCounter() {
    return _phoneCounter;
}

std::vector<Television> &AssetRegister::televisionCounter() {
    return _televisionCouter;
}

std::vector<HMD> &AssetRegister::hmdCounter() {
    return _hmdCounter;
}

AssetRegister::AssetRegister() {
}
