#include <iostream>

using namespace std;

int main() {
    // Khai báo và khởi tạo biến
    double costPrice = 14.95;  // Giá vốn của bo mạch
    double profitPercentage = 0.35;  // Tỷ lệ lợi nhuận (35%)

    // Tính giá bán
    double sellingPrice = costPrice * (1 + profitPercentage);

    // Hiển thị kết quả
    cout << "Gia ban cua bo mach dien tu la: $" << sellingPrice << endl;

    return 0;
}
