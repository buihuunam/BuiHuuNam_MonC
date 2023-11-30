#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main() {
    double initialBalance; // Initial balance
    double annualInterestRate; // Annual interest rate
    int numMonths; // Number of months
    double monthlyDeposit; // Monthly deposit
    double balance = 0.0; // Current balance

    // Open the output file for writing
    ofstream outputFile("SavingsAccountReport.txt");

    if (!outputFile) {
        cerr << "Error opening the output file." << endl;
        return 1;
    }

    // Get user input
    cout << "Enter the initial balance: $";
    cin >> initialBalance;

    cout << "Enter the annual interest rate (in decimal form): ";
    cin >> annualInterestRate;

    cout << "Enter the number of months: ";
    cin >> numMonths;

    cout << "Enter the monthly deposit: $";
    cin >> monthlyDeposit;

    // Write header to the output file
    outputFile << "Month\tBalance" << endl;
    outputFile << "------------------" << endl;

    // Calculate and write the savings account balance for each month
    for (int month = 1; month <= numMonths; ++month) {
        balance += initialBalance;
        balance += monthlyDeposit;
        balance += balance * (annualInterestRate / 12.0); // Monthly interest

        // Write the month and balance to the output file
        outputFile << month << "\t$" << fixed << setprecision(2) << balance << endl;
    }

    // Close the output file
    outputFile.close();

    cout << "Savings account report has been written to SavingsAccountReport.txt." << endl;

    return 0;
}
