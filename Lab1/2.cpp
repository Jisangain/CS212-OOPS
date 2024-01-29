#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    string account_number;
    string account_type;
    double balance;

public:
    void assign(string name, string account_number, string account_type, double balance) {
        this-> name = name;
        this-> account_number = account_number;
        this -> account_type = account_type;
        this-> balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance" << endl << endl;
        } else {
            balance -= amount;
        }
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Account number: " << account_number << endl;
        cout << "Account type: " << account_type << endl;
        cout << "Balance: " << balance << endl << endl;
    }
};

int main() {
    // Test the program// 
    BankAccount test;//creating the object//
    test.assign("Jisan Gain", "638486486", "Savings", 50);
    test.deposit(200);
    test.display();
    test.withdraw(100);
    test.withdraw(500);

    // Modify the class and program for handling 10 customers//
   BankAccount accounts[10];
    for (int i = 0; i < 10; i++) {
        accounts[i].assign("Customer " + to_string(i+1), "ACC" + to_string(i+1), "Savings", 1000);
        accounts[i].deposit(500);
        accounts[i].withdraw(200);
        accounts[i].display();
    }
// here to_string function  is used to convert the data to string//
    return 0;
}