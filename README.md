# ATM Simulator

## Project Overview

The ATM Simulator is a simple command-line application developed in C++ to simulate banking operations like account creation, checking balance, depositing, and withdrawing money. It allows the creation of two types of accounts: Savings and Current, each with specific withdrawal and deposit limits. This project simulates the behavior of an ATM system, providing users with a basic interface to interact with their accounts.

## Why This Project Was Created

This project was developed as an exercise to practice Object-Oriented Programming (OOP) concepts, such as inheritance, polymorphism, and encapsulation. It also provides an opportunity to understand how banking operations could be modeled in a real-world system using classes and objects.

## Key Concepts Utilized

- **Object-Oriented Programming (OOP):**
  - **Inheritance:** The `SavingAccount` and `CurrentAccount` classes inherit from the base `Account` class, enabling code reuse and extending functionality for specific account types.
  - **Polymorphism:** The `withdraw` and `deposit` methods are virtual in the base class `Account` and overridden in derived classes, allowing different behavior based on the account type.
  - **Encapsulation:** Data like account number, balance, and pin are encapsulated within the `Account` class, ensuring these details are not directly accessible.

- **Abstraction:**
  - The interface provided by the `Account` class abstracts the operations common to all account types (checking balance, withdrawing, depositing), while the derived classes implement specific behaviors.

## Features

- **Account Creation:** 
  - Users can create a Savings or Current account by entering the account number, pin, and initial balance.
  
- **Check Balance:** 
  - Users can check their account balance at any time.
  
- **Deposit and Withdraw Money:** 
  - Users can deposit and withdraw money, with limits set for each account type (Savings and Current).
  
- **ATM Simulation Interface:** 
  - A simple menu-driven interface to interact with the ATM system.
