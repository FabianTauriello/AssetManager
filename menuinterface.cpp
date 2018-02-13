#include "menuinterface.h"
#include "assetregister.h"
#include <limits>
#include <string>
#include <list>
#include <cstdlib>
//#include <map>

MenuInterface::MenuInterface(std::ostream &display, std::istream &input)
    : _display{display}, _input{input} {
}

void MenuInterface::displayMainMenu() const {
    _display << "What would you like to do?" << std::endl;
    _display << " (a)dd an asset" << std::endl;
    _display << " (d)ispose an asset" << std::endl;
    _display << " (u)pdate asset custodian or location" << std::endl;
    _display << " add asset (m)aintenance record" << std::endl;
    _display << " (l)ist assets by type" << std::endl;
    _display << " List assets by (c)ustodian" << std::endl;
    _display << " (f)ind asset" << std::endl;
    _display << " (q)uit" << std::endl;

}

char MenuInterface::getCharacterInput() const {
    char input;
    // grab input from user
    _input >> input;
    // clear buffer till the next newline character
    _input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //std::_display << input << std::endl;
    return input;
}

void MenuInterface::displayComputer(const Computer &computer) const {
    char control;
    _display << std::endl;
    _display << std::left << std::setw(20) << "Asset ID:" << computer.id() << std::endl;
    _display << std::left << std::setw(20) << "Brand:" << computer.brand() << std::endl;
    _display << std::left << std::setw(20) << "Model:" << computer.model() << std::endl;
    _display << std::left << std::setw(20) << "Purchase Price:" << "$" << std::setprecision(2) << std::fixed << computer.purchasePrice() << std::endl;
    _display << std::left << std::setw(20) << "Purchase Date:" << computer.purchaseDate().format() << std::endl;
    _display << std::left << std::setw(20) << "Depreciated Value:" /*<< computer.calculateDepreciation()*/ << std::endl;
    _display << std::left << std::setw(20) << "Serial Number:" << computer.serialNumber() << std::endl;
    _display << std::left << std::setw(20) << "Network Identifier:" << computer.networkIdentifier() << std::endl;
    _display << std::left << std::setw(20) << "Operating System:" << computer.operatingSystem() << std::endl;
    _display << std::left << std::setw(20) << "Custodian:" << computer.custodian()->name() << std::endl;
    //_display << std::left << std::setw(20) << "Last Maintenance:" << computer.custodian()->name() << std::endl;
    _display << std::endl;
    _display << "(c)ustodian details" << std::endl;
    _display << "(m)aintenance history" << std::endl;
    _display << "(b)ack to main menu" << std::endl;
    _display << std::endl;
    _input >> control;

    switch (control) {
    case 'c': {
        break;
    }
    case 'm': {
        break;
    }
    case 'b': {
        displayMainMenu();
        break;
    }
    default:
        break;
    }
}

void MenuInterface::displayTelevision(const Television television) const {
    char control;
    _display << std::endl;
    _display << std::left << std::setw(20) << "Asset ID:" << television.id() << std::endl;
    _display << std::left << std::setw(20) << "Brand:" << television.brand() << std::endl;
    _display << std::left << std::setw(20) << "Model:" << television.model() << std::endl;
    _display << std::left << std::setw(20) << "Purchase Price:" << "$" << std::setprecision(2) << std::fixed << television.purchasePrice() << std::endl;
    _display << std::left << std::setw(20) << "Purchase Date:" << television.purchaseDate().format() << std::endl;
    _display << std::left << std::setw(20) << "Depreciated Value:" /*<< television.calculateDepreciation()*/ << std::endl;
    _display << std::left << std::setw(20) << "Serial Number:" << television.serialNumber() << std::endl;
    _display << std::left << std::setw(20) << "Location:" << television.location() << std::endl;
    _display << std::endl;
    _display << "(m)aintenance history" << std::endl;
    _display << "(b)ack to main menu" << std::endl;
    _display << std::endl;
    _input >> control;

    switch (control) {
    case 'm': {
        break;
    }
    case 'b': {
        displayMainMenu();
        break;
    }
    default:
        break;
    }
}

void MenuInterface::displayHMD(const HMD hmd) const {
    char control;
    _display << std::endl;
    _display << std::left << std::setw(20) << "Asset ID:" << hmd.id() << std::endl;
    _display << std::left << std::setw(20) << "Brand:" << hmd.brand() << std::endl;
    _display << std::left << std::setw(20) << "Model:" << hmd.model() << std::endl;
    _display << std::left << std::setw(20) << "Purchase Price:" << "$" << std::setprecision(2) << std::fixed << hmd.purchasePrice() << std::endl;
    _display << std::left << std::setw(20) << "Purchase Date:" << hmd.purchaseDate().format() << std::endl;
    _display << std::left << std::setw(20) << "Depreciated Value:" /*<< hmd.calculateDepreciation()*/ << std::endl;
    _display << std::left << std::setw(20) << "Serial Number:" << hmd.serialNumber() << std::endl;
    _display << std::left << std::setw(20) << "Custodian:" << hmd.custodian()->name() << std::endl;
    //_display << std::left << std::setw(20) << "Last Maintenance:" << hmd.custodian()->name() << std::endl;
    _display << std::endl;
    _display << "(c)ustodian details" << std::endl;
    _display << "(m)aintenance history" << std::endl;
    _display << "(b)ack to main menu" << std::endl;
    _display << std::endl;
    _input >> control;

    switch (control) {
    case 'c': {
        break;
    }
    case 'm': {
        break;
    }
    case 'b': {
        displayMainMenu();
        break;
    }
    default:
        break;
    }
}

void MenuInterface::displayPhone(const Phone phone) const {
    char control;
    _display << std::endl;
    _display << std::left << std::setw(20) << "Asset ID:" << phone.id() << std::endl;
    _display << std::left << std::setw(20) << "Brand:" << phone.brand() << std::endl;
    _display << std::left << std::setw(20) << "Model:" << phone.model() << std::endl;
    _display << std::left << std::setw(20) << "Phone Number:" << phone.phoneNumber() << std::endl;
    _display << std::left << std::setw(20) << "Purchase Price:" << "$" << std::setprecision(2) << std::fixed << phone.purchasePrice() << std::endl;
    _display << std::left << std::setw(20) << "Purchase Date:" << phone.purchaseDate().format() << std::endl;
    _display << std::left << std::setw(20) << "Depreciated Value:" /*<< phone.calculateDepreciation()*/ << std::endl;
    _display << std::left << std::setw(20) << "Serial Number:" << phone.serialNumber() << std::endl;
    _display << std::left << std::setw(20) << "Billing Identifier:" << phone.billingIdentifier() << std::endl;
    _display << std::left << std::setw(20) << "Operating System:" << phone.operatingSystem() << std::endl;
    _display << std::left << std::setw(20) << "Custodian:" << phone.custodian()->name() << std::endl;
    //_display << std::left << std::setw(20) << "Last Maintenance:" << phone.custodian()->name() << std::endl;
    _display << std::endl;
    _display << "(c)ustodian details" << std::endl;
    _display << "(m)aintenance history" << std::endl;
    _display << "(b)ack to main menu" << std::endl;
    _display << std::endl;
    _input >> control;

    switch (control) {
    case 'c': {
        break;
    }
    case 'm': {
        break;
    }
    case 'b': {
        displayMainMenu();
        break;
    }
    default:
        break;
    }
}

void MenuInterface::displayCustodianDetails(const Asset &asset) const {

}

bool MenuInterface::processSelection(char selection) {
    switch (selection) {
    case 'a':
        addAsset();
        break;
    case 'd':
        disposeAsset();
        break;
    case 'u':
        updateAsset();
        break;
    case 'm':
        addMaintenance();
        break;
    case 'l':
        listAssetsByType();
        break;
    case 'c':
        listAssetsByCustodian();
        break;
    case 'f':
        findAsset();
        break;
    case 'q':
        exit(0);
        return false;
    default:
        _display << "Sorry, \'" << selection << "\' is not a valid option, please try again."
                 << std::endl;
    }
    return true;
}

void MenuInterface::addAsset() {
    // TODO: implement this member function.
    _display << "Add an asset" << std::endl;
    _display << " add a (c)omputer" << std::endl;
    _display << " add a (p)hone" << std::endl;
    _display << " add a (t)elevision" << std::endl;
    _display << " add a (h)md" << std::endl;
    _display << " (b)ack to main menu" << std::endl;

    char input;
    _input >> input;
    //    _display << "You pressed: " << input << std::endl;

    std::string brand;
    std::string model;
    double purchasePrice;
    std::string purchaseDate;
    std::string serialNumber;
    std::string operatingSystem;
    std::string networkIdenifier;
    std::string billingIdentifier;
    std::string custName;
    std::string custDept;
    std::string custPhoneNumber;
    std::string cStartDate;
    std::string phoneNumber;
    std::string location;
    int dateNumber;
    char lapQuestion;
    bool laptop;
    char confirmation;

    switch(input) {
    case 'c': {
        _display << "To add a computer, please enter the following details:" << std::endl;
        _display << "  Brand: ";
        _input >> brand;
        _display << "  Model: ";
        _input >> model;
        _display << "  Purchase Price: ";
        while(!(_input >> purchasePrice)) {
            _display << "  Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        _display << "  Purchase Date: " << std::endl;
        _display << "   Enter day of month (as a number, 1-31): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 31)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        _display << "   Enter month of year (as a number, 1-12): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 12)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        _display << "   Enter year (as a number, 1900-2017): ";
        while(!(_input >> dateNumber) || (dateNumber < 1900 || dateNumber > 2017)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        Date newDate = checkDate(purchaseDate);
        _display << "  Serial Number: ";
        _input >> serialNumber;
        _display << "  Operating System: ";
        _input >> operatingSystem;
        _display << "  Network Identifier: ";
        _input >> networkIdenifier;
        _display << "  Custodian: " << std::endl;
        _display << "   Custodian Name: ";
        _input >> custName;
        _display << "   Custodian Department: ";
        _input >> custDept;
        _display << "   Custodian Phone Number: ";
        _input >> custPhoneNumber;
        _display << "   Custodian Start date: " << std::endl;
        _display << "    Enter day of month (as a number, 1-31): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 31)) {
            _display << "    Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        cStartDate.append(std::to_string(dateNumber)).append("/");
        _display << "    Enter month of year (as a number, 1-12): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 12)) {
            _display << "    Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        cStartDate.append(std::to_string(dateNumber)).append("/");
        _display << "    Year (enter a number, 1900-2017): ";
        while(!(_input >> dateNumber) || (dateNumber < 1900 || dateNumber > 2017)) {
            _display << "    Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        cStartDate.append(std::to_string(dateNumber)).append("/");
        Date custStartDate = checkDate(cStartDate);
        _display << "  Is it a laptop (Y/N)?: ";
        _input >> lapQuestion;
        while(tolower(lapQuestion) != 'y' && tolower(lapQuestion) != 'n') {
            _display << "  Please enter the letter 'y' for yes or 'n' for no: ";
            _input >> lapQuestion;
        }


        if(tolower(lapQuestion) == 'y') {
            laptop = true;
        } else {
            laptop = false;
        }

        _display << "\nAre you sure you want to add the asset?" << std::endl << "(press Y to confirm or any other character to cancel) ";
        _input >> confirmation;
        if(tolower(confirmation) == 'y') {
            // make a new asset id using asset prefix and asset register map count
            std::string id1 = "comp";
            std::string id2 = std::to_string(AssetRegister::instance().computerCounter().size() + 1);
            std::string id = id1 + id2;
            // construct new computer with inputs from user
            Computer newComputer(id, brand, model, purchasePrice, newDate, serialNumber, operatingSystem, laptop);
            newComputer.setNetworkIdentifier(networkIdenifier);
            // create a new custodian
            Custodian custodian(custName, custDept, custPhoneNumber, custStartDate);
            // create a new custodian shared pointer
            std::shared_ptr<Custodian> newCustodian(new Custodian(custodian));
            // set pointer to new asset
            newComputer.setCustodian(newCustodian);
            // create a new Asset shared pointer
            std::shared_ptr<Computer> assetPointer(new Computer(newComputer));
            // add new computer to asset register instance
            AssetRegister::instance().storeAsset(assetPointer);
            //std::_display << AssetRegister::instance().computerCounter().size() << std::endl;
            AssetRegister::instance().computerCounter().push_back(newComputer);
            //std::_display << AssetRegister::instance().computerCounter().size() << std::endl;
            _display << "\n***************************************************************" << std::endl;
            _display << "...Asset has been added to the register!" << " Asset id is " << id << std::endl;
            _display << "***************************************************************\n" << std::endl;
            //std::_display << newComputer.serialNumber();
        } else {
            _display << "...Operation cancelled\n" << std::endl;
            addAsset();
        }
        break;
    }
    case 'p': {
        _display << "To add a phone, please enter the following details:" << std::endl;
        _display << "  Phone Number: ";
        _input >> phoneNumber;
        _display << "  Brand: ";
        _input >> brand;
        _display << "  Model: ";
        _input >> model;
        _display << "  Purchase Price: ";
        while(!(_input >> purchasePrice)) {
            _display << "  Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        _display << "  Purchase Date: " << std::endl;
        _display << "   Enter day of month (as a number, 1-31): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 31)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        _display << "   Enter month of year (as a number, 1-12): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 12)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        _display << "   Enter year (as a number, 1900-2017): ";
        while(!(_input >> dateNumber) || (dateNumber < 1900 || dateNumber > 2017)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        Date newDate = checkDate(purchaseDate);
        _display << "  Serial Number: ";
        _input >> serialNumber;
        _display << "  Operating System: ";
        _input >> operatingSystem;
        _display << "  Billing Identifier: ";
        _input >> billingIdentifier;
        _display << "  Custodian: " << std::endl;
        _display << "   Custodian Name: ";
        _input >> custName;
        _display << "   Custodian Department: ";
        _input >> custDept;
        _display << "   Custodian Phone Number: ";
        _input >> custPhoneNumber;
        _display << "   Custodian Start date: " << std::endl;
        _display << "    Enter day of month (as a number, 1-31): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 31)) {
            _display << "    Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        cStartDate.append(std::to_string(dateNumber)).append("/");
        _display << "    Enter month of year (as a number, 1-12): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 12)) {
            _display << "    Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        cStartDate.append(std::to_string(dateNumber)).append("/");
        _display << "    Year (enter a number, 1900-2017): ";
        while(!(_input >> dateNumber) || (dateNumber < 1900 || dateNumber > 2017)) {
            _display << "    Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        cStartDate.append(std::to_string(dateNumber)).append("/");
        Date custStartDate = checkDate(cStartDate);
        _display << "\nAre you sure you want to add the asset?" << std::endl << "(press Y to confirm or any other character to cancel) ";
        _input >> confirmation;
        if(tolower(confirmation) == 'y') {
            // make a new asset id using asset prefix and asset register map count
            std::string id1 = "phon";
            std::string id2 = std::to_string(AssetRegister::instance().phoneCounter().size() + 1);
            std::string id = id1 + id2;
            // construct new phone with inputs from user
            Phone newPhone(id, brand, model, purchasePrice, newDate, serialNumber, operatingSystem, billingIdentifier, phoneNumber);
            // create a new custodian
            Custodian custodian(custName, custDept, custPhoneNumber, custStartDate);
            // create a new custodian shared pointer
            std::shared_ptr<Custodian> newCustodian(new Custodian(custodian));
            // set pointer to new asset
            newPhone.setCustodian(newCustodian);
            // create a new Asset shared pointer
            std::shared_ptr<Phone> assetPointer(new Phone(newPhone));
            // add new phone to asset register instance
            AssetRegister::instance().storeAsset(assetPointer);
            //std::_display << AssetRegister::instance().phoneCounter().size() << std::endl;
            AssetRegister::instance().phoneCounter().push_back(newPhone);
            //std::_display << AssetRegister::instance().phoneCounter().size() << std::endl;
            _display << "\n***************************************************************" << std::endl;
            _display << "...Asset has been added to the register!" << " Asset id is " << id << std::endl;
            _display << "***************************************************************\n" << std::endl;
        } else {
            _display << "...Operation cancelled\n" << std::endl;
            addAsset();
        }
        break;
    }
    case 't': {

        _display << "To add a Television, please enter the following details:" << std::endl;
        _display << "  Brand: ";
        _input >> brand;
        _display << "  Model: ";
        _input >> model;
        _display << "  Purchase Price: ";
        while(!(_input >> purchasePrice)) {
            _display << "  Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        _display << "  Purchase Date: " << std::endl;
        _display << "   Enter day of month (as a number, 1-31): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 31)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        _display << "   Enter month of year (as a number, 1-12): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 12)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        _display << "   Enter year (as a number, 1900-2017): ";
        while(!(_input >> dateNumber) || (dateNumber < 1900 || dateNumber > 2017)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        Date newDate = checkDate(purchaseDate);
        _display << "  Serial Number: ";
        _input >> serialNumber;
        _display << "  Location: ";
        _input >> location;

        _display << "\nAre you sure you want to add the asset?" << std::endl << "(press Y to confirm or any other character to cancel) ";
        _input >> confirmation;

        if(tolower(confirmation) == 'y') {
            // make a new asset id using asset prefix and asset register map count
            std::string id1 = "tele";
            std::string id2 = std::to_string(AssetRegister::instance().televisionCounter().size() + 1);
            std::string id = id1 + id2;
            // construct new TV with inputs from user
            Television newTele(id, brand, model, purchasePrice, newDate, serialNumber, location);
            // create a new Asset shared pointer
            std::shared_ptr<Television> assetPointer(new Television(newTele));
            // add new TV to asset register instance
            AssetRegister::instance().storeAsset(assetPointer);
            //std::_display << AssetRegister::instance().teleCounter().size() << std::endl;
            AssetRegister::instance().televisionCounter().push_back(newTele);
            //std::_display << AssetRegister::instance().teleCounter().size() << std::endl;
            _display << "\n***************************************************************" << std::endl;
            _display << "...Asset has been added to the register!" << " Asset id is " << id << std::endl;
            _display << "***************************************************************\n" << std::endl;
        } else {
            _display << "...Operation cancelled\n" << std::endl;
            addAsset();
        }

        break;
    }
    case 'h': {

        _display << "To add a HMD, please enter the following details:" << std::endl;
        _display << "  Brand: ";
        _input >> brand;
        _display << "  Model: ";
        _input >> model;
        _display << "  Purchase Price: ";
        while(!(_input >> purchasePrice)) {
            _display << "  Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        _display << "  Purchase Date: " << std::endl;
        _display << "   Enter day of month (as a number, 1-31): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 31)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        _display << "   Enter month of year (as a number, 1-12): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 12)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        _display << "   Enter year (as a number, 1900-2017): ";
        while(!(_input >> dateNumber) || (dateNumber < 1900 || dateNumber > 2017)) {
            _display << "   Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        purchaseDate.append(std::to_string(dateNumber)).append("/");
        Date newDate = checkDate(purchaseDate);
        _display << "  Serial Number: ";
        _input >> serialNumber;
        _display << "  Custodian: " << std::endl;
        _display << "   Custodian Name: ";
        _input >> custName;
        _display << "   Custodian Department: ";
        _input >> custDept;
        _display << "   Custodian Phone Number: ";
        _input >> custPhoneNumber;
        _display << "   Custodian Start date: " << std::endl;
        _display << "    Enter day of month (as a number, 1-31): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 31)) {
            _display << "    Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        cStartDate.append(std::to_string(dateNumber)).append("/");
        _display << "    Enter month of year (as a number, 1-12): ";
        while(!(_input >> dateNumber) || (dateNumber == 0 || dateNumber > 12)) {
            _display << "    Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        cStartDate.append(std::to_string(dateNumber)).append("/");
        _display << "    Year (enter a number, 1900-2017): ";
        while(!(_input >> dateNumber) || (dateNumber < 1900 || dateNumber > 2017)) {
            _display << "    Incorrect entry, try again: ";
            _input.clear();
            _input.ignore(100, '\n');
        }
        cStartDate.append(std::to_string(dateNumber)).append("/");
        Date custStartDate = checkDate(cStartDate);
        _display << "\nAre you sure you want to add the asset?" << std::endl << "(press Y to confirm or any other character to cancel) ";
        _input >> confirmation;

        if(tolower(confirmation) == 'y') {
            // make a new asset id using asset prefix and asset register map count
            std::string id1 = "hmd";
            std::string id2 = std::to_string(AssetRegister::instance().hmdCounter().size() + 1);
            std::string id = id1 + id2;
            // construct new hmd with inputs from user
            HMD newHMD(id, brand, model, purchasePrice, newDate, serialNumber);
            // create a new custodian
            Custodian custodian(custName, custDept, custPhoneNumber, custStartDate);
            // create a new custodian shared pointer
            std::shared_ptr<Custodian> newCustodian(new Custodian(custodian));
            // set pointer to new asset
            newHMD.setCustodian(newCustodian);
            // create a new Asset shared pointer
            std::shared_ptr<HMD> assetPointer(new HMD(newHMD));
            // add new HMD to asset register instance
            AssetRegister::instance().storeAsset(assetPointer);
            //std::_display << AssetRegister::instance().hmdCounter().size() << std::endl;
            AssetRegister::instance().hmdCounter().push_back(newHMD);
            //std::_display << AssetRegister::instance().hmdCounter().size() << std::endl;
            _display << "\n***************************************************************" << std::endl;
            _display << "...Asset has been added to the register!" << " Asset id is " << id<< std::endl;
            _display << "***************************************************************\n" << std::endl;
        } else {
            _display << "...Operation cancelled\n" << std::endl;
            addAsset();
        }
        break;
    }
    default:
        _display << "error" << std::endl;
    }
}

void MenuInterface::disposeAsset() {
    std::string del;
    _display << "Enter the asset's id you want to delete: ";
    _input >> del;


}

void MenuInterface::updateAsset() {
    // TODO: implement this member function.
}

Date MenuInterface::checkDate(std::string &date) {
    std::string delimiter = "/";
    // get day token
    int day = std::stoi(date.substr(0, date.find(delimiter)));
    date.erase(0, date.find(delimiter) + delimiter.length());

    // get month token
    int month = std::stoi(date.substr(0, date.find(delimiter)));
    date.erase(0, date.find(delimiter) + delimiter.length());

    // get year token
    int year = std::stoi(date.substr(0, date.find(delimiter)));
    date.erase(0, date.find(delimiter) + delimiter.length());

    Date::Month enumMonth;
    switch (month) {
    case 1:
        enumMonth = Date::Month::January;
        break;
    case 2:
        enumMonth = Date::Month::February;
        break;
    case 3:
        enumMonth = Date::Month::March;
        break;
    case 4:
        enumMonth = Date::Month::April;
        break;
    case 5:
        enumMonth = Date::Month::May;
        break;
    case 6:
        enumMonth = Date::Month::June;
        break;
    case 7:
        enumMonth = Date::Month::July;
        break;
    case 8:
        enumMonth = Date::Month::August;
        break;
    case 9:
        enumMonth = Date::Month::September;
        break;
    case 10:
        enumMonth = Date::Month::October;
        break;
    case 11:
        enumMonth = Date::Month::November;
        break;
    case 12:
        enumMonth = Date::Month::December;
        break;
    default:
        break;
    }
    Date newDate(day, enumMonth, year);
    return newDate;
}

void MenuInterface::addMaintenance() {
    // TODO: implement this member function.
}

void MenuInterface::listAssetsByType() {
    char control;
    _display << std::endl;
    _display << "List assets by type" << std::endl;
    _display << " list (a)ll assets" << std::endl;
    _display << " list (c)computers" << std::endl;
    _display << " list (p)hones" << std::endl;
    _display << " list (t)elevisions" << std::endl;
    _display << " list (h)mds" << std::endl;
    _display << " (b) to main menu" << std::endl;
    _display << std::endl;
    _input >> control;

    AssetRegister &assetRegister = AssetRegister::instance();

    switch (control) {
    case 'a': {
        std::vector<Computer> *comps = &assetRegister.computerCounter();
        for (std::vector<Computer>::iterator it = comps->begin(); it != comps->end(); ++it) {
            Computer c = *it;
            c.display();
        }
        std::vector<Phone> *phones = &assetRegister.phoneCounter();
        for (std::vector<Phone>::iterator it = phones->begin(); it != phones->end(); ++it) {
            Phone p = *it;
            p.display();
        }
        std::vector<Television> *tvs = &assetRegister.televisionCounter();
        for (std::vector<Television>::iterator it = tvs->begin(); it != tvs->end(); ++it) {
            Television t = *it;
            t.display();
        }
        std::vector<HMD> *hmds = &assetRegister.hmdCounter();
        for (std::vector<HMD>::iterator it = hmds->begin(); it != hmds->end(); ++it) {
            HMD h = *it;
            h.display();
        }
        break;
    }
    case 'c': {
        std::vector<Computer> *comps = &assetRegister.computerCounter();
        for (std::vector<Computer>::iterator it = comps->begin(); it != comps->end(); ++it) {
            Computer c = *it;
            c.display();
        }
        break;
    }
    case 'p': {
        std::vector<Phone> *phones = &assetRegister.phoneCounter();
        for (std::vector<Phone>::iterator it = phones->begin(); it != phones->end(); ++it) {
            Phone p = *it;
            p.display();
        }
        break;
    }
    case 't': {
        std::vector<Television> *tvs = &assetRegister.televisionCounter();
        for (std::vector<Television>::iterator it = tvs->begin(); it != tvs->end(); ++it) {
            Television t = *it;
            t.display();
        }
        break;
    }
    case 'h': {
        std::vector<HMD> *hmds = &assetRegister.hmdCounter();
        for (std::vector<HMD>::iterator it = hmds->begin(); it != hmds->end(); ++it) {
            HMD h = *it;
            h.display();
        }
        break;
    }
    case 'b': {
        displayMainMenu();
        break;
    }
    default:
        break;
    }
}

void MenuInterface::listAssetsByCustodian() {
    // TODO: implement this member function.
}

void MenuInterface::findAsset() {
    _display << "Find asset" << std::endl;
    _display << "  search by (a)sset id" << std::endl;
    _display << "  search by (s)erial" << std::endl;
    _display << "(b)ack to main menu" << std::endl;

    std::string search;

    char input = getCharacterInput();

    switch (input) {
    case 'a': {
        _display << "Please enter an asset id: ";
        _input >> search;

        // create reference to asset register instance
        AssetRegister &am = AssetRegister::instance();
        // retrieve asset from register according to given input and assign it to a pointer
        std::shared_ptr<Asset> asset = am.retrieveAsset(search);

        std::shared_ptr<Computer> computer = std::dynamic_pointer_cast<Computer>(asset);
        if (computer != nullptr) {
            // asset is a computer - cast it
            std::shared_ptr<Computer> computer = std::dynamic_pointer_cast<Computer>(asset);
            displayComputer(*computer);
        }
        std::shared_ptr<Phone> phone = std::dynamic_pointer_cast<Phone>(asset);
        if (phone != nullptr) {
            // asset is a phone - cast it
            std::shared_ptr<Phone> phone = std::dynamic_pointer_cast<Phone>(asset);
            displayPhone(*phone);
        }
        std::shared_ptr<Television> tv = std::dynamic_pointer_cast<Television>(asset);
        if (tv != nullptr) {
            // asset is a tv - cast it
            std::shared_ptr<Television> tv = std::dynamic_pointer_cast<Television>(asset);
            displayTelevision(*tv);
        }
        std::shared_ptr<HMD> hmd = std::dynamic_pointer_cast<HMD>(asset);
        if (hmd != nullptr) {
            // asset is a hmd - cast it
            std::shared_ptr<HMD> hmd = std::dynamic_pointer_cast<HMD>(asset);
            displayHMD(*hmd);
        } else {
            _display << "Sorry, I am not able to find that id" << std::endl << std::endl;
            findAsset();
        }

        break;
    }
    case 's': {
        _display << "Please enter a serial number: ";
        _input >> search;

        break;
    }
    case 'b':
        displayMainMenu();
        break;
    default:
        break;
    }
}
