#include <iostream>
using namespace std;

int main() {
    // Constants for the original recipe
    const double sugarPerCookie = 1.5 / 48;
    const double butterPerCookie = 1.0 / 48;
    const double flourPerCookie = 2.75 / 48;

    // Variables to store user input
    int numCookies;

    // Prompt the user to enter the number of cookies they want to make
    cout << "Enter the number of cookies you want to make: ";
    cin >> numCookies;

    // Calculate the amount of each ingredient needed for the specified number of cookies
    double sugarAmount = sugarPerCookie * numCookies;
    double butterAmount = butterPerCookie * numCookies;
    double flourAmount = flourPerCookie * numCookies;

    // Display the results
    cout << "For " << numCookies << " cookies, you will need:" << endl;
    cout << sugarAmount << " cups of sugar" << endl;
    cout << butterAmount << " cups of butter" << endl;
    cout << flourAmount << " cups of flour" << endl;

    return 0;
}
