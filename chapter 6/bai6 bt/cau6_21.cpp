#include <iostream>
using namespace std;

// Hàm tính toán lợi nhuận hoặc lỗ từ bán cổ phiếu
double calculateProfitOrLoss(int numberOfShares, double purchasePricePerShare, double purchaseCommission,
                              double salePricePerShare, double saleCommission) {
    double purchaseCost = numberOfShares * purchasePricePerShare + purchaseCommission;
    double saleIncome = numberOfShares * salePricePerShare - saleCommission;
    return saleIncome - purchaseCost;
}

// Hàm chính
int main() {
    int numStockSales;
    double totalProfitOrLoss = 0;

    // Nhập số lượng giao dịch cổ phiếu
    cout << "Enter the number of stock sales: ";
    cin >> numStockSales;

    // Lặp qua từng giao dịch
    for (int i = 1; i <= numStockSales; ++i) {
        int numberOfShares;
        double purchasePricePerShare, purchaseCommission, salePricePerShare, saleCommission;

        // Nhập dữ liệu từ người dùng cho mỗi giao dịch
        cout << "\nStock Sale " << i << ":\n";
        cout << "Enter the number of shares: ";
        cin >> numberOfShares;

        cout << "Enter the purchase price per share: $";
        cin >> purchasePricePerShare;

        cout << "Enter the purchase commission: $";
        cin >> purchaseCommission;

        cout << "Enter the sale price per share: $";
        cin >> salePricePerShare;

        cout << "Enter the sale commission: $";
        cin >> saleCommission;

        // Gọi hàm để tính toán lợi nhuận hoặc lỗ từ mỗi giao dịch và cộng vào tổng
        totalProfitOrLoss += calculateProfitOrLoss(numberOfShares, purchasePricePerShare, purchaseCommission,
                                                   salePricePerShare, saleCommission);
    }

    // Hiển thị tổng lợi nhuận hoặc tổng lỗ
    cout << "\nTotal profit or loss from all stock sales: $" << totalProfitOrLoss << endl;

    return 0;
}
