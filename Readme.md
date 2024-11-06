Author:  Shubham M. Gandhi
Student Id : 200526729

# Bank System Project

## Overview

This Bank System project is designed to simulate a simple banking environment with functionalities to manage customer accounts, perform deposits, withdrawals, check balances, and calculate interest rates for different types of accounts. The system supports different types of customers, including Seniors, Adults, and Students, each with specific rules for interest rates, check charges, and overdraft penalties.

## Features

- **Account Management**: Create checking and savings accounts for different types of customers.
- **Customer Types**:
  - **Senior**: Has specific interest rates, check charges, and overdraft policies.
  - **Adult**: Standard banking rates and penalties.
  - **Student**: Reduced check charges and special rates.
- **Transactions**: 
  - Deposit funds into accounts.
  - Withdraw funds with overdraft checks.
  - Calculate interest over time based on the customer type and account type.
- **Interactive Menu**: Console-based menu for ease of use and operation.

## Project Structure

The project is organized into several classes, with each class split into header (`.h`) and implementation (`.cpp`) files. The main classes are:

### Classes

- **Customer**:
  - Contains the common functionality for `Senior`, `Adult`, and `Student` customers.
- **Account**:
  - Manages the functionalities for `CheckingAccount` and `SavingsAccount`.
- **BankSystem**:
  - Manages the overall system, including operations like adding accounts, making deposits, withdrawals, and checking account information.
- **Transaction**:
  - Handles transaction logging, storing deposit and withdrawal data for accounts.
- **Date**:
  - Manages dates for transactions to calculate interest accurately.

  Usage
Upon running the program, an interactive menu will appear with the following options:
Select:
0: Add Account
1: Make Deposit
2: Make Withdrawal
3: Check Account
4: Exit
> 0
Enter Customer Name> John
Enter Customer Address> Regina
Enter Customer Age> 40
Enter Customer Phone Number> 30633333
Select:
0: Senior
1: Adult
2: Student
> 1
Select:
0: Checking
1: Savings
> 1
Account: 0 Added
Select:
0: Add Account
1: Make Deposit
2: Make Withdrawal
3: Check Account
4: Exit
> 1
Enter Account Number> 0
Enter The Amount> 2000
Enter the date yyyy-mm-dd> 2018-10-10
Deposit in 0 amount: $2000.00 on 2018-10-10 new balance: $2000.00
Select:
0: Add Account
1: Make Deposit
2: Make Withdrawal
3: Check Account
4: Exit
> 3
Enter Account Number> 0
Account: 0
Owner: John
Type of customer: Adult
Balance: $2000
      DEP  2018-10-10  $ 2000.00  $ 2000.00

Select:
0: Add Account
1: Make Deposit
2: Make Withdrawal
3: Check Account
4: Exit
> 2
Enter Account Number> 0
Enter The Amount> 100
Enter the date yyyy-mm-dd> 2020-10-10
Withdraw from 0 amount: 100.00 on 2020-10-10 new balance: 2020.16
Select:
0: Add Account
1: Make Deposit
2: Make Withdrawal
3: Check Account
4: Exit
> 3
Enter Account Number> 0
Account: 0
Owner: John
Type of customer: Adult
Balance: $2020.16
      DEP  2018-10-10  $ 2000.00  $ 2000.00
   INT CR  2020-10-10  $  120.16  $ 2120.16
       WD  2020-10-10  $  100.00  $ 2020.16

Select:
0: Add Account
1: Make Deposit
2: Make Withdrawal
3: Check Account
4: Exit
> 0
Enter Customer Name> Sara
Enter Customer Address> Regina ave
Enter Customer Age> 18
Enter Customer Phone Number> 30644444
Select:
0: Senior
1: Adult
2: Student
> 2
Select:
0: Checking
1: Savings
> 0
Account: 1 Added
Select:
0: Add Account
1: Make Deposit
2: Make Withdrawal
3: Check Account
4: Exit
> 1
Enter Account Number> 1
Enter The Amount> 500
Enter the date yyyy-mm-dd> 2018-10-11
Deposit in 1 amount: $500.00 on 2018-10-11 new balance: $500.00
Select:
0: Add Account
1: Make Deposit
2: Make Withdrawal
3: Check Account
4: Exit
> 3
Enter Account Number> 1
Account: 1
Owner: Sara
Type of customer: Student
Balance: $500
      DEP  2018-10-11  $  500.00  $  500.00

Select:
0: Add Account
1: Make Deposit
2: Make Withdrawal
3: Check Account
4: Exit

Git Hub Link : https://github.com/Shubham-Gandhi-009/Assignment-4




