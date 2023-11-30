#include <iostream>
using namespace std;

int main() {
    int numYears;

    // Prompt the user for the number of years
    cout << "Enter the number of years: ";
    cin >> numYears;

    // Input validation: Ensure the number of years is at least 1
    if (numYears < 1) {
        cout << "Please enter a valid number of years (at least 1)." << endl;
        return 1; // Exit the program with an error code
    }

    double totalRainfall = 0.0;
    int totalMonths = 0;

    // Outer loop for each year
    for (int year = 1; year <= numYears; ++year) {
        // Inner loop for each month
        for (int month = 1; month <= 12; ++month) {
            double monthlyRainfall;

            // Prompt the user for the monthly rainfall
            do {
                cout << "Enter the inches of rainfall for month " << month << " (year " << year << "): ";
                cin >> monthlyRainfall;

                // Input validation: Ensure the monthly rainfall is non-negative
                if (monthlyRainfall < 0) {
                    cout << "Please enter a valid non-negative monthly rainfall." << endl;
                }
            } while (monthlyRainfall < 0);

            totalRainfall += monthlyRainfall;
            totalMonths++;
        }
    }

    // Calculate the average rainfall
    double averageRainfall = totalRainfall / totalMonths;

    // Display the results
    cout << "Number of months: " << totalMonths << endl;
    cout << "Total inches of rainfall: " << totalRainfall << " inches" << endl;
    cout << "Average monthly rainfall: " << averageRainfall << " inches" << endl;

    return 0;
}
