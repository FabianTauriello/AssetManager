#include "assetregister.h"
#include "assettesting.h"
#include <algorithm>
#include <cstring>
#include <ctime>
#include <limits>

#if TESTING_CUSTODIAN
#include "custodian.h"
#endif

#if TESTING_COMPUTER
#include "computer.h"
#endif

#if TESTING_PHONE
#include "phone.h"
#endif

#if TESTING_HMD
#include "hmd.h"
#endif

#if TESTING_TELEVISION
#include "television.h"
#endif

const double AssetTesting::s_maxEpsilon = std::max(std::numeric_limits<double>::epsilon(), 0.0001);

AssetTesting::AssetTesting()
    : _randomEngine{static_cast<uint32_t>(time(NULL))}, _dateDistribution{nullptr} {
}

AssetTesting::~AssetTesting() {
  if (_dateDistribution != nullptr) {
    delete _dateDistribution;
  }
}

void AssetTesting::initialize() {
  prepareRandomDateGenerator();
}

std::string AssetTesting::testDate() {
  bool failure{false};

  return failure ? "Failed" : "Passed";
}

std::string AssetTesting::testAsset() {
  // Test Concrete Asset class - verify operation of Asset as per original specifications.
  bool failure{false};
  std::string id{"asset123"};
  std::string brand{"AwesomeBrand!"};
  std::string model{"The232"};
  double price{1000.99};
  Date purchaseDate(7, Date::May, 2012);
  std::string serial = generateSerialNumber();
  ConcreteAsset conAsset{id, brand, model, price, purchaseDate, serial};
  if (conAsset.id() != id) {
    _failMessages << "Asset .id() does not match constructor argument." << std::endl;
    failure = true;
  }
  if (conAsset.brand() != brand) {
    _failMessages << "Asset .brand() does not match constructor argument." << std::endl;
    failure = true;
  }
  if (conAsset.model() != model) {
    _failMessages << "Asset .model() does not match constructor argument." << std::endl;
    failure = true;
  }
  if (conAsset.purchasePrice() != price) {
    _failMessages << "Asset .price() does not match constructor argument." << std::endl;
    failure = true;
  }
  if (conAsset.purchaseDate() != purchaseDate) {
    _failMessages << "Asset .purchaseDate() does not match constructor argument." << std::endl;
    failure = true;
  }
  if (conAsset.serialNumber() != serial) {
    _failMessages << "ConcreteAsset .serialNumber() does not match constructor argument. This "
                     "should not happen!"
                  << std::endl;
    failure = true;
  }
  // Test through pointer.
  std::shared_ptr<Asset> asset =
      std::make_shared<ConcreteAsset>(id, brand, model, price, purchaseDate, serial);
  failure = !validateAsset(asset, id, brand, model, price, purchaseDate, "Asset") || failure;
  return failure ? "Failed" : "Passed";
}

std::string AssetTesting::testComputer() {
#if TESTING_COMPUTER
  std::string type{"Computer"};
  bool failure = false;
  std::string os;
  std::shared_ptr<Computer> comp = generateComputer(os);
  failure = !validateAsset<Computer>(comp, type) || failure;
  failure = !testAssetCustodian<Computer>(comp, type) || failure;
  failure = !testDeprecation(type) || failure;
  if (comp->operatingSystem() != os) {
    _failMessages << type << " ->operatingSystem() does not match constructor argument."
                  << std::endl;
    failure = true;
  }
  // Update operating system
  os = "Windows 11";
  comp->setOperatingSystem(os);
  if (comp->operatingSystem() != os) {
    _failMessages << type << " ->operatingSystem() does not match ->setOperatingSystem() argument."
                  << std::endl;
    failure = true;
  }
  // Update operating system
  os = "Windows 11";
  comp->setOperatingSystem(os);
  if (comp->operatingSystem() != os) {
    _failMessages << type << " ->operatingSystem() does not match ->setOperatingSystem() argument."
                  << std::endl;
    failure = true;
  }
  return failure ? "Failed" : "Passed";
#else
  return "Skipped";
#endif
}

std::string AssetTesting::testPhone() {
#if TESTING_PHONE
  std::string type{"Phone"};
  bool failure{false};
  std::string os;
  std::string billingId;
  std::string phoneNumber;
  std::shared_ptr<Phone> phone = generatePhone(os, billingId, phoneNumber);
  failure = !validateAsset<Phone>(phone, type) || failure;
  failure = !testAssetCustodian<Phone>(phone, type) || failure;
  failure = !testDeprecation(type) || failure;
  if (phone->operatingSystem() != os) {
    _failMessages << type << " ->operatingSystem() does not match constructor argument."
                  << std::endl;
    failure = true;
  }
  if (phone->billingIdentifier() != billingId) {
    _failMessages << type << " ->billingIdentifier() does not match constructor argument."
                  << std::endl;
    failure = true;
  }
  if (phone->phoneNumber() != phoneNumber) {
    _failMessages << type << " ->phoneNumber() does not match constructor argument." << std::endl;
    failure = true;
  }
  // Update phone number
  phoneNumber = "0712348765";
  phone->setPhoneNumber(phoneNumber);
  if (phone->phoneNumber() != phoneNumber) {
    _failMessages << type << " ->phoneNumber() does not match ->setPhoneNumber() argument."
                  << std::endl;
    failure = true;
  }
  // Update billing identifier
  billingId = "AAA48765";
  phone->setBillingIdentifier(billingId);
  if (phone->billingIdentifier() != billingId) {
    _failMessages << type
                  << " ->billingIdentifier() does not match ->setBillingIdentifier() argument."
                  << std::endl;
    failure = true;
  }
  // Update os
  os = "Android 8";
  phone->setOperatingSystem(os);
  if (phone->operatingSystem() != os) {
    _failMessages << type << " ->operatingSystem() does not match ->setOperatingSystem() argument."
                  << std::endl;
    failure = true;
  }
  return failure ? "Failed" : "Passed";
#else
  return "Skipped";
#endif
}

std::string AssetTesting::testTelevision() {
#if TESTING_TELEVISION
  std::string type{"Television"};
  bool failure{false};
  std::string location;
  std::shared_ptr<Television> tv = generateTelevision(location);
  failure = !validateAsset<Television>(tv, type) || failure;
  failure = !testDeprecation(type) || failure;
  if (tv->location() != location) {
    _failMessages << type << " ->location() does not match constructor argument." << std::endl;
    failure = true;
  }
  // Update location
  location = "Grand Hall";
  tv->setLocation(location);
  if (tv->location() != location) {
    _failMessages << type << " ->location() does not match setLocation() argument." << std::endl;
    failure = true;
  }
  return failure ? "Failed" : "Passed";
#else
  return "Skipped";
#endif
}

std::string AssetTesting::testHMD() {
#if TESTING_HMD
  std::string type{"HMD"};
  bool failure{false};
  std::shared_ptr<HMD> hmd = generateHMD();
  failure = !validateAsset<HMD>(hmd, type) || failure;
  failure = !testAssetCustodian<HMD>(hmd, type) || failure;
  failure = !testDeprecation(type) || failure;
  return failure ? "Failed" : "Passed";
#else
  return "Skipped";
#endif
}

std::string AssetTesting::testCustodian() {
#if TESTING_CUSTODIAN
  bool failure{false};
  std::string name{"David Webb"};
  std::string department{"ITMS"};
  std::string phone{"(08) 8302 3582"};
  Date employmentStart{15, Date::February, 2016};
  Custodian cust{name, department, phone, employmentStart};
  if (cust.name() != name) {
    _failMessages << "Custodian name() does not match constructor argument." << std::endl;
    failure = true;
  }
  if (cust.department() != department) {
    _failMessages << "Custodian department() does not match constructor argument." << std::endl;
    failure = true;
  }
  if (cust.phoneNumber() != phone) {
    _failMessages << "Custodian phoneNumber() does not match constructor argument." << std::endl;
    failure = true;
  }
  if (cust.employmentStart() != employmentStart) {
    _failMessages << "Custodian employmentStart() does not match constructor argument."
                  << std::endl;
    failure = true;
  }
  // Update department
  department = "ITEE";
  cust.setDepartment(department);
  if (cust.department() != department) {
    _failMessages << "Custodian department() does not match setDepartment() argument." << std::endl;
    failure = true;
  }
  // Update phone number
  phone = "1300 864 669";
  cust.setPhoneNumber(phone);
  if (cust.phoneNumber() != phone) {
    _failMessages << "Custodian phoneNumber() does not match setPhoneNumber() argument."
                  << std::endl;
    failure = true;
  }
  return failure ? "Failed" : "Passed";
#else
  return "Skipped";
#endif
}

void AssetTesting::printFailures(std::ostream &ostream) {
  if (_failMessages.rdbuf()->in_avail()) {
    ostream << "Failures:" << std::endl;
    ostream << _failMessages.rdbuf() << std::endl;
  }
}

std::string AssetTesting::generateSerialNumber() {
  static std::uniform_int_distribution<int> lenGen(10, 30);
  std::string serial;
  size_t length = lenGen(_randomEngine);
  serial.resize(length);
  for (size_t i = 0; i < length; ++i) {
    serial[i] = randomCharacter();
  }
  return serial;
}

std::string AssetTesting::generateAssetId() {
  std::string id = generateSerialNumber(); // Serial number implementation will suffice
  while (AssetRegister::instance().retrieveAsset(id) != nullptr) {
    id = generateSerialNumber();
  }
  return id;
}

void AssetTesting::prepareRandomDateGenerator() {
  Date minDate(1, Date::January, 1990);
  Date maxDate{Date::currentDate()};
  tm minTm = minDate;
  tm maxTm = maxDate;
  time_t minDateTime = mktime(&minTm);
  time_t maxDateTime = mktime(&maxTm);
  _dateDistribution = new std::uniform_int_distribution<long long>(minDateTime, maxDateTime);
}

Date AssetTesting::generateRandomDate() {
  time_t date{static_cast<time_t>((*_dateDistribution)(_randomEngine))};
  tm *dateTm{gmtime(&date)};
  return Date(dateTm->tm_mday, static_cast<Date::Month>(dateTm->tm_mon), dateTm->tm_year + 1900);
}

char AssetTesting::randomCharacter() {
  static std::uniform_int_distribution<int> index(
      0, static_cast<int>(std::strlen(AssetTesting::s_validCharacters) - 1));
  return s_validCharacters[index(_randomEngine)];
}

void AssetTesting::generateAssetDetails(double price, Date purchaseDate) {
  static std::uniform_real_distribution<double> priceDist(100, 10000);
  std::string id{generateAssetId()};
  // Use random strings here; the values do not need to make sense for testing.
  std::string brand{generateSerialNumber()};
  std::string model{generateSerialNumber()};
  if (price == 0.0) {
    price = priceDist(_randomEngine);
  }
  if (!purchaseDate.valid()) {
    purchaseDate = generateRandomDate();
  }
  _asset = std::make_shared<ConcreteAsset>(id, brand, model, price, purchaseDate,
                                           generateSerialNumber());
}

std::shared_ptr<Custodian> AssetTesting::generateCustodian() {
#if TESTING_CUSTODIAN
  std::string name{"David Webb"};
  std::string department{"ITMS"};
  std::string phone{"(08) 8302 3582"};
  Date employmentStart{15, Date::February, 2016};
  return std::make_shared<Custodian>(name, department, phone, employmentStart);
#else
  return nullptr;
#endif
}

ConcreteAsset::ConcreteAsset(const std::string &id, const std::string &brand,
                             const std::string &model, double purchasePrice,
                             const Date &purchaseDate, const std::string &serialNumber)
    : Asset(id, brand, model, purchasePrice, purchaseDate), _serialNumber{serialNumber} {
}

std::string ConcreteAsset::serialNumber() const {
  return _serialNumber;
}

double ConcreteAsset::calculateDepreciation(const Date &/*date*/) const {
  return 0;
}

std::shared_ptr<Computer> AssetTesting::generateComputer(std::string &os, bool laptop, double price,
                                                         Date purchaseDate) {
#if TESTING_COMPUTER
  // Select an operating system.
  static std::string oses[] = {"Windows XP", "Windows 7", "Windows 8.1",
                               "Windows 10", "macOS",     "Linux"};
  static std::uniform_int_distribution<int> osDist(0, 5);

  generateAssetDetails(price, purchaseDate);
  os = oses[osDist(_randomEngine)];
  return std::make_shared<Computer>(_asset->id(), _asset->brand(), _asset->model(),
                                    _asset->purchasePrice(), _asset->purchaseDate(),
                                    _asset->_serialNumber, os, laptop);
#else
  return nullptr;
#endif
}

std::shared_ptr<Phone> AssetTesting::generatePhone(std::string &os, std::string &billingId,
                                                   std::string &phoneNumber, double price,
                                                   Date purchaseDate) {
#if TESTING_PHONE
  // Select an operating system.
  static std::string oses[] = {"Windows Phone", "Android 7", "Android 6", "iOS10", "iOS11", "None"};
  static std::uniform_int_distribution<int> osDist(0, 5);

  generateAssetDetails(price, purchaseDate);
  os = oses[osDist(_randomEngine)];
  billingId = generateSerialNumber();
  phoneNumber = generateSerialNumber();
  return std::make_shared<Phone>(_asset->id(), _asset->brand(), _asset->model(),
                                 _asset->purchasePrice(), _asset->purchaseDate(),
                                 _asset->_serialNumber, os, billingId, phoneNumber);
#else
  return nullptr;
#endif
}

std::shared_ptr<Television> AssetTesting::generateTelevision(std::string &location, double price,
                                                             Date purchaseDate) {
#if TESTING_TELEVISION
  generateAssetDetails(price, purchaseDate);

  location = generateSerialNumber();
  return std::make_shared<Television>(_asset->id(), _asset->brand(), _asset->model(),
                                      _asset->purchasePrice(), _asset->purchaseDate(),
                                      _asset->_serialNumber, location);
#else
  return nullptr;
#endif
}

std::shared_ptr<HMD> AssetTesting::generateHMD(double price, Date purchaseDate) {
#if TESTING_HMD
  generateAssetDetails(price, purchaseDate);
  return std::make_shared<HMD>(_asset->id(), _asset->brand(), _asset->model(),
                               _asset->purchasePrice(), _asset->purchaseDate(),
                               _asset->_serialNumber);
#else
  return nullptr;
#endif
}

bool AssetTesting::testDeprecation(const std::string &type) {
  bool failure{false};
  if (type == "Computer") {
#if TESTING_COMPUTER
    std::string os;
    std::shared_ptr<Computer> comp =
        generateComputer(os, false, 100.0, Date(1, Date::January, 2015));
    double result = comp->calculateDepreciation(Date(1, Date::January, 2016));
    if (std::abs(result - 25.0) > s_maxEpsilon) {
      _failMessages << type
                    << " ->calculateDepriciation() returned incorrect value, expected 25.0, got "
                    << result << std::endl;
      failure = true;
    }

    comp = generateComputer(os, true, 100.0, Date(1, Date::January, 2015));
    result = comp->calculateDepreciation(Date(1, Date::January, 2016));
    if (std::abs(result - 33.33333) > s_maxEpsilon) {
      _failMessages << type
                    << " ->calculateDepriciation() returned incorrect value, expected 25.0, got "
                    << result << std::endl;
      failure = true;
    }
#endif
  } else if (type == "Phone") {
#if TESTING_PHONE
    std::string os;
    std::string billing;
    std::string number;
    std::shared_ptr<Phone> phone =
        generatePhone(os, billing, number, 100.0, Date(1, Date::January, 2015));
    double result = phone->calculateDepreciation(Date(1, Date::January, 2016));
    if (std::abs(result - 50.0) > s_maxEpsilon) {
      _failMessages << type
                    << " ->calculateDepriciation() returned incorrect value, expected 25.0, got "
                    << result << std::endl;
      failure = true;
    }
#endif
  } else if (type == "Television") {
#if TESTING_TELEVISION
    std::string location;
    std::shared_ptr<Television> tv =
        generateTelevision(location, 100.0, Date(1, Date::January, 2015));
    double result = tv->calculateDepreciation(Date(1, Date::January, 2016));
    if (std::abs(result - 16.66666) > s_maxEpsilon) {
      _failMessages << type
                    << " ->calculateDepriciation() returned incorrect value, expected 16.6666, got "
                    << result << std::endl;
      failure = true;
    }
#endif
  } else if (type == "HMD") {
#if TESTING_HMD
    std::shared_ptr<HMD> hmd = generateHMD(100.0, Date(1, Date::January, 2015));
    double result = hmd->calculateDepreciation(Date(1, Date::January, 2016));
    if (std::abs(result - 40.0) > s_maxEpsilon) {
      _failMessages << type
                    << " ->calculateDepriciation() returned incorrect value, expected 25.0, got "
                    << result << std::endl;
      failure = true;
    }
#endif
  }
  return !failure;
}

const char *AssetTesting::s_validCharacters = "abcdefghijklmnopqrstuvwxyz"
                                              "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                              "123567890-/.";
