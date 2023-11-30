#include <iostream>
#include <fstream>
using namespace std;
int main() {
    //tao ra bien nhap file
    ifstream inputFile("Random.txt");
    double number;
    double sum = 0.0;
    int count = 0;

    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    while (inputFile >> number) {
        sum += number;
        count++;
    }

    inputFile.close();

    if (count > 0) {
        double average = sum / count;

        cout << "A) Number of numbers in the file: " << count << endl;
        cout << "B) Sum of all the numbers in the file: " << sum << endl;
        cout << "C) Average of all the numbers in the file: " << average << endl;
    } else {
        cout << "No numbers found in the file." << endl;
    }

    return 0;
}
