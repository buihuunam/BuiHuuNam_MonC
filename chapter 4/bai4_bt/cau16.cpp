#include <iostream>
#include <string>
using namespace std;

int main() {
    // Variables to store runner names and times
    string runner1, runner2, runner3;
    double time1, time2, time3;

    // Input: Runner names and times
    cout << "Enter the name of the first runner: ";
    cin >> runner1;
    cout << "Enter the time it took for " << runner1 << " to finish (in seconds): ";
    cin >> time1;

    cout << "Enter the name of the second runner: ";
    cin >> runner2;
    cout << "Enter the time it took for " << runner2 << " to finish (in seconds): ";
    cin >> time2;

    cout << "Enter the name of the third runner: ";
    cin >> runner3;
    cout << "Enter the time it took for " << runner3 << " to finish (in seconds): ";
    cin >> time3;

    // Determine the order of finish
    string firstPlace, secondPlace, thirdPlace;

    if (time1 < time2 && time1 < time3) {
        firstPlace = runner1;
        if (time2 < time3) {
            secondPlace = runner2;
            thirdPlace = runner3;
        } else {
            secondPlace = runner3;
            thirdPlace = runner2;
        }
    } else if (time2 < time1 && time2 < time3) {
        firstPlace = runner2;
        if (time1 < time3) {
            secondPlace = runner1;
            thirdPlace = runner3;
        } else {
            secondPlace = runner3;
            thirdPlace = runner1;
        }
    } else {
        firstPlace = runner3;
        if (time1 < time2) {
            secondPlace = runner1;
            thirdPlace = runner2;
        } else {
            secondPlace = runner2;
            thirdPlace = runner1;
        }
    }

    // Display the results
    cout << "Results:" << endl;
    cout << "First Place: " << firstPlace << endl;
    cout << "Second Place: " << secondPlace << endl;
    cout << "Third Place: " << thirdPlace << endl;

    return 0;
}
