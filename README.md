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

