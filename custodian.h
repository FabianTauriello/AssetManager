#ifndef CUSTODIAN_H
#define CUSTODIAN_H
#include <string>
#include "date.h"

/**
 * @brief The Custodian class the class representing a custodian for an asset
 */
class Custodian {
public:
    /**
     * @brief Custodian constructor for the class Custodian
     * @param name name of the custodian
     * @param department department the custodian belongs to
     * @param phoneNumber the phone number of the custodian
     * @param employmentStartDate the custodian's first day of employment
     */
    Custodian(const std::string &name, const std::string &department,
              const std::string &phoneNumber, const Date &employmentStartDate);

    /**
     * @brief name retrieve the name of a custodian
     * @return custodian's name
     */
    const std::string &name() const;

    /**
     * @brief department retrieve the department to which the custodian belongs
     * @return custodian's department
     */
    const std::string &department() const;

    /**
     * @brief phoneNumber retrieve the phone number of a custodian
     * @return custodian's phone number
     */
    const std::string &phoneNumber() const;

    /**
     * @brief employmentStart retrieve the employment start date of a custodian
     * @return custodian's start date of employment
     */
    const Date &employmentStart() const;

    /**
     * @brief setDepartment assign the custodian with a department
     * @param department the department to assign
     */
    void setDepartment(std::string &department);

    /**
     * @brief setPhoneNumber assign the custodian with a phone number
     * @param phoneNumber the phone number to assign
     */
    void setPhoneNumber(std::string &phoneNumber);

private:
    std::string _name;              /**< the name of a custodian */
    std::string _department;        /**< the department of a custodian */
    std::string _phoneNumber;       /**< the phone number of a custodian */
    Date _employmentStartDate;      /**< the employment start date of a custodian */

};

#endif // CUSTODIAN_H
