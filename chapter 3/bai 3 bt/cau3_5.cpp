#include <iostream>
using namespace std;

int main() {
    int numMales, numFemales;
    
    // Prompt the user to enter the number of males and females
    cout << "Enter the number of males: ";
    cin >> numMales;
    
    cout << "Enter the number of females: ";
    cin >> numFemales;
    
    int totalStudents = numMales + numFemales;
    
    // Calculate the percentages
    double malePercentage = (static_cast<double>(numMales) / totalStudents) * 100;
    double femalePercentage = (static_cast<double>(numFemales) / totalStudents) * 100;
    
    // Display the results
    cout << "Percentage of males: " << malePercentage << "%" << endl;
    cout << "Percentage of females: " << femalePercentage << "%" << endl;
    
    return 0;
}
