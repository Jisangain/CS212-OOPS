#include <iostream>
#include <string>
using namespace std;

class JuiceMachine {
private:
    string juiceOptions[4] = {"orange juice", "apple juice", "mango juice", "strawberrybanana juice"};
    int juicePrices[4] = {50, 65, 80, 85};

public:
    void displayMenu() {
        cout << "\n\nTo select an item, enter:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << " for " << juiceOptions[i] << " (" << juicePrices[i] << " cents)" << endl;
        }
        cout << "0 to exit" << endl;
    }

    void serveJuice(int choice) {
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please select a valid option." << endl;
            return;
        }

        int selectedJuicePrice = juicePrices[choice - 1];
        cout << "Please deposit " << selectedJuicePrice << " cents" << endl;

        int depositedAmount = 0;
        while (depositedAmount < selectedJuicePrice) {
            int deposit;
            cin >> deposit;
            depositedAmount += deposit;
            if (depositedAmount < selectedJuicePrice) {
                cout << "Please deposit another " << selectedJuicePrice - depositedAmount << " cents" << endl;
            }
        }

        cout << "Collect your " << juiceOptions[choice - 1];
        if (depositedAmount > selectedJuicePrice) {
            cout << " and take " << depositedAmount - selectedJuicePrice << " cents";
        }
    }
};

int main() {
    JuiceMachine juiceMachine;
    int choice;

    cout << "Welcome to Jisan's Juice Shop" << endl;

    do {
        juiceMachine.displayMenu();
        cin >> choice;
        if (choice != 0) {
            juiceMachine.serveJuice(choice);
        }
    } while (choice != 0);

    cout << "Thank you for using Jisan's Juice Shop!" << endl;

    return 0;
}