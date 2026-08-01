#include <iostream>

// Base class
class Account {
protected:
    std::string name;
    std::string acc_type;
    float balance;

public:
    // Constructor
    Account(std::string n, std::string type, float b) {
        name = n;
        acc_type = type;
        balance = b;
        std::cout << "Account Constructor Called\n";
    }

    // Deposit function
    void deposit(float amount) {
        balance += amount;
        std::cout << "Amount Deposited: " << amount << std::endl;
    }

    // Display balance
    void display() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Account Type: " << acc_type << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }

    // Destructor
    ~Account() {
        std::cout << "Account Destructor Called\n";
    }
};

// Derived class: Saving Account
class Saving_account : public Account {
private:
    float interest_rate;

public:
    // Constructor
    Saving_account(std::string n, float b, float rate)
        : Account(n, "Saving", b) {
        interest_rate = rate;
        std::cout << "Saving Account Constructor Called\n";
    }

    // Compute and deposit interest
    void compute_interest() {
        float interest = (balance * interest_rate) / 100;
        balance += interest;
        std::cout << "Interest Added: " << interest << std::endl;
    }

    // Withdraw function
    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: " << amount << std::endl;
        } else {
            std::cout << "Insufficient Balance\n";
        }
    }

    // Destructor
    ~Saving_account() {
        std::cout << "Saving Account Destructor Called\n";
    }
};

// Derived class: Current Account
class Current_account : public Account {
public:
    // Constructor
    Current_account(std::string n, float b)
        : Account(n, "Current", b) {
        std::cout << "Current Account Constructor Called\n";
    }

    // Withdraw function
    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: " << amount << std::endl;
        } else {
            std::cout << "Insufficient Balance\n";
        }
    }

    // Destructor
    ~Current_account() {
        std::cout << "Current Account Destructor Called\n";
    }
};

// Main function
int main() {
    Saving_account s("Ali", 1000, 5);
    s.deposit(500);
    s.compute_interest();
    s.withdraw(300);
    s.display();

    std::cout << "---------------------\n";

    Current_account c("Ahmed", 2000);
    c.deposit(1000);
    c.withdraw(500);
    c.display();

    return 0;
}