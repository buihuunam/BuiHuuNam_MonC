#include <iostream>
using namespace std;

int main() {
    // Constants for fees and balance threshold
    const double MONTHLY_FEE = 10.0;
    const double LOW_BALANCE_FEE = 15.0;
    const double FEE_LESS_THAN_20 = 0.10;
    const double FEE_20_TO_39 = 0.08;
    const double FEE_40_TO_59 = 0.06;
    const double FEE_60_OR_MORE = 0.04;
    const double BALANCE_THRESHOLD = 400.0;

    double balance;
    int numChecks;

    // Input: Beginning balance and number of checks
    cout << "Enter the beginning balance: $";
    cin >> balance;

    if (balance < 0) {
        cout << "URGENT: The account is overdrawn!" << endl;
        return 1;  // Exit program with an error code
    }

    cout << "Enter the number of checks written: ";
    cin >> numChecks;

    if (numChecks < 0) {
        cout << "Invalid input: Number of checks cannot be negative." << endl;
        return 1;  // Exit program with an error code
    }

    // Calculate the total fees
    double totalFees = MONTHLY_FEE;

    if (balance < BALANCE_THRESHOLD) {
        totalFees += LOW_BALANCE_FEE;
    }

    if (numChecks < 20) {
        totalFees += numChecks * FEE_LESS_THAN_20;
    } else if (numChecks >= 20 && numChecks <= 39) {
        totalFees += numChecks * FEE_20_TO_39;
    } else if (numChecks >= 40 && numChecks <= 59) {
        totalFees += numChecks * FEE_40_TO_59;
    } else {
        totalFees += numChecks * FEE_60_OR_MORE;
    }

    // Display the total service fees
    cout << "Total service fees for the month: $" << totalFees << endl;

    return 0;
}
