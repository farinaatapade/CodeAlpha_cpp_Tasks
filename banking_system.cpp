// Task 3 = Banking System

#include <iostream>
#include <vector>
using namespace std;

class Account
{
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string accNum, string holder, double bal)
    {
        accountNumber = accNum;
        accountHolder = holder;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount<<"Rs."<< " | New Balance: " << balance<<"Rs."<< endl;
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient funds!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount<<"Rs." << " | New Balance: "<< balance<<"Rs."<< endl;
        return true;
    }

    void display()
    {
        cout << "Account Number: " << accountNumber << "\nHolder: " << accountHolder << "\nBalance: $" << balance << endl;
    }

    string getAccountNumber() 
    { 
        return accountNumber; 
    }
    double getBalance() 
    { 
        return balance;
    }
};

class Bank
{
private:
    vector<Account> accounts;

public:
    void createAccount(string accNum, string holder, double initialDeposit)
    {
        accounts.push_back(Account(accNum, holder, initialDeposit));
        cout << "Account created successfully!\n";
    }

    Account *findAccount(string accNum)
    {
        for (auto &acc : accounts)
        {
            if (acc.getAccountNumber() == accNum)
            {
                return &acc;
            }
        }
        return nullptr;
    }

    void deposit(string accNum, double amount)
    {
        Account *acc = findAccount(accNum);
        if (acc)
            acc->deposit(amount);
        else
            cout << "Account not found!" << endl;
    }

    void withdraw(string accNum, double amount)
    {
        Account *acc = findAccount(accNum);
        if (acc)
            acc->withdraw(amount);
        else
            cout << "Account not found!" << endl;
    }

    void displayAccount(string accNum)
    {
        Account *acc = findAccount(accNum);
        if (acc)
            acc->display();
        else
            cout << "Account not found!" << endl;
    }
};

int main()
{
    Bank bank;
    int choice;
    string accNum, holder;
    double amount;

    while (true)
    {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. View Account\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder: ";
            cin >> holder;
            cout << "Enter Initial Deposit: ";
            cin >> amount;
            bank.createAccount(accNum, holder, amount);
            break;
        
        case 2:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            bank.deposit(accNum, amount);
            break;
        
        case 3:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            bank.withdraw(accNum, amount);
            break;
        
        case 4:
            cout << "Enter Account Number: ";
            cin >> accNum;
            bank.displayAccount(accNum);
            break;
        
        case 5:
            cout << "Exiting...\n";
            return 0;
       
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}