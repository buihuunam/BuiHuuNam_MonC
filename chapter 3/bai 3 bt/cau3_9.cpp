#include <iostream>
using namespace std;

int main() {
    const int COOKIESPERBAG = 30;
    const int SERVINGSPERBAG = 10;
    const int CALORIESPERSERVING = 300;

    int cookiesEaten;

    // Prompt the user to enter the number of cookies eaten
    cout << "Enter the number of cookies you actually ate: ";
    cin >> cookiesEaten;

    // Calculate the total calories consumed
    int totalCalories = (cookiesEaten * CALORIESPERSERVING) / (COOKIESPERBAG / SERVINGSPERBAG);

    // Display the result
    cout << "Total calories consumed: " << totalCalories << " calories" << endl;

    return 0;
}
