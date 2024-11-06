#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Customer.h"
#include "Transaction.h"
#include <string>

/**
 * @class Account
 * @brief Represents a general account with customer information, balance, and transactions
 */
class Account {
protected:
    Customer* customer; ///< Pointer to the customer associated with the account
    double balance; ///< Current balance in the account
    int account_number; ///< Account number
    Transaction* transactions[100]; ///< Array to store transactions
    int transaction_count; ///< Count of transactions

    void add_transaction(const std::string& type, double amount);
    std::string to_string() const;

public:
    /**
     * @brief Constructor for creating an Account object
     * @param customer Pointer to the customer associated with the account
     * @param account_number The account number
     */
    Account(Customer* customer, int account_number);

    /**
     * @brief Virtual destructor for Account class
     */
    virtual ~Account();

    /**
     * @brief Virtual function to deposit money into the account
     * @param amount The amount to deposit
     */
    virtual void deposit(double amount) = 0;

    /**
     * @brief Virtual function to withdraw money from the account
     * @param amount The amount to withdraw
     * @return True if the withdrawal is successful, false otherwise
     */
    virtual bool withdraw(double amount) = 0;

    double get_balance() const; ///< Get the current balance
    int get_account_number() const; ///< Get the account number
    Customer* get_customer() const; ///< Get the associated customer
    void set_balance(double balance); ///< Set the balance

    /**
     * @brief Get account information as a string
     * @return A string representing the account information
     */
    std::string get_account_info() const {
        return to_string();
    }
};

/**
 * @class SavingsAccount
 * @brief Represents a savings account, a type of Account
 */
class SavingsAccount : public Account {
public:
    /**
     * @brief Constructor for creating a SavingsAccount object
     * @param customer Pointer to the customer associated with the account
     * @param account_number The account number
     */
    SavingsAccount(Customer* customer, int account_number);

    void deposit(double amount) override; ///< Deposit money into the savings account
    bool withdraw(double amount) override; ///< Withdraw money from the savings account
    void add_interest(); ///< Add interest to the savings account
};

/**
 * @class CheckingAccount
 * @brief Represents a checking account, a type of Account
 */
class CheckingAccount : public Account {
public:
    /**
     * @brief Constructor for creating a CheckingAccount object
     * @param customer Pointer to the customer associated with the account
     * @param account_number The account number
     */
    CheckingAccount(Customer* customer, int account_number);

    void deposit(double amount) override; ///< Deposit money into the checking account
    bool withdraw(double amount) override; ///< Withdraw money from the checking account
    void add_interest(); ///< Add interest to the checking account
};

#endif // ACCOUNT_H