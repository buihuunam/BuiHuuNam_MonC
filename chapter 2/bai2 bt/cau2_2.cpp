#include <iostream>

using namespace std;

int main() {
    // Given percentage of total sales generated by the East Coast division
    double eastCoastPercentage = 0.58;

    // Total sales of the company
    double totalSales = 8.6;  // in million dollars

    // Calculate East Coast division's sales
    double eastCoastSales = eastCoastPercentage * totalSales;

    // Display the result
    cout << "The East Coast division is predicted to generate $" << eastCoastSales << " million in sales this year." << endl;

    return 0;
}