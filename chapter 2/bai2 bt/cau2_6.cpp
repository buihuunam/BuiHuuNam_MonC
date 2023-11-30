#include <iostream>

using namespace std;

int main() {
    // Định nghĩa và khởi tạo biến
    double payAmount = 2200.0; // Số tiền mỗi kỳ lương
    int payPeriods = 26;      // Số lần lương mỗi năm
    double annualPay;         // Tổng thu nhập hàng năm

    // Tính tổng thu nhập hàng năm
    annualPay = payAmount * payPeriods;

    // Hiển thị kết quả
    cout << "Tổng thu nhập hàng năm của nhân viên là: $" << annualPay << endl;

    return 0;
}
