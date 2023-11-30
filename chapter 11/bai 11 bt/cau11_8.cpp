#include <iostream>
#include <string>

using namespace std;

struct CustomerAccount {
    string name;
    string address;
    string cityStateZIP;
    string phoneNumber;
    double accountBalance;
    string lastPaymentDate;
};

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

    do {
        cout << "Số dư tài khoản: $";
        cin >> khachHang.accountBalance;
        if (khachHang.accountBalance < 0) {
            cout << "Vui lòng không nhập số dư tài khoản âm." << endl;
        }
    } while (khachHang.accountBalance < 0);

    cin.ignore();
    cout << "Ngày thanh toán cuối cùng: ";
    getline(cin, khachHang.lastPaymentDate);
}

void hienThiThongTinKhachHang(const CustomerAccount& khachHang) {
    cout << "\nThông tin tài khoản khách hàng:" << endl;
    cout << "Tên khách hàng: " << khachHang.name << endl;
    cout << "Địa chỉ: " << khachHang.address << endl;
    cout << "Thành phố, Tiểu bang, và Mã ZIP: " << khachHang.cityStateZIP << endl;
    cout << "Số điện thoại: " << khachHang.phoneNumber << endl;
    cout << "Số dư tài khoản: $" << khachHang.accountBalance << endl;
    cout << "Ngày thanh toán cuối cùng: " << khachHang.lastPaymentDate << endl;
}

// Hàm tìm kiếm tài khoản theo tên
void timKiemTheoTen(const CustomerAccount danhSachKhachHang[], int soTaiKhoanKhachHang, const string& ten) {
    bool timThay = false;

    for (int i = 0; i < soTaiKhoanKhachHang; ++i) {
        // Nếu tên của khách hàng chứa phần của tên cần tìm
        if (danhSachKhachHang[i].name.find(ten) != string::npos) {
            hienThiThongTinKhachHang(danhSachKhachHang[i]);
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Không tìm thấy tài khoản khách hàng với tên chứa \"" << ten << "\"." << endl;
    }
}

int main() {
    const int SOTAIKHOANKHACHHANG = 10;
    CustomerAccount danhSachKhachHang[SOTAIKHOANKHACHHANG];

    int luaChon;
    int index;
    string tenTimKiem;

    do {
        cout << "\n** Menu **" << endl;
        cout << "1. Nhập thông tin tài khoản khách hàng" << endl;
        cout << "2. Hiển thị thông tin tất cả tài khoản khách hàng" << endl;
        cout << "3. Hiển thị thông tin một tài khoản khách hàng" << endl;
        cout << "4. Tìm kiếm tài khoản theo tên" << endl;
        cout << "5. Thoát" << endl;
        cout << "Chọn một lựa chọn (1-5): ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "Chọn số tài khoản (1-" << SOTAIKHOANKHACHHANG << "): ";
                cin >> index;
                cin.ignore();
                if (index >= 1 && index <= SOTAIKHOANKHACHHANG) {
                    nhapThongTinKhachHang(danhSachKhachHang[index - 1]);
                } else {
                    cout << "Số tài khoản không hợp lệ." << endl;
                }
                break;
            case 2:
                for (int i = 0; i < SOTAIKHOANKHACHHANG; ++i) {
                    hienThiThongTinKhachHang(danhSachKhachHang[i]);
                }
                break;
            case 3:
                cout << "Chọn số tài khoản (1-" << SOTAIKHOANKHACHHANG << "): ";
                cin >> index;
                if (index >= 1 && index <= SOTAIKHOANKHACHHANG) {
                    hienThiThongTinKhachHang(danhSachKhachHang[index - 1]);
                } else {
                    cout << "Số tài khoản không hợp lệ." << endl;
                }
                break;
            case 4:
                cout << "Nhập phần của tên cần tìm kiếm: ";
                cin.ignore(); // Đọc dấu xuống dòng còn lại
                getline(cin, tenTimKiem);
                timKiemTheoTen(danhSachKhachHang, SOTAIKHOANKHACHHANG, tenTimKiem);
                break;
            case 5:
                cout << "Kết thúc chương trình." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
        }
    } while (luaChon != 5);

    return 0;
}
