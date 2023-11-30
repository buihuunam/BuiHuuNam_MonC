#include <iostream>
using namespace std;

int main() {
    double annualInterestRate;
    double startingBalance;
    int monthsPassed;

    // Prompt the user for input
    cout << "Enter the annual interest rate (as a decimal): ";
    cin >> annualInterestRate;
    
    cout << "Enter the starting balance: ";
    cin >> startingBalance;

    cout << "Enter the number of months that have passed: ";
    cin >> monthsPassed;

    // Input validation: Ensure the annual interest rate is non-negative
    if (annualInterestRate < 0) {
        cout << "Please enter a non-negative annual interest rate." << endl;
        return 1; // Exit the program with an error code
    }

    // Initialize variables for totals
    double endingBalance = startingBalance;
    double totalDeposits = 0.0;
    double totalWithdrawals = 0.0;
    double totalInterestEarned = 0.0;

    for (int month = 1; month <= monthsPassed; ++month) {
        double deposits, withdrawals, monthlyInterest;

        // Prompt the user for deposits (non-negative)
        cout << "Enter the amount deposited in month " << month << ": ";
        cin >> deposits;
        
        if (deposits < 0) {
            cout << "Please enter a non-negative deposit amount." << endl;
            return 1; // Exit the program with an error code
        }

        // Prompt the user for withdrawals (non-negative)
        cout << "Enter the amount withdrawn in month " << month << ": ";
        cin >> withdrawals;

        if (withdrawals < 0) {
            cout << "Please enter a non-negative withdrawal amount." << endl;
            return 1; // Exit the program with an error code
        }

        // Calculate monthly interest
        monthlyInterest = (annualInterestRate / 12) * endingBalance;
        
        // Update balances and totals
        endingBalance += deposits - withdrawals + monthlyInterest;
        totalDeposits += deposits;
        totalWithdrawals += withdrawals;
        totalInterestEarned += monthlyInterest;
    }

    // Display the results
    cout << "Ending Balance: $" << endingBalance << endl;
    cout << "Total Deposits: $" << totalDeposits << endl;
    cout << "Total Withdrawals: $" << totalWithdrawals << endl;
    cout << "Total Interest Earned: $" << totalInterestEarned << endl;

    return 0;
}
