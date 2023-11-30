#include <iostream>
using namespace std;

// Hàm để chuyển đổi nhiệt độ từ Fahrenheit sang Celsius
double celsius(double fahrenheit) {
    return 5.0 / 9.0 * (fahrenheit - 32);
}

int main() {
    // Hiển thị tiêu đề của bảng
    cout << "Fahrenheit\tCelsius\n";
    cout << "-------------------------\n";

    // Gọi hàm để chuyển đổi và hiển thị bảng từ Fahrenheit 0 đến 20
    for (int fahrenheit = 0; fahrenheit <= 20; ++fahrenheit) {
        double celsiusTemp = celsius(fahrenheit);
        cout << fahrenheit << "\t\t" << celsiusTemp << endl;
    }

    return 0;
}
