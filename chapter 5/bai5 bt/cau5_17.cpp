#include <iostream>
using namespace std;

int main() {
    const int numStores = 5;
    int sales[numStores];

    // Prompt the user to enter sales for each store
    for (int i = 0; i < numStores; ++i) {
        cout << "Enter today's sales for store " << (i + 1) << ": ";
        cin >> sales[i];
    }

    cout << "SALES BAR CHART" << endl;
    cout << "(Each * = $100)" << endl;

    // Display the bar graph
    for (int i = 0; i < numStores; ++i) {
        cout << "Store " << (i + 1) << ": ";
        // Calculate the number of asterisks to display
        int numAsterisks = sales[i] / 100;
        for (int j = 0; j < numAsterisks; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
