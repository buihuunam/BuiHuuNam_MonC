#include <iostream>
using namespace std;

// Hàm tính kích thước dân số cho mỗi năm
double calculatePopulationSize(double previousPopulation, double birthRate, double deathRate) {
    return previousPopulation + (previousPopulation * birthRate / 100) - (previousPopulation * deathRate / 100);
}

int main() {
    // Nhập dữ liệu từ người dùng
    double startingSize, birthRate, deathRate;
    int numberOfYears;

    cout << "Enter the starting size of the population: ";
    cin >> startingSize;

    // Kiểm tra đầu vào
    if (startingSize < 2) {
        cerr << "Invalid input. Starting size must be at least 2." << endl;
        return 1; // Thoát chương trình với mã lỗi
    }

    cout << "Enter the annual birth rate (in percentage): ";
    cin >> birthRate;

    // Kiểm tra đầu vào
    if (birthRate < 0) {
        cerr << "Invalid input. Birth rate cannot be negative." << endl;
        return 1; // Thoát chương trình với mã lỗi
    }

    cout << "Enter the annual death rate (in percentage): ";
    cin >> deathRate;

    // Kiểm tra đầu vào
    if (deathRate < 0) {
        cerr << "Invalid input. Death rate cannot be negative." << endl;
        return 1; // Thoát chương trình với mã lỗi
    }

    cout << "Enter the number of years to display: ";
    cin >> numberOfYears;

    // Kiểm tra đầu vào
    if (numberOfYears < 1) {
        cerr << "Invalid input. Number of years must be at least 1." << endl;
        return 1; // Thoát chương trình với mã lỗi
    }

    // Hiển thị kích thước dân số cho mỗi năm
    for (int year = 1; year <= numberOfYears; ++year) {
        cout << "Year " << year << ": Population = " << startingSize << endl;
        startingSize = calculatePopulationSize(startingSize, birthRate, deathRate);
    }

    return 0;
}
