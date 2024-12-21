#pragma once
#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class BankAccount {
private:
    int id;
    string name;

public:
    // Parameterized constructor
    BankAccount(int accountID, const string &accountName);
    
    // Necessary getters
    string getName() const;
    int getID() const;

    // Pure virtual functions
    virtual void Display() const = 0;
    virtual void Deposit(float amount) = 0;
    virtual float getAmount() const = 0;

    // Virtual destructor
    virtual ~BankAccount() = 0;
};

// Derived class: CheckingAccount
class CheckingAccount : virtual public BankAccount {
private:
    float amount;

protected:
    void SetAmount(float amount);

public:
    // Constructor
    CheckingAccount(float initialAmount, int accountID, const string& accountName);

    // Override pure virtual functions
    void Display() const override;
    void Deposit(float depositAmount) override;
    float getAmount() const override;

    // Withdraw function
    bool Withdraw(float withdrawAmount);
};

// Derived class: SavingsAccount
class SavingsAccount : virtual public BankAccount {
private:
    float amount;

protected:
    void SetAmount(float newAmount);

public:
    ~SavingsAccount() override; // Corrected destructor declaration
    // Constructor
    SavingsAccount(float initialAmount, int accountID, const string& accountName);

    // Override pure virtual functions
    void Display() const override;
    void Deposit(float depositAmount) override;
    float getAmount() const override;

    // Additional functions
    float CompoundEarnings(float percent);
    bool Transfer(CheckingAccount& checkingAccount, float transferAmount);
};

// Composite class: InvestmentAccount
class InvestmentAccount : public CheckingAccount, private SavingsAccount {
public:
    ~InvestmentAccount() override; // Corrected destructor declaration
    // Constructor with initial amount directed to savings
    InvestmentAccount(float initialSavings, int accountID, const string& accountName);

    // Override pure virtual functions
    void Display() const override;
    void Deposit(float depositAmount) override;
    float getAmount() const override;

    // Additional functions
    float CompoundEarnings(float percent);
    bool Transfer(float percent);
};