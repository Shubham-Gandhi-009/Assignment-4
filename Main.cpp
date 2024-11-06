#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

//Date Class
class Date {
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) { }
    
    std::string to_string() const {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << day << '/' 
            << std::setw(2) << month << '/' 
            << std::setw(4) << year;
        return oss.str();
    }

private:
    int day, month, year;
};

//Transaction Class
class Transaction {
public:
    Transaction(const std::string& type, double amt, double bal, const Date& dt)
        : transaction_type(type), amount(amt), balance(bal), date(dt) { }
    
    std::string to_string() const {
        std::ostringstream oss;
        oss << transaction_type << " " << date.to_string() << " $" << amount << " Balance: $" << balance;
        return oss.str();
    }

private:
    std::string transaction_type;
    double amount;
    double balance;
    Date date;
};

//Customer Class
class Customer {
public:
    Customer(const std::string& name, const std::string& address, int age, const std::string& phone, int customer_number)
        : name(name), address(address), age(age), telephone_number(phone), customer_number(customer_number) { }

    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
    int get_age() const { return age; }
    std::string get_phone() const { return telephone_number; }
    int get_customer_number() const { return customer_number; }

private:
    std::string name, address, telephone_number;
    int age, customer_number;
};

// Senior, Adult, Student Classes (Subclasses of Customer)
class Senior : public Customer {
public:
    Senior(const std::string& name, const std::string& address, int age, const std::string& phone, int customer_number)
        : Customer(name, address, age, phone, customer_number) { }

    static const double SAVINGS_INTEREST, CHECKING_INTEREST, CHECK_CHARGE, OVERDRAFT_PENALTY;
};

const double Senior::SAVINGS_INTEREST = 0.04;
const double Senior::CHECKING_INTEREST = 0.01;
const double Senior::CHECK_CHARGE = 0.01;
const double Senior::OVERDRAFT_PENALTY = 25.0;

class Adult : public Customer {
public:
    Adult(const std::string& name, const std::string& address, int age, const std::string& phone, int customer_number)
        : Customer(name, address, age, phone, customer_number) { }

    static const double SAVINGS_INTEREST, CHECKING_INTEREST, CHECK_CHARGE, OVERDRAFT_PENALTY;
};

const double Adult::SAVINGS_INTEREST = 0.03;
const double Adult::CHECKING_INTEREST = 0.01;
const double Adult::CHECK_CHARGE = 0.03;
const double Adult::OVERDRAFT_PENALTY = 25.0;

class Student : public Customer {
public:
    Student(const std::string& name, const std::string& address, int age, const std::string& phone, int customer_number)
        : Customer(name, address, age, phone, customer_number) { }

    static const double SAVINGS_INTEREST, CHECKING_INTEREST, CHECK_CHARGE, OVERDRAFT_PENALTY;
};

const double Student::SAVINGS_INTEREST = 0.04;
const double Student::CHECKING_INTEREST = 0.01;
const double Student::CHECK_CHARGE = 0.02;
const double Student::OVERDRAFT_PENALTY = 25.0;

//Account Class and Derived Classes (SavingsAccount, CheckingAccount)
class Account {
public:
    Account(Customer* cust, int acct_number)
        : customer(cust), account_number(acct_number), balance(0.0), transaction_count(0) { }

    double get_balance() const { return balance; }
    int get_account_number() { return account_number; }
    Customer* get_customer() const { return customer; }

    void set_balance(double bal) { balance = bal; }
    void add_transaction(const std::string& type, double amount) {
        Date today(1, 1, 2023); // Placeholder for the current date
        transactions[transaction_count++] = new Transaction(type, amount, balance, today);
    }

    virtual void deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void add_interest() = 0;

    std::string to_string() const {
        std::ostringstream oss;
        oss << "Account Number: " << account_number << "\n"
            << "Owner: " << customer->get_name() << "\n"
            << "Balance: $" << balance;
        return oss.str();
    }

protected:
    Customer* customer;
    int account_number;
    double balance;
    int transaction_count;
    Transaction* transactions[100];  // Maximum of 100 transactions per account
};

class SavingsAccount : public Account {
public:
    SavingsAccount(Customer* cust, int acct_number)
        : Account(cust, acct_number) { }

    void deposit(double amount) override {
        balance += amount;
        add_transaction("DEP", amount);
        std::cout << "Deposited: $" << amount << "\n";
    }

    bool withdraw(double amount) override {
        if (amount > balance) {
            std::cout << "Insufficient funds for withdrawal.\n";
            return false;
        }
        balance -= amount;
        add_transaction("WD", amount);
        std::cout << "Withdrew: $" << amount << "\n";
        return true;
    }

    void add_interest() override {
        double interest = balance * Senior::SAVINGS_INTEREST;
        balance += interest;
        add_transaction("INT", interest);
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(Customer* cust, int acct_number)
        : Account(cust, acct_number) { }

    void deposit(double amount) override {
        balance += amount;
        add_transaction("DEP", amount);
        std::cout << "Deposited: $" << amount << "\n";
    }

    bool withdraw(double amount) override {
        if (amount > balance) {
            balance -= Senior::OVERDRAFT_PENALTY;  // Apply overdraft penalty
            std::cout << "Overdraft! Charged penalty: $" << Senior::OVERDRAFT_PENALTY << "\n";
            return false;
        }
        balance -= amount;
        add_transaction("WD", amount);
        std::cout << "Withdrew: $" << amount << "\n";
        return true;
    }

    void add_interest() override {
        double interest = balance * Senior::CHECKING_INTEREST;
        balance += interest;
        add_transaction("INT", interest);
    }
};

//Bank Class
class Bank {
public:
    Bank() : account_count(0) {}

    ~Bank() {
        for (int i = 0; i < account_count; i++) delete accounts[i];
        // delete[] accounts;
    }

    void add_account(Account* account) {
        if (account_count < 100) {
            accounts[account_count] = account;
            // std::cout << "Account information " << account << std::endl;
            std::cout << "Account added: " << account_count << std::endl;
            account_count++;
        } else {
            std::cout << "Maximum accounts reached.\n";
        }
    }

    Account* get_account(int account_number) const {
        for (int i = 0; i < account_count; i++) {
            // std::cout << "Accounts " << accounts[i]->get_account_number() << std::endl;
            if (accounts[i]->get_account_number() == account_number) return accounts[i];
        }
        return nullptr;
    }

    void make_deposit(int account_number, double amount) {
        Account* account = get_account(account_number);
        if (account) account->deposit(amount);
        else std::cout << "Account not found.\n";
    }

    void make_withdrawal(int account_number, double amount) {
        Account* account = get_account(account_number);
        if (account) account->withdraw(amount);
        else std::cout << "Account not found.\n";
    }

    // Add this method to return the account count
    int get_account_count() const {
        return account_count;
    }

private:
    Account* accounts[100];
    int account_count;
};


// Application Main
void display_menu() {
    std::cout << "Select:\n"
              << "0: Add Account\n"
              << "1: Make Deposit\n"
              << "2: Make Withdrawal\n"
              << "3: Check Account\n"
              << "4: Exit\n";
}

int main() {
    Bank bank;
    while (true) {
        display_menu();
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            std::string name, address, phone;
            int age, customer_number, customer_type;
            std::cout << "Enter Customer Name> ";
            std::cin >> name;
            std::cout << "Enter Customer Address> ";
            std::cin >> address;
            std::cout << "Enter Customer Age> ";
            std::cin >> age;
            std::cout << "Enter Customer Phone Number> ";
            std::cin >> phone;
            std::cout << "Enter Customer Number> ";
            std::cin >> customer_number;

            Customer* customer;
            std::cout << "Select:\n0: Senior\n1: Adult\n2: Student\n";
            std::cin >> customer_type;

            if (customer_type == 0) customer = new Senior(name, address, age, phone, customer_number);
            else if (customer_type == 1) customer = new Adult(name, address, age, phone, customer_number);
            else customer = new Student(name, address, age, phone, customer_number);

            std::cout << "Select:\n0: Savings Account\n1: Checking Account\n";
            int account_type;
            std::cin >> account_type;

            int account_number = bank.get_account_count();  // Unique account number
            Account* account = (account_type == 0)
            ? static_cast<Account*>(new SavingsAccount(customer, account_number))
            : static_cast<Account*>(new CheckingAccount(customer, account_number));


            bank.add_account(account);
        } else if (choice == 1) {
            int account_number;
            double amount;
            std::cout << "Enter Account Number> ";
            std::cin >> account_number;
            std::cout << "Enter The Amount> ";
            std::cin >> amount;

            bank.make_deposit(account_number, amount);
        } else if (choice == 2) {
            int account_number;
            double amount;
            std::cout << "Enter Account Number> ";
            std::cin >> account_number;
            std::cout << "Enter The Amount> ";
            std::cin >> amount;

            bank.make_withdrawal(account_number, amount);
        } else if (choice == 3) {
            int account_number;
            std::cout << "Enter Account Number> ";
            std::cin >> account_number;
            Account* account = bank.get_account(account_number);
            if (account) std::cout << account->get_account_number() << std::endl;
            else std::cout << "Account not found.\n";
        } else if (choice == 4) break;
        else std::cout << "Invalid choice!\n";
    }
    return 0;
}
