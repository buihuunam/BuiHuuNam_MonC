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
    // Nhập dữ liệu từ người dùng
    int numberOfShares;
    double purchasePricePerShare, purchaseCommission, salePricePerShare, saleCommission;

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

    // Gọi hàm để tính toán lợi nhuận hoặc lỗ
    double profitOrLoss = calculateProfitOrLoss(numberOfShares, purchasePricePerShare, purchaseCommission,
                                                 salePricePerShare, saleCommission);

    // Hiển thị kết quả
    if (profitOrLoss > 0) {
        cout << "The sale resulted in a profit of: $" << profitOrLoss << endl;
    } else if (profitOrLoss < 0) {
        cout << "The sale resulted in a loss of: $" << -profitOrLoss << endl;
    } else {
        cout << "The sale resulted in neither profit nor loss." << endl;
    }

    return 0;
}
