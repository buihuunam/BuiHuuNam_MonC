#include <iostream>
#include <string>

using namespace std;

// Định nghĩa cấu trúc cho dữ liệu tài khoản khách hàng
struct CustomerAccount {
    string name;           // Tên khách hàng
    string address;        // Địa chỉ
    string cityStateZIP;   // Thành phố, Tiểu bang, và Mã ZIP
    string phoneNumber;    // Số điện thoại
    double accountBalance; // Số dư tài khoản
    string lastPaymentDate; // Ngày thanh toán cuối cùng
};

// Hàm nhập thông tin cho một tài khoản khách hàng
void nhapThongTinKhachHang(CustomerAccount& khachHang) {
    cout << "Nhập thông tin tài khoản khách hàng:" << endl;

    cout << "Tên khách hàng: ";
    getline(cin, khachHang.name);

    cout << "Địa chỉ: ";
    getline(cin, khachHang.address);

    cout << "Thành phố, Tiểu bang, và Mã ZIP: ";
    getline(cin, khachHang.cityStateZIP);

    cout << "Số điện thoại: ";
    getline(cin, khachHang.phoneNumber);

    // Nhập và kiểm tra tính hợp lệ số dư tài khoản
    do {
        cout << "Số dư tài khoản: $";
        cin >> khachHang.accountBalance;
        if (khachHang.accountBalance < 0) {
            cout << "Vui lòng không nhập số dư tài khoản âm." << endl;
        }
    } while (khachHang.accountBalance < 0);

    cin.ignore(); // Đọc dấu xuống dòng còn lại
    cout << "Ngày thanh toán cuối cùng: ";
    getline(cin, khachHang.lastPaymentDate);
}

// Hàm hiển thị thông tin của một tài khoản khách hàng
void hienThiThongTinKhachHang(const CustomerAccount& khachHang) {
    cout << "\nThông tin tài khoản khách hàng:" << endl;
    cout << "Tên khách hàng: " << khachHang.name << endl;
    cout << "Địa chỉ: " << khachHang.address << endl;
    cout << "Thành phố, Tiểu bang, và Mã ZIP: " << khachHang.cityStateZIP << endl;
    cout << "Số điện thoại: " << khachHang.phoneNumber << endl;
    cout << "Số dư tài khoản: $" << khachHang.accountBalance << endl;
    cout << "Ngày thanh toán cuối cùng: " << khachHang.lastPaymentDate << endl;
}

int main() {
    const int SOTAIKHOANKHACHHANG = 10;
    CustomerAccount danhSachKhachHang[SOTAIKHOANKHACHHANG]; // Mảng 10 cấu trúc để lưu trữ thông tin tài khoản khách hàng

    int luaChon;
    int index;

    do {
        // Hiển thị menu
        cout << "\n** Menu **" << endl;
        cout << "1. Nhập thông tin tài khoản khách hàng" << endl;
        cout << "2. Hiển thị thông tin tất cả tài khoản khách hàng" << endl;
        cout << "3. Hiển thị thông tin một tài khoản khách hàng" << endl;
        cout << "4. Thoát" << endl;
        cout << "Chọn một lựa chọn (1-4): ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                // Nhập thông tin cho một tài khoản khách hàng
                cout << "Chọn số tài khoản (1-" << SOTAIKHOANKHACHHANG << "): ";
                cin >> index;
                cin.ignore(); // Đọc dấu xuống dòng còn lại
                if (index >= 1 && index <= SOTAIKHOANKHACHHANG) {
                    nhapThongTinKhachHang(danhSachKhachHang[index - 1]);
                } else {
                    cout << "Số tài khoản không hợp lệ." << endl;
                }
                break;
            case 2:
                // Hiển thị thông tin tất cả tài khoản khách hàng
                for (int i = 0; i < SOTAIKHOANKHACHHANG; ++i) {
                    hienThiThongTinKhachHang(danhSachKhachHang[i]);
                }
                break;
            case 3:
                // Hiển thị thông tin một tài khoản khách hàng
                cout << "Chọn số tài khoản (1-" << SOTAIKHOANKHACHHANG << "): ";
                cin >> index;
                if (index >= 1 && index <= SOTAIKHOANKHACHHANG) {
                    hienThiThongTinKhachHang(danhSachKhachHang[index - 1]);
                } else {
                    cout << "Số tài khoản không hợp lệ." << endl;
                }
                break;
            case 4:
                cout << "Kết thúc chương trình." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
        }
    } while (luaChon != 4);

    return 0;
}
