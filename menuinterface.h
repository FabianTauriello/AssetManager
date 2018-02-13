#ifndef MENUITERFACE_H
#define MENUITERFACE_H
#include <iostream>
#include "date.h"
#include "computer.h"
#include "phone.h"
#include "hmd.h"
#include "television.h"
#include <iomanip>

/**
 * @brief The MenuInterface class encapsulates all interaction with the asset management system.
 */
class MenuInterface {
public:
  /**
   * @brief MenuInterface
   * @param display
   * @param input
   */
  MenuInterface(std::ostream &display, std::istream &input);

  /**
   * @brief displayMainMenu write the main menu to the display device.
   */
  void displayMainMenu() const;

  /**
   * @brief getCharacterInput get a single character input from the input device
   * and clear the buffer till the next newline character.
   * @return the character input.
   */
  char getCharacterInput() const;

  /**
   * @brief displayComputer
   * @param computer
   */
  void displayComputer(const Computer &computer) const;

  /**
   * @brief displayTelevision
   * @param television
   */
  void displayTelevision(const Television television) const;

  /**
   * @brief displayHMD
   * @param hmd
   */
  void displayHMD(const HMD hmd) const;

  /**
   * @brief displayPhone
   * @param phone
   */
  void displayPhone(const Phone phone) const;

  /**
   * @brief displayCustodianDetails
   * @param asset
   */
  void displayCustodianDetails(const Asset &asset) const;

  /**
   * @brief processSelection process the selection for the menu.
   * @param selection the single character selection.
   * @return true to continue the program, false to quit.
   */
  bool processSelection(char selection);

private:
  std::ostream &_display; /**< the stream to pass all display output to */
  std::istream &_input;   /**< the stream to read all input from */

  /**
   * @brief addAsset display and process the add asset task.
   */
  void addAsset();

  /**
   * @brief disposeAsset display and process the dispose asset task.
   */
  void disposeAsset();

  /**
   * @brief updateAsset display and process the update asset custodian or location task.
   */
  void updateAsset();

  /**
   * @brief checkDate Checks a string and converts to date
   * @param date the string that needs conversion
   * @return a date object from the given string
   */
  Date checkDate(std::string &date);

  /**
   * @brief addMaintenance display and process the add asset maintenance record task.
   */
  void addMaintenance();

  /**
   * @brief listAssetsByType display and process the list assets by type task.
   */
  void listAssetsByType();

  /**
   * @brief listAssetsByCustodian display and process the list assets by custodian task.
   */
  void listAssetsByCustodian();

  /**
   * @brief findAsset display and process the find asset task.
   */
  void findAsset();
};

#endif // MENUITERFACE_H
