#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int startingPopulation;
    double dailyIncreasePercentage;
    int numDays;

    // Prompt the user for the starting population
    cout << "Enter the starting number of organisms (at least 2): ";
    cin >> startingPopulation;

    // Input validation: Ensure starting population is at least 2
    if (startingPopulation < 2) {
        cout << "Please enter a starting population of at least 2." << endl;
        return 1; // Exit the program with an error code
    }

    // Prompt the user for the daily population increase percentage
    cout << "Enter the average daily population increase (as a percentage, greater than or equal to 0): ";
    cin >> dailyIncreasePercentage;

    // Input validation: Ensure daily increase percentage is non-negative
    if (dailyIncreasePercentage < 0) {
        cout << "Please enter a non-negative daily population increase percentage." << endl;
        return 1; // Exit the program with an error code
    }

    // Prompt the user for the number of days
    cout << "Enter the number of days they will multiply (at least 1): ";
    cin >> numDays;

    // Input validation: Ensure number of days is at least 1
    if (numDays < 1) {
        cout << "Please enter a number of days greater than or equal to 1." << endl;
        return 1; // Exit the program with an error code
    }

    // Display table header
    cout << "Day\tPopulation" << endl;
    cout << "----------------" << endl;

    // Calculate and display population for each day
    double population = startingPopulation;
    for (int day = 1; day <= numDays; ++day) {
        cout << day << "\t" << fixed << setprecision(0) << population << endl;
        population += (population * dailyIncreasePercentage / 100);
    }

    return 0;
}
