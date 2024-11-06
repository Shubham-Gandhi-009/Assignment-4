#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Date.h"

/**
 * @class Transaction
 * @brief Represents a financial transaction with type, amount, balance, and date information
 */
class Transaction 
{
public:
    /**
     * @brief Constructor for creating a Transaction object with the given type, amount, balance, and date
     * @param type The type of transaction
     * @param amount The amount involved in the transaction
     * @param balance The balance after the transaction
     * @param date The date of the transaction
     */
    Transaction(const std::string& type, double amount, double balance, const Date& date);

    /**
     * @brief Converts the Transaction object to a string representation
     * @return A string representing the transaction details
     */
    std::string to_string() const;

private:
    std::string transaction_type; ///< The type of transaction
    double amount; ///< The amount involved in the transaction
    double balance; ///< The balance after the transaction
    Date date; ///< The date of the transaction
};

#endif