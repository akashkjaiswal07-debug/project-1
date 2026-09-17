
#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Customer Model
class Customer {
public:
    int customerId;
    string name;
    string phone;

    void createCustomer() {
        cout << "\nEnter Customer ID: ";
        cin >> customerId;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Phone Number: ";
        cin >> phone;
    }

    void displayCustomer() {
        cout << "\nCustomer ID: " << customerId << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
    }
};

// Transaction Model
class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void displayTransaction() {
        cout << type << " : Rs. " << amount << endl;
    }
};

// Bank Account Model
class BankAccount {
public:
    int accountNumber;
    string accountType;
    double balance;

    vector<Transaction> history;

    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Account Type (Savings/Current): ";
        cin >> accountType;

        cout << "Enter Opening Balance: ";
        cin >> balance;

        cout << "Account created successfully!" << endl;
    }

    void deposit() {
        double amount;

        cout << "\nEnter Deposit Amount: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;

            history.push_back(
                Transaction("Deposit", amount)
            );

            cout << "Deposit successful!" << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }

    void withdraw() {
        double amount;

        cout << "\nEnter Withdrawal Amount: ";
        cin >> amount;

        if (amount > 0 && amount <= balance) {
            balance -= amount;

            history.push_back(
                Transaction("Withdrawal", amount)
            );

            cout << "Withdrawal successful!" << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    void displayAccount() {
        cout << "\n===== ACCOUNT DETAILS =====" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    void showHistory() {
        cout << "\n===== TRANSACTION HISTORY =====" << endl;

        if (history.empty()) {
            cout << "No transactions yet." << endl;
        } else {
            for (int i = 0; i < history.size(); i++) {
                history[i].displayTransaction();
            }
        }
    }
};

// Transfer function
void transferMoney(BankAccount &from, BankAccount &to) {
    double amount;

    cout << "\nEnter Transfer Amount: ";
    cin >> amount;

    if (amount > 0 && amount <= from.balance) {
        from.balance -= amount;
        to.balance += amount;

        from.history.push_back(
            Transaction("Transfer Sent", amount)
        );

        to.history.push_back(
            Transaction("Transfer Received", amount)
        );

        cout << "Transfer successful!" << endl;
    } else {
        cout << "Invalid amount or insufficient balance!" << endl;
    }
}

int main() {
    Customer customer;

    BankAccount account1, account2;

    int choice;

    cout << "===== SMART BANKING SYSTEM =====" << endl;

    customer.createCustomer();

    account1.createAccount();

    do {
        cout << "\n===== MAIN MENU =====" << endl;
        cout << "1. Display Customer" << endl;
        cout << "2. Display Account" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Create Second Account" << endl;
        cout << "6. Transfer Money" << endl;
        cout << "7. Transaction History" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );

            cout << "Please enter a valid number!" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                customer.displayCustomer();
                break;

            case 2:
                account1.displayAccount();
                break;

            case 3:
                account1.deposit();
                break;

            case 4:
                account1.withdraw();
                break;

            case 5:
                account2.createAccount();
                break;

            case 6:
                transferMoney(account1, account2);
                break;

            case 7:
                account1.showHistory();
                break;

            case 8:
                cout << "\nThank you for using Smart Banking System!" << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 8);

    return 0;
}