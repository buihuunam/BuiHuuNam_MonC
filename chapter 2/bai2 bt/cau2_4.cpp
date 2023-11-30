#include <iostream>

using namespace std;

int main() {
    // Constants for tax and tip rates
    const double taxRate = 0.0675;  // 6.75%
    const double tipRate = 0.20;    // 20%

    // Meal charge
    double mealCharge = 88.67;

    // Calculate tax amount
    double taxAmount = mealCharge * taxRate;

    // Calculate total after adding tax
    double totalWithTax = mealCharge + taxAmount;

    // Calculate tip amount
    double tipAmount = totalWithTax * tipRate;

    // Calculate total bill
    double totalBill = totalWithTax + tipAmount;

    // Display the results
    cout << "Meal Cost: $" << mealCharge << endl;
    cout << "Tax Amount: $" << taxAmount << endl;
    cout << "Tip Amount: $" << tipAmount << endl;
    cout << "Total Bill: $" << totalBill << endl;

    return 0;
}
