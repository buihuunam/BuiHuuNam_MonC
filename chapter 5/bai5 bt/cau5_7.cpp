#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numDays;

    // Prompt the user for the number of days worked
    cout << "Enter the number of days worked: ";
    cin >> numDays;

    // Validate input: Ensure numDays is greater than or equal to 1
    if (numDays < 1) {
        cout << "Please enter a number of days greater than or equal to 1." << endl;
        return 1; // Exit the program with an error code
    }

    double totalPay = 0.01; // Initial salary (one penny)
    
    // Display table header
    cout << "Day\tSalary Earned" << endl;
    cout << "------------------" << endl;

    // Calculate and display salary for each day
    for (int day = 1; day <= numDays; ++day) {
        cout << day << "\t$" << fixed << setprecision(2) << totalPay << endl;
        totalPay *= 2; // Double the salary for the next day
    }

    return 0;
}
