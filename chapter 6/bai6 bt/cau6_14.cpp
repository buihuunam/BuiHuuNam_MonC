#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Hàm để nhập thông tin đặt hàng và kiểm tra tính hợp lệ
void getOrderInfo(int &numOrdered, int &numInStock, bool &specialCharges, double &specialChargesPerSpool) {
    do {
        cout << "Nhap so luong cuon dong dat hang: ";
        cin >> numOrdered;

        // Kiểm tra tính hợp lệ của số lượng đặt hàng
        if (cin.fail() || numOrdered < 1) {
            cin.clear(); // Xóa trạng thái lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Loại bỏ dữ liệu nhập không hợp lệ
            cout << "So luong dat hang khong hop le. Vui long nhap lai.\n";
        } else {
            break; // Nếu số lượng đặt hàng hợp lệ, thoát khỏi vòng lặp
        }
    } while (true);

    do {
        cout << "Nhap so luong cuon dong co san: ";
        cin >> numInStock;

        // Kiểm tra tính hợp lệ của số lượng đang có
        if (cin.fail() || numInStock < 0) {
            cin.clear(); // Xóa trạng thái lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Loại bỏ dữ liệu nhập không hợp lệ
            cout << "So luong co san khong hop le. Vui long nhap lai.\n";
        } else {
            break; // Nếu số lượng có sẵn hợp lệ, thoát khỏi vòng lặp
        }
    } while (true);

    cout << "Co phi van chuyen va xu ly dac biet khong? (1: Co, 0: Khong): ";
    cin >> specialCharges;

    if (specialCharges) {
        do {
            cout << "Nhap phi van chuyen va xu ly dac biet (khong am): ";
            cin >> specialChargesPerSpool;

            // Kiểm tra tính hợp lệ của phí
            if (cin.fail() || specialChargesPerSpool < 0) {
                cin.clear(); // Xóa trạng thái lỗi
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Loại bỏ dữ liệu nhập không hợp lệ
                cout << "Phi van chuyen va xu ly dac biet khong hop le. Vui long nhap lai.\n";
            } else {
                break; // Nếu phí hợp lệ, thoát khỏi vòng lặp
            }
        } while (true);
    }
}

// Hàm để hiển thị thông tin đơn hàng
void displayOrderStatus(int numOrdered, int numInStock, bool specialCharges, double specialChargesPerSpool) {
    int numReadyToShip = min(numOrdered, numInStock);
    int numBackordered = max(numOrdered - numInStock, 0);

    double subtotal = numReadyToShip * 100.0;
    double shippingAndHandling = specialCharges ? specialChargesPerSpool * numReadyToShip : 10.0 * numReadyToShip;
    double totalOrder = subtotal + shippingAndHandling;

    cout << "\nThong tin don hang:\n";
    cout << "So luong cuon dong san co the giao: " << numReadyToShip << endl;
    cout << "So luong cuon dong dat hang bi huy: " << numBackordered << endl;
    cout << "Tong tien cuon dong san co the giao (100 USD/cuon): $" << fixed << setprecision(2) << subtotal << endl;
    cout << "Tong phi van chuyen va xu ly cuon dong san co the giao: $" << fixed << setprecision(2) << shippingAndHandling << endl;
    cout << "Tong tien don hang co the giao: $" << fixed << setprecision(2) << totalOrder << endl;
}

int main() {
    int numOrdered, numInStock;
    bool specialCharges;
    double specialChargesPerSpool;

    // Nhập thông tin đơn hàng
    getOrderInfo(numOrdered, numInStock, specialCharges, specialChargesPerSpool);

    // Hiển thị thông tin đơn hàng
    displayOrderStatus(numOrdered, numInStock, specialCharges, specialChargesPerSpool);

    return 0;
}
