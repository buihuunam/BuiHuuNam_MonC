#include <iostream>

using namespace std;

int main() {
    // Khai báo và khởi tạo biến
    int numberOfShares = 750;
    double stockPricePerShare = 35.00;
    double commissionRate = 0.02; // 2%

    // Tính giá trị cổ phiếu (không kể phí môi giới)
    double stockAmount = numberOfShares * stockPricePerShare;

    // Tính phí môi giới
    double commissionAmount = stockAmount * commissionRate;

    // Tính tổng giá trị thanh toán (cổ phiếu và phí môi giới)
    double totalAmountPaid = stockAmount + commissionAmount;

    // Hiển thị kết quả
    cout << "So tien chi cho co phieu (khong ke phi moi gioi): $" << stockAmount << endl;
    cout << "So tien phi moi gioi: $" << commissionAmount << endl;
    cout << "Tong so tien chi tra (co phieu va phi moi gioi): $" << totalAmountPaid << endl;

    return 0;
}
