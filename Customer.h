#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

/**
 * @class Customer
 * @brief Represents a generic customer with basic information
 */
class Customer 
{
public:
    /**
     * @brief Constructor for creating a Customer object
     * @param name The name of the customer
     * @param address The address of the customer
     * @param age The age of the customer
     * @param phone The phone number of the customer
     * @param customer_number The customer number
     */
    Customer(const std::string& name, const std::string& address, int age, const std::string& phone, int customer_number);

    std::string get_name() const; ///< Get the name of the customer
    std::string get_address() const; ///< Get the address of the customer
    int get_age() const; ///< Get the age of the customer
    std::string get_phone() const; ///< Get the phone number of the customer
    int get_customer_number() const; ///< Get the customer number

protected:
    std::string name; ///< The name of the customer
    std::string address; ///< The address of the customer
    int age; ///< The age of the customer
    std::string telephone_number; ///< The phone number of the customer
    int customer_number; ///< The customer number
};

/**
 * @class Senior
 * @brief Represents a senior customer, inheriting from Customer
 */
class Senior : public Customer 
{
public:
    /**
     * @brief Constructor for creating a Senior customer object
     * @param name The name of the customer
     * @param address The address of the customer
     * @param age The age of the customer
     * @param phone The phone number of the customer
     * @param customer_number The customer number
     */
    Senior(const std::string& name, const std::string& address, int age, const std::string& phone, int customer_number);

    static const double SAVINGS_INTEREST; ///< Savings interest rate for senior customers
    static const double CHECKING_INTEREST; ///< Checking interest rate for senior customers
    static const double CHECK_CHARGE; ///< Check charge for senior customers
    static const double OVERDRAFT_PENALTY; ///< Overdraft penalty for senior customers
};

/**
 * @class Adult
 * @brief Represents an adult customer, inheriting from Customer
 */
class Adult : public Customer 
{
public:
    /**
     * @brief Constructor for creating an Adult customer object
     * @param name The name of the customer
     * @param address The address of the customer
     * @param age The age of the customer
     * @param phone The phone number of the customer
     * @param customer_number The customer number
     */
    Adult(const std::string& name, const std::string& address, int age, const std::string& phone, int customer_number);

    static const double SAVINGS_INTEREST; ///< Savings interest rate for adult customers
    static const double CHECKING_INTEREST; ///< Checking interest rate for adult customers
    static const double CHECK_CHARGE; ///< Check charge for adult customers
    static const double OVERDRAFT_PENALTY; ///< Overdraft penalty for adult customers
};

/**
 * @class Student
 * @brief Represents a student customer, inheriting from Customer
 */
class Student : public Customer 
{
public:
    /**
     * @brief Constructor for creating a Student customer object
     * @param name The name of the customer
     * @param address The address of the customer
     * @param age The age of the customer
     * @param phone The phone number of the customer
     * @param customer_number The customer number
     */
    Student(const std::string& name, const std::string& address, int age, const std::string& phone, int customer_number);

    static const double SAVINGS_INTEREST; ///< Savings interest rate for student customers
    static const double CHECKING_INTEREST; ///< Checking interest rate for student customers
    static const double CHECK_CHARGE; ///< Check charge for student customers
    static const double OVERDRAFT_PENALTY; ///< Overdraft penalty for student customers
};

#endif // CUSTOMER_H