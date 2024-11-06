#ifndef BANK_H
#define BANK_H

#include "Account.h"

/**
 * @class Bank
 * @brief Represents a bank with accounts and banking operations
 */
class Bank 
{
public:
    /**
     * @brief Constructor for creating a Bank object
     */
    Bank(){}

    /**
     * @brief Destructor for the Bank class
     */
    ~Bank(){}

    /**
     * @brief Add an account to the bank
     * @param account Pointer to the account to be added
     */
    void add_account(Account* account);

    /**
     * @brief Make a deposit into the specified account
     * @param account_number The account number to deposit into
     * @param amount The amount to deposit
     */
    void make_deposit(int account_number, double amount);

    /**
     * @brief Make a withdrawal from the specified account
     * @param account_number The account number to withdraw from
     * @param amount The amount to withdraw
     */
    void make_withdrawal(int account_number, double amount);

    /**
     * @brief Get the account with the specified account number
     * @param account_number The account number to search for
     * @return Pointer to the account with the specified account number
     */
    Account* get_account(int account_number) const;

    /**
     * @brief Get the total count of accounts in the bank
     * @return The total count of accounts
     */
    int get_account_count() const { return account_count; }

private:
    Account** accounts; ///< Array of pointers to accounts
    int account_count; ///< Total count of accounts in the bank
};

#endif // BANK_H