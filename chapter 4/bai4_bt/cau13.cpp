#include <iostream>
using namespace std;

int main() {
    // Constants for shipping rates and constraints
    const double RATE_2KG_OR_LESS = 1.10;
    const double RATE_OVER_2KG_UP_TO_6KG = 2.20;
    const double RATE_OVER_6KG_UP_TO_10KG = 3.70;
    const double RATE_OVER_10KG_UP_TO_20KG = 4.80;
    const double MAX_WEIGHT = 20.0;
    const double MIN_DISTANCE = 10.0;
    const double MAX_DISTANCE = 3000.0;

    double weight, distance;

    // Input: Weight of the package and shipping distance
    cout << "Enter the weight of the package (in kilograms): ";
    cin >> weight;

    if (weight <= 0 || weight > MAX_WEIGHT) {
        cout << "Invalid input: Weight must be greater than 0 and not exceed 20 kg." << endl;
        return 1;  // Exit program with an error code
    }

    cout << "Enter the shipping distance (in miles): ";
    cin >> distance;

    if (distance < MIN_DISTANCE || distance > MAX_DISTANCE) {
        cout << "Invalid input: Distance must be between 10 and 3000 miles." << endl;
        return 1;  // Exit program with an error code
    }

    double charges;

    // Calculate the shipping charges based on weight
    if (weight <= 2) {
        charges = (distance / 500) * RATE_2KG_OR_LESS;
    } else if (weight <= 6) {
        charges = (distance / 500) * RATE_OVER_2KG_UP_TO_6KG;
    } else if (weight <= 10) {
        charges = (distance / 500) * RATE_OVER_6KG_UP_TO_10KG;
    } else {
        charges = (distance / 500) * RATE_OVER_10KG_UP_TO_20KG;
    }

    // Display the shipping charges
    cout << "Shipping charges: $" << charges << endl;

    return 0;
}
