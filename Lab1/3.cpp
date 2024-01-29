#include <iostream>
#include <cmath>
using namespace std;

class DB; // Forward declaration

class DM {
private:
    int meters;
    float centimeters;

public:
    DM() : meters(0), centimeters(0.0) {}

    void readDistance() {
        cout << "Enter distance in meters: ";
        cin >> meters;
        cout << "Enter distance in centimeters: ";
        cin >> centimeters;
    }

    void displayDistance() const {
        cout << "Distance: " << meters << " meters and " << centimeters << " centimeters\n";
    }

    // Friend function for addition
    friend DM addDistances(const DM&, const DB&);
};

class DB {
private:
    int feet;
    float inches;

public:
    DB() : feet(0), inches(0.0) {}

    void readDistance() {
        cout << "Enter distance in feet: ";
        cin >> feet;
        cout << "Enter distance in inches: ";
        cin >> inches;
    }

    void displayDistance() const {
        cout << "Distance: " << feet << " feet and " << inches << " inches\n";
    }

    // Friend function for addition
    friend DM addDistances(const DM&, const DB&);
};

// Friend function definition
DM addDistances(const DM& d1, const DB& d2) {
    DM result;

    // Convert DB to DM
    float totalCentimeters = (d2.feet * 30.48) + (d2.inches * 2.54) + d1.centimeters;
    // Add DM and converted DB
    result.meters = d1.meters + static_cast<int>(totalCentimeters / 100);
    result.centimeters = static_cast<int>(totalCentimeters) % 100 + fmod(totalCentimeters, 1.0);

    return result;
}

int main() {
    DM dmObj;
    DB dbObj;

    // Read distances
    cout << "Enter distance in meters and centimeters:\n";
    dmObj.readDistance();

    cout << "\nEnter distance in feet and inches:\n";
    dbObj.readDistance();

    // Add distances using friend function
    DM result = addDistances(dmObj, dbObj);

    // Display the result in the appropriate format
    result.displayDistance();

    return 0;
}