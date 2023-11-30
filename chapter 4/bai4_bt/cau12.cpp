#include <iostream>
using namespace std;

int main() {
    // Constants for the package price and discount rates
    const double PACKAGE_PRICE = 99.0;
    const double DISCOUNT_10_TO_19 = 0.2;  // 20% discount
    const double DISCOUNT_20_TO_49 = 0.3;  // 30% discount
    const double DISCOUNT_50_TO_99 = 0.4;  // 40% discount
    const double DISCOUNT_100_OR_MORE = 0.5;  // 50% discount

    int quantity;

    // Input validation: Make sure the number of units is greater than 0
    do {
        cout << "Enter the number of units sold: ";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid input. Please enter a positive number of units." << endl;
        }
    } while (quantity <= 0);

    double totalCost;

    if (quantity >= 10 && quantity <= 19) {
        totalCost = quantity * PACKAGE_PRICE * (1 - DISCOUNT_10_TO_19);
    } else if (quantity >= 20 && quantity <= 49) {
        totalCost = quantity * PACKAGE_PRICE * (1 - DISCOUNT_20_TO_49);
    } else if (quantity >= 50 && quantity <= 99) {
        totalCost = quantity * PACKAGE_PRICE * (1 - DISCOUNT_50_TO_99);
    } else if (quantity >= 100) {
        totalCost = quantity * PACKAGE_PRICE * (1 - DISCOUNT_100_OR_MORE);
    } else {
        totalCost = quantity * PACKAGE_PRICE;  // No discount for quantities less than 10
    }

    cout << "Total cost of the purchase: $" << totalCost << endl;

    return 0;
}
