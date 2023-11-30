#include <iostream>
using namespace std;

int main() {
    // Declare variables
    double calories, fatGrams, caloriesFromFat, percentageOfCaloriesFromFat;

    // Get input for calories and fat grams
    cout << "Enter the number of calories in the food: ";
    cin >> calories;
    cout << "Enter the number of fat grams in the food: ";
    cin >> fatGrams;

    // Input validation
    if (calories < 0 || fatGrams < 0 || fatGrams * 9 > calories) {
        cout << "Error: Invalid input. Calories and fat grams must be non-negative, and calories from fat cannot exceed total calories." << endl;
        return 1;
    }

    // Calculate calories from fat
    caloriesFromFat = fatGrams * 9;

    // Calculate the percentage of calories from fat
    percentageOfCaloriesFromFat = (caloriesFromFat / calories) * 100;

    // Display the result
    cout << "Percentage of calories from fat: " << percentageOfCaloriesFromFat << "%" << endl;

    // Check if the food is low in fat
    if (percentageOfCaloriesFromFat < 30) {
        cout << "This food is low in fat." << endl;
    }

    return 0;
}
