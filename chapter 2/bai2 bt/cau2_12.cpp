#include <iostream>

using namespace std;

int main() {
    // Khai báo và khởi tạo biến
    double squareFeetInOneAcre = 43560.0;  // Số feet vuông trong 1 acre
    double landAreaInSquareFeet = 391876.0; // Diện tích đất trong feet vuông

    // Tính số acre
    double acres = landAreaInSquareFeet / squareFeetInOneAcre;

    // Hiển thị kết quả
    cout << "Khu dat co " << acres << " mau dat." << endl;

    return 0;
}
