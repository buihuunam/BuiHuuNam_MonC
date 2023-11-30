#include <iostream>
using namespace std;

int main() {
    const double WIDGETWEIGHT = 12.5;  // Weight of a single widget in pounds

    double palletWeightAlone, palletWeightWithWidgets;

    // Prompt the user to enter the weights
    cout << "Enter the weight of the pallet alone (in pounds): ";
    cin >> palletWeightAlone;
    
    cout << "Enter the weight of the pallet with widgets (in pounds): ";
    cin >> palletWeightWithWidgets;

    // Calculate the number of widgets stacked on the pallet
    int numberOfWidgets = static_cast<int>((palletWeightWithWidgets - palletWeightAlone) / WIDGETWEIGHT);

    // Display the result
    cout << "Number of widgets stacked on the pallet: " << numberOfWidgets << endl;

    return 0;
}
