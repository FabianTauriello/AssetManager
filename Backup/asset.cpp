#include "asset.h"

const std::string &Asset::id() const {
  return _id;
}

const Date &Asset::purchaseDate() const {
  return _purchaseDate;
}

// TODO: finish the implementation of the Asset constructor.
Asset::Asset(const std::string &id, const std::string &brand, const std::string &model,
             double purchasePrice, const Date &purchaseDate)
    : _id{id} {
}
