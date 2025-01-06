#include <iostream>
using namespace std;

class Account
{
protected:
    long int accountNumber;
    long double balance;
    short int pin;

public:
    Account(long int accountNumber, short int pin, long double balance)
    {
        this->accountNumber = accountNumber;
        this->pin = pin;
        if (balance > 0)
        {
            this->balance = balance;
        }
        else
        {
            this->balance = 0;
        }
    }

    void checkbalance()
    {
        cout << "Current Balance: " << balance << endl;
    }
    virtual void withdraw(long double amount) = 0;
    virtual void deposit(long double amount) = 0;
};

class SavingAccount : public Account
{
private:
    const double withdrawLimit = 10000.00;
    const double depositLimit = 10000.00;

public:
    SavingAccount(long int accountNumber, short int pin, long double balance)
        : Account(accountNumber, pin, balance) {}

    void checkbalance()
    {
        cout << "Current Balance: " << this->balance << endl;
    }
    void withdraw(long double amount)
    {
        if (amount > withdrawLimit)
        {
            cout << "Cant withdraw amount, amount exceeds the limit for this account type." << endl;
            cout << "Limit for Savings Account : INR 10,000.00" << endl;
            return;
        }
        if (amount > balance)
        {
            cout << "Insufficient balance!" << endl;
            return;
        }
        this->balance = (this->balance) - amount;
        cout << "Wihtdraw successful !" << endl;
        cout << "Updated account balance: INR " << this->balance << endl;
    }
    void deposit(long double amount)
    {
        if (amount > depositLimit)
        {
            cout << "Cant deposit amount, amount exceeds the limit for this account type." << endl;
            cout << "Limit for Savings Account : INR 10,000.00" << endl;
            return;
        }
        this->balance = (this->balance) + amount;
        cout << "Deposit successfull !" << endl;
        cout << "Updated account balance: INR " << this->balance << endl;
    }
};

class CurrentAccount : public Account
{
private:
    const double withdrawLimit = 50000.00;
    const double depositLimit = 100000.00;

public:
    CurrentAccount(long int accountNumber, short int pin, long double balance)
        : Account(accountNumber, pin, balance) {}

    void checkbalance()
    {
        cout << "Current Balance: " << this->balance << endl;
    }
    void withdraw(long double amount)
    {
        if (amount > withdrawLimit)
        {
            cout << "Cant withdraw amount, amount exceeds the limit for this account type." << endl;
            cout << "Limit for Current Account : INR 50,000.00" << endl;
            return;
        }
        if (amount > balance)
        {
            cout << "Insufficient balance!" << endl;
            return;
        }
        this->balance = (this->balance) - amount;
        cout << "Wihtdraw successful !" << endl;
        cout << "Updated account balance: INR " << this->balance << endl;
    }
    void deposit(long double amount)
    {
        if (amount > depositLimit)
        {
            cout << "Cant deposit amount, amount exceeds the limit for this account type." << endl;
            cout << "Limit for Current Account : INR 1,00,000.00" << endl;
            return;
        }
        this->balance = (this->balance) + amount;
        cout << "Deposit successfull !" << endl;
        cout << "Updated account balance: INR " << this->balance << endl;
    }
};

int main()
{
    int accountType = 0;
    long int accountNumber;
    short int pin;
    long double balance;

    cout << "ATM Simulator" << endl;

    cout << "Create an Account!" << endl;
    cout << "Select an account type : ";
    cout << "1. Savings Account" << endl;
    cout << "2. Current Account" << endl;

    cout << "Enter the choice: ";
    cin >> accountType;

    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter pin: ";
    cin >> pin;
    cout << "Enter initial balance: ";
    cin >> balance;

    Account *account = nullptr;

    switch (accountType)
    {
    case 1:
        account = new SavingAccount(accountNumber, pin, balance);
        cout << "Account Creation Successful" << endl;
        break;

    case 2:
        account = new CurrentAccount(accountNumber, pin, balance);
        cout << "Account Creation Successful" << endl;
        break;

    default:
        cout << "Invalid Operation" << endl;
        break;
    }
    int operation;
    do
    {
        cout << "\nSelect an operation:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> operation;

        long double amount;

        switch (operation)
        {
        case 1:
            account->checkbalance();
            break;

        case 2:
            cout << "Enter deposit amount: ";
            cin >> amount;
            account->deposit(amount);
            break;

        case 3:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            account->withdraw(amount);
            break;

        case 4:
            cout << "Exiting the ATM Simulator." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (operation != 4);

    delete account;
}