#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;
public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "\nAmount Deposited Successfully!";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "\nInsufficient Balance!";
        } else {
            balance -= amount;
            cout << "\nAmount Withdrawn Successfully!";
        }
    }

    virtual double calculateInterest() {
        return 0.0;
    }

    void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nHolder Name: " << accountHolderName;
        cout << "\nBalance: " << balance;
    }
}; // END OF BASE CLASS


class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int accNo, string name, double bal)
        : BankAccount(accNo, name, bal) {}

    double calculateInterest() override {
        return balance * 0.04; // 4%
    }
};


class CheckingAccount : public BankAccount {
public:
    CheckingAccount(int accNo, string name, double bal)
        : BankAccount(accNo, name, bal) {}
};


class FixedDepositAccount : public BankAccount {
public:
    FixedDepositAccount(int accNo, string name, double bal)
        : BankAccount(accNo, name, bal) {}

    double calculateInterest() override {
        return balance * 0.07; // 7%
    }
};


int main() {
    SavingsAccount s1(101, "Rohan", 5000);
    CheckingAccount c1(102, "Priya", 3000);
    FixedDepositAccount f1(103, "Karan", 10000);

    cout << "\n=== Account Details ===";
    s1.displayAccountInfo();
    c1.displayAccountInfo();
    f1.displayAccountInfo();

    cout << "\n\n=== Testing Operations ===";
    s1.deposit(1000);
    s1.withdraw(6000);

    cout << "\n\nInterest on FD: " << f1.calculateInterest();
    cout << "\n\n=== END ===\n";

    return 0;
}
