# Mini BANK System - CSI2372 Project
A comprehensive bank account management system implemented in C++ that handles various account types, transactions, and client reporting.

--- 

## 📋 Project Overview
This project implements a mini banking system that processes client accounts and transactions from text files, providing account management functionalities including deposits, withdrawals, checks, and interest calculations.

## 🏗️ System Architecture
Account Types
- 01 - Checking Account
- 02 - Savings Account
- 03 - Term Deposit
- 04 - Loan Account

Transaction Codes
- 01 - Deposit (all account types)
- 02 - Withdrawal (checking & savings only)
- 03 - Check (checking only)

---

## 📁 Project Structure

- ├── Bank.h              # Class definitions and declarations
- ├── Bank.cpp            # Main implementation file
- ├── clients.txt         # Client accounts data
- ├── transact.txt        # Transaction records
- └── README.md           # Project documentation

---

## ⚙️ Features
- Account Management: Create and manage different bank account types
- Transaction Processing: Handle deposits, withdrawals, and checks with validation
- Interest Calculation: Automatic interest for deposit accounts
- Loan Management: Loan amount calculation with interest over specified years
- Reporting: Generate comprehensive client account reports
- Data Persistence: Read from and process text file data

---

## 🚀 Getting Started
Prerequisites
- C++ Compiler (g++, clang++, or MSVC)
- Standard Template Library (STL)

Compilation
- bash
- g++ -o bank Bank.cpp

Execution
- bash
- ./bank

--- 

## 🎯 Key Functionalities
- Account Reading (readAccounts())
- Parses client data from clients.txt
- Creates appropriate account objects based on type
- Account Sorting (sortAccounts())
- Sorts accounts by client name and account type
- Maintains proper grouping for reporting
- Transaction Processing (updateAccounts())
- Processes transactions from transact.txt
- Validates transaction-account compatibility
- Applies fees and restrictions
- Report Generation (displayAccounts())
- Displays formatted client account summaries
- Shows pre-update and post-update states

---

## 💰 Business Rules
- Withdrawal Fee: $0.50 per withdrawal (checking & savings)
- Deposit Bonus: Annual interest rate applied to deposit accounts
- Loan Calculation: Total amount includes interest over specified years
- Validation: Transactions are validated against account type rules

---

## 🔧 Technical Details
- Language: C++
- Paradigm: Object-Oriented Programming
- Key Concepts: Inheritance, Polymorphism, File I/O, Memory Management
- Data Structures: Arrays, Pointers, Strings

--- 

## 📈 Sample Output
The system generates comprehensive reports showing:



               THE REPORT OF THE BANK ACCOUNTS OF CLIENTS
               ------------------------------------------

         Client Name:  Jean-Marc Leroux

Bank Account            Type    Update Date     Balance         Nb.Years        Rate 
------------            ----    -----------     -------         --------        ----
10010                   4       960911          105124.69       5               8.55

                                                ----------
                 TOTAL ACCOUNTS: 105124.69


         Client Name:  Anne-Marie Tremblay

Bank Account            Type    Update Date     Balance         Nb.Years        Rate
------------            ----    -----------     -------         --------        ----
20005                   1       960901          10000.00
20005                   2       960920          5000.00
20005                   3       961001          25013.54        3               6.50

                                                ----------
                 TOTAL ACCOUNTS: 40013.54


         Client Name:  Bernard Chevrette

Bank Account            Type    Update Date     Balance         Nb.Years        Rate
------------            ----    -----------     -------         --------        ---- 
30015                   3       961105          125225.69       10              6.50

                                                ----------
                 TOTAL ACCOUNTS: 125225.69


         Client Name:  Brian Cook

Bank Account            Type    Update Date     Balance         Nb.Years        Rate
------------            ----    -----------     -------         --------        ----
40000                   1       960911          5000.00

                                                ----------
                 TOTAL ACCOUNTS: 5000.00


               ************************************************
               * RE-DISPLAY OF DATA AFTER THE UPDATE *
               ************************************************



               THE REPORT OF THE BANK ACCOUNTS OF CLIENTS
               ------------------------------------------

         Client Name:  Jean-Marc Leroux

Bank Account            Type    Update Date     Balance         Nb.Years        Rate 
------------            ----    -----------     -------         --------        ----
10010                   4       960911          100124.69       5               8.55

                                                ----------
                 TOTAL ACCOUNTS: 100124.69


         Client Name:  Anne-Marie Tremblay

Bank Account            Type    Update Date     Balance         Nb.Years        Rate
------------            ----    -----------     -------         --------        ----
20005                   1       960901          10000.00
20005                   2       960920          5000.00
20005                   3       961001          35532.78        3               6.50

                                                ----------
                 TOTAL ACCOUNTS: 50532.78


         Client Name:  Bernard Chevrette

Bank Account            Type    Update Date     Balance         Nb.Years        Rate
------------            ----    -----------     -------         --------        ----
30015                   3       961105          125451.80       10              6.50

                                                ----------
                 TOTAL ACCOUNTS: 125451.80


         Client Name:  Brian Cook

Bank Account            Type    Update Date     Balance         Nb.Years        Rate
------------            ----    -----------     -------         --------        ----
40000                   1       960911          5000.00

                                                ----------
                 TOTAL ACCOUNTS: 5000.00
