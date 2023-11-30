#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate two random numbers between 1 and 100
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;

    // Calculate the correct answer
    int correctAnswer = num1 + num2;

    // Display the math problem to the student
    cout << "Math Tutor - Addition" << endl;
    cout << num1 << endl;
    cout << "+" << endl;
    cout << num2 << endl;
    cout << "Enter your answer: ";

    // Get the student's answer
    int studentAnswer;
    cin >> studentAnswer;

    // Check if the answer is correct
    if (studentAnswer == correctAnswer) {
        cout << "Congratulations! Your answer is correct." << endl;
    } else {
        cout << "Sorry, the correct answer is: " << correctAnswer << endl;
    }

    return 0;
}
