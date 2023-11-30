#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Function to calculate the mode of an array
int calculateMode(const int *array, int size) {
    // ... (Implement the mode calculation function as described in a previous response)
}

// Function to calculate the median of an array
double calculateMedian(const int *array, int size) {
    // ... (Implement the median calculation function as described in a previous response)
}

int main() {
    int numStudents;

    // Step A: Ask the user how many students were surveyed
    cout << "Enter the number of students surveyed: ";
    cin >> numStudents;

    // Input validation
    while (numStudents <= 0) {
        cout << "Please enter a positive number of students: ";
        cin >> numStudents;
    }

    // Step B: Dynamically allocate an array of integers
    int *moviesPerStudent = new int[numStudents];

    // Allow the user to enter the number of movies each student saw
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter the number of movies student " << i + 1 << " saw: ";
        cin >> moviesPerStudent[i];

        // Input validation
        while (moviesPerStudent[i] < 0) {
            cout << "Please enter a non-negative number of movies: ";
            cin >> moviesPerStudent[i];
        }
    }

    // Step C: Calculate and display the average, median, and mode
    int sum = 0;
    for (int i = 0; i < numStudents; ++i) {
        sum += moviesPerStudent[i];
    }

    double average = static_cast<double>(sum) / numStudents;
    double median = calculateMedian(moviesPerStudent, numStudents);
    int mode = calculateMode(moviesPerStudent, numStudents);

    cout << fixed << setprecision(2);
    cout << "Average number of movies: " << average << endl;
    cout << "Median number of movies: " << median << endl;
    cout << "Mode number of movies: " << mode << endl;

    // Step D: Release dynamically allocated memory
    delete[] moviesPerStudent;

    return 0;
}
