#include <iostream>
#include <cmath> // Thư viện cho hàm pow
using namespace std;

// Hàm để tính giá trị hiện tại dựa trên công thức giá trị hiện tại
double presentValue(double futureValue, double annualInterestRate, int years) {
    // Chuyển đổi lãi suất hàng năm thành lãi suất hàng năm
    double r = annualInterestRate / 100.0;

    // Tính giá trị hiện tại
    double presentValue = futureValue / pow(1 + r, years);

    return presentValue;
}

int main() {
    // Nhập giá trị tương lai, lãi suất hàng năm và số năm từ người dùng
    double futureValue, annualInterestRate;
    int years;

    cout << "Nhap gia tri tuong lai (VD: 10000): $";
    cin >> futureValue;

    cout << "Nhap lai suat hang nam (VD: 5.0): ";
    cin >> annualInterestRate;

    cout << "Nhap so nam (VD: 10): ";
    cin >> years;

    // Gọi hàm để tính và hiển thị giá trị hiện tại
    double presentVal = presentValue(futureValue, annualInterestRate, years);
    cout << "Ban can gui ngay hom nay: $" << presentVal << endl;

    return 0;
}
