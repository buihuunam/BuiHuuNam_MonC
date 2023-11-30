#include <iostream>
#include <iomanip>

using namespace std;

// Hàm tính toán giá bán lẻ
double calculateRetail(double wholesaleCost, double markupPercentage) {
    // Kiểm tra giá trị đầu vào
    if (wholesaleCost < 0 || markupPercentage < 0) {
        cout << "Loi: Khong chap nhan gia tri am." << endl;
        return -1; // Giá trị trả về -1 để chỉ ra lỗi
    }

    // Tính toán giá bán lẻ
    double retailPrice = wholesaleCost * (1 + markupPercentage / 100.0);

    return retailPrice;
}

int main() {
    // Nhập chi phí buôn bán và tỷ lệ phần trăm markup
    double wholesaleCost, markupPercentage;

    cout << "Nhap chi phi buon ban cua san pham: $";
    cin >> wholesaleCost;

    // Kiểm tra giá trị đầu vào
    if (wholesaleCost < 0) {
        cout << "Loi: Chi phi buon ban khong the la gia tri am." << endl;
        return 1; // Kết thúc chương trình với mã lỗi 1
    }

    cout << "Nhap ty le phan tram markup: ";
    cin >> markupPercentage;

    // Kiểm tra giá trị đầu vào
    if (markupPercentage < 0) {
        cout << "Loi: Ty le phan tram markup khong the la gia tri am." << endl;
        return 1; // Kết thúc chương trình với mã lỗi 1
    }

    // Gọi hàm để tính toán giá bán lẻ
    double retailPrice = calculateRetail(wholesaleCost, markupPercentage);

    // Kiểm tra xem hàm tính toán giá bán lẻ có lỗi không
    if (retailPrice != -1) {
        // Hiển thị giá bán lẻ
        cout << fixed << setprecision(2); // Đặt số lẻ sau dấu thập phân là 2 chữ số
        cout << "Gia ban le cua san pham la: $" << retailPrice << endl;
    }

    return 0;
}
