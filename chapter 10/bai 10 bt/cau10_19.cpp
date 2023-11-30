#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to convert a numeric amount to words
string convertToWords(double amount) {
    const string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const string teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const string tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string result;

    // Extract dollars and cents
    int dollars = static_cast<int>(amount);
    int cents = static_cast<int>((amount - dollars) * 100);

    // Convert dollars to words
    if (dollars >= 1000) {
        result += ones[dollars / 1000] + " Thousand ";
        dollars %= 1000;
    }
    if (dollars >= 100) {
        result += ones[dollars / 100] + " Hundred ";
        dollars %= 100;
    }
    if (dollars >= 20) {
        result += tens[dollars / 10] + " ";
        dollars %= 10;
    }
    if (dollars >= 11 && dollars <= 19) {
        result += teens[dollars - 10] + " ";
        dollars = 0;  // Teens are already complete words
    }
    if (dollars > 0) {
        result += ones[dollars] + " ";
    }

    // Convert cents to words
    result += "and " + to_string(cents) + "/100";

    return result;
}

int main() {
    // Get user input
    string date, payee;
    double amount;

    cout << "Enter the date: ";
    getline(cin, date);

    cout << "Enter the payee's name: ";
    getline(cin, payee);

    cout << "Enter the amount (up to $10,000): $";
    cin >> amount;

    // Input validation
    if (amount < 0 || amount > 10000) {
        cerr << "Invalid amount. Please enter a non-negative amount up to $10,000." << endl;
        return 1;
    }

    // Display the simulated paycheck
    cout << fixed << setprecision(2);
    cout << "Date: " << date << endl;
    cout << "Pay to the Order of: " << payee << " $" << amount << endl;
    cout << convertToWords(amount) << endl;

    return 0;
}
