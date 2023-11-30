#include <iostream>
#include <cmath> // Thư viện cho hàm pow
using namespace std;

// Hàm để tính giá trị tương lai của tài khoản tiết kiệm
double futureValue(double presentValue, double monthlyInterestRate, int months) {
    // Tính giá trị tương lai
    double futureValue = presentValue * pow(1 + monthlyInterestRate, months);

    return futureValue;
}

int main() {
    // Nhập giá trị hiện tại, lãi suất hàng tháng và số tháng từ người dùng
    double presentValue, monthlyInterestRate;
    int months;

    cout << "Nhap gia tri hien tai cua tai khoan ($): ";
    cin >> presentValue;

    cout << "Nhap lai suat hang thang (%): ";
    cin >> monthlyInterestRate;

    cout << "Nhap so thang de giu tien trong tai khoan: ";
    cin >> months;

    // Chuyển đổi lãi suất hàng tháng thành tỉ lệ
    monthlyInterestRate /= 100.0;

    // Gọi hàm để tính và hiển thị giá trị tương lai
    double futureVal = futureValue(presentValue, monthlyInterestRate, months);
    cout << "Gia tri tuong lai cua tai khoan sau " << months << " thang la: $" << futureVal << endl;

    return 0;
}
