#include <iostream>
#include <string>

using namespace std;

int main() {
    // Initialize variables to store total rainfall and month count
    double totalRainfall = 0;
    int months = 3;

    // Initialize an array to store the names of the months
    string monthNames[3];

    // Loop to input rainfall data for each month
    for (int i = 0; i < months; i++) {
        cout << "Enter the name of month " << (i + 1) << ": ";
        cin >> monthNames[i];
        cout << "Enter the amount of rain (in inches) for " << monthNames[i] << ": ";
        double rainfall;
        cin >> rainfall;

        // Add the rainfall to the total
        totalRainfall += rainfall;
    }

    // Calculate the average rainfall
    double averageRainfall = totalRainfall / months;

    // Display the result
    cout << "The average rainfall for " << monthNames[0] << ", " << monthNames[1] << ", and " << monthNames[2]
         << " is " << averageRainfall << " inches." << endl;

    return 0;
}
