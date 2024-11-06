#ifndef DATE_H
#define DATE_H

#include <string>

/**
 * @class Date
 * @brief Represents a date with day, month, and year information
 */
class Date 
{
public:
    /**
     * @brief Constructor for creating a Date object with the given day, month, and year
     * @param day The day of the date
     * @param month The month of the date
     * @param year The year of the date
     */
    Date(int day, int month, int year);

    /**
     * @brief Converts the Date object to a string in the format "DD/MM/YYYY"
     * @return A string representation of the date
     */
    std::string to_string() const;

private:
    int day; ///< The day of the date
    int month; ///< The month of the date
    int year; ///< The year of the date
};

#endif