#include <iostream>

using namespace std;

int main() {
    // Định nghĩa và khởi tạo giá của năm mặt hàng
    double giaMonHang1 = 15.95;
    double giaMonHang2 = 24.95;
    double giaMonHang3 = 6.95;
    double giaMonHang4 = 12.95;
    double giaMonHang5 = 3.95;

    // Tính tổng giá trị của đơn hàng
    double tongGiaTriDonHang = giaMonHang1 + giaMonHang2 + giaMonHang3 + giaMonHang4 + giaMonHang5;

    // Tính số thuế bán hàng (7% của tổng giá trị đơn hàng)
    double thueBanHang = 0.07 * tongGiaTriDonHang;

    // Tính tổng cộng (tổng giá trị đơn hàng + số thuế bán hàng)
    double tongCong = tongGiaTriDonHang + thueBanHang;

    // Hiển thị kết quả
    cout << "Gia cua mon hang 1: $" << giaMonHang1 << endl;
    cout << "Gia cua mon hang 2: $" << giaMonHang2 << endl;
    cout << "Gia cua mon hang 3: $" << giaMonHang3 << endl;
    cout << "Gia cua mon hang 4: $" << giaMonHang4 << endl;
    cout << "Gia cua mon hang 5: $" << giaMonHang5 << endl;

    cout << "\nTong gia tri don hang: $" << tongGiaTriDonHang << endl;
    cout << "So thue ban hang (7%): $" << thueBanHang << endl;
    cout << "Tong cong: $" << tongCong << endl;

    return 0;
}
