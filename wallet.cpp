/*
 * Digital Wallet Transaction System
 * -----------------------------------------------------------
 * Assumptions made (stated explicitly since the problem leaves
 * them open):
 * 1. Transaction IDs are auto-generated, starting from 1, and
 *    increase by 1 for every successful Load/Payment action.
 *    (A failed payment due to insufficient balance does NOT
 *    generate a transaction ID.)
 * 2. Only the last 5 transactions are kept in memory at any
 *    time (older ones are shifted out), as per the requirement
 *    "browse through last five transactions".
 * 3. Reward points: every payment > 2000 earns 50 reward
 *    points. Every time reward points reach >= 1000, the user
 *    gets Rs. 10 added to balance and 1000 points are deducted
 *    (this can trigger more than once if enough points have
 *    accumulated).
 * 4. Negative or zero amounts are rejected as invalid input.
 * 5. Runtime polymorphism is demonstrated by calling
 *    loadBalance(), makePayment(), and showTransaction()
 *    through a Digital_wallet* base class pointer that actually
 *    points to a Transaction object.
 */

#include <iostream>
#include <string>
using namespace std;

// ---------------- Abstract Base Class ----------------
class Digital_wallet {
protected:
    double balance;
    int rewardPoints;

public:
    Digital_wallet() {
        balance = 0;
        rewardPoints = 0;
    }

    // Pure virtual functions -> makes this class abstract
    virtual void loadBalance(double amount) = 0;
    virtual void makePayment(double amount) = 0;
    virtual void showTransaction(int id) = 0;

    virtual ~Digital_wallet() {}
};

// ---------------- Derived Class ----------------
class Transaction : public Digital_wallet {
private:
    static const int MAX_STORED = 5;

    int transID[MAX_STORED];
    string transType[MAX_STORED];
    double transAmount[MAX_STORED];
    int count;      // how many slots are currently filled (max 5)
    int nextID;     // ever-increasing unique transaction id

    // Store only the last 5 transactions (shift-left when full)
    void store(int id, const string &type, double amount) {
        if (count < MAX_STORED) {
            transID[count] = id;
            transType[count] = type;
            transAmount[count] = amount;
            count++;
        } else {
            for (int i = 0; i < MAX_STORED - 1; i++) {
                transID[i]     = transID[i + 1];
                transType[i]   = transType[i + 1];
                transAmount[i] = transAmount[i + 1];
            }
            transID[MAX_STORED - 1]     = id;
            transType[MAX_STORED - 1]   = type;
            transAmount[MAX_STORED - 1] = amount;
        }
    }

public:
    Transaction() {
        count = 0;
        nextID = 1; // first transaction will be ID 1
    }

    // ---- Load Balance ----
    void loadBalance(double amount) override {
        if (amount <= 0) {
            cout << "Invalid amount! Load amount must be positive." << endl;
            return;
        }
        balance += amount;
        store(nextID, "Load", amount);
        cout << "Loaded: " << amount
             << " | Transaction ID: " << nextID
             << " | New Balance: " << balance << endl;
        nextID++;
    }

    // ---- Make Payment ----
    void makePayment(double amount) override {
        if (amount <= 0) {
            cout << "Invalid amount! Payment amount must be positive." << endl;
            return;
        }
        if (amount > balance) {
            cout << "Insufficient Balance!" << endl;
            return;
        }

        balance -= amount;

        // Reward logic: > 2000 payment earns 50 points
        if (amount > 2000) {
            rewardPoints += 50;
        }

        // Every 1000 points earns balance of 10 (can trigger multiple times)
        while (rewardPoints >= 1000) {
            balance += 10;
            rewardPoints -= 1000;
        }

        store(nextID, "Payment", amount);
        cout << "Payment Done: " << amount
             << " | Transaction ID: " << nextID
             << " | Remaining Balance: " << balance << endl;
        nextID++;
    }

    // ---- Payment History / show one transaction (runtime polymorphism) ----
    void showTransaction(int id) override {
        for (int i = 0; i < count; i++) {
            if (transID[i] == id) {
                cout << "\n--- Transaction Details ---" << endl;
                cout << "Transaction ID : " << transID[i] << endl;
                cout << "Type           : " << transType[i] << endl;
                cout << "Amount         : " << transAmount[i] << endl;
                cout << "Current Balance: " << balance << endl;
                cout << "Reward Points  : " << rewardPoints << endl;
                return;
            }
        }
        cout << "Transaction not found in the last " << MAX_STORED
             << " records!" << endl;
    }

    // Extra helper: browse through all currently stored (last 5) transactions
    void showHistory() {
        cout << "\n--- Last " << count << " Transaction(s) ---" << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". ID: " << transID[i]
                 << " | Type: " << transType[i]
                 << " | Amount: " << transAmount[i] << endl;
        }
    }
};

// ---------------- Main Function ----------------
int main() {
    Digital_wallet* wallet;   // Base class pointer
    Transaction t;
    wallet = &t;              // Runtime polymorphism: base pointer -> derived object

    wallet->loadBalance(5000);
    wallet->makePayment(2500);
    wallet->makePayment(1000);
    wallet->loadBalance(2000);
    wallet->makePayment(3000);
    wallet->makePayment(1500); // by now, more than 5 transactions have occurred

    t.showHistory(); // shows only the last 5, with correct unique IDs

    int id;
    cout << "\nEnter Transaction ID to view details: ";
    cin >> id;
    wallet->showTransaction(id); // dynamic dispatch through base class pointer

    return 0;
}