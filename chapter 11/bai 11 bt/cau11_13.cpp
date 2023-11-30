#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Định nghĩa cấu trúc cho dữ liệu đồ uống
struct Drink {
    string name;
    double cost;
    int numInMachine;
};

// Hàm để hiển thị menu đồ uống
void hienThiMenu(const Drink danhSachDoUong[], int soLuong) {
    cout << "\nMenu đồ uống:" << endl;
    cout << setw(15) << left << "Tên đồ uống" << setw(10) << left << "Giá" << "Số lượng" << endl;

    for (int i = 0; i < soLuong; ++i) {
        cout << setw(15) << left << danhSachDoUong[i].name << setw(10) << left << danhSachDoUong[i].cost
             << danhSachDoUong[i].numInMachine << endl;
    }
}

// Hàm để thực hiện mua đồ uống
void muaDoUong(Drink& doUong) {
    double tienNhap;
    
    cout << "Nhập số tiền (không quá $1.00): $";
    cin >> tienNhap;

    // Kiểm tra hợp lệ cho số tiền
    while (tienNhap < 0 || tienNhap > 1.00) {
        cout << "Số tiền không hợp lệ. Vui lòng nhập lại: $";
        cin >> tienNhap;
    }

    // Kiểm tra xem có đủ đồ uống không
    if (doUong.numInMachine > 0) {
        // Kiểm tra xem có đủ tiền không
        if (tienNhap >= doUong.cost) {
            // Tính và hiển thị số tiền thừa và giảm số lượng đồ uống
            double tienThua = tienNhap - doUong.cost;
            cout << "Số tiền thừa: $" << tienThua << endl;
            doUong.numInMachine--;
        } else {
            cout << "Số tiền không đủ để mua đồ uống này." << endl;
        }
    } else {
        cout << "Đồ uống " << doUong.name << " đã hết." << endl;
    }
}

int main() {
    const int SOLUONGDOUONG = 5;
    Drink danhSachDoUong[SOLUONGDOUONG] = {
        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };

    char luaChon;
    double tongDoanhThu = 0.0;

    do {
        hienThiMenu(danhSachDoUong, SOLUONGDOUONG);

        cout << "\n(Q)uit or choose a (D)rink: ";
        cin >> luaChon;

        if (luaChon == 'D' || luaChon == 'd') {
            int luaChonDoUong;
            cout << "Chọn một đồ uống (1-" << SOLUONGDOUONG << "): ";
            cin >> luaChonDoUong;

            // Kiểm tra lựa chọn đồ uống hợp lệ
            if (luaChonDoUong >= 1 && luaChonDoUong <= SOLUONGDOUONG) {
                muaDoUong(danhSachDoUong[luaChonDoUong - 1]);
                tongDoanhThu += danhSachDoUong[luaChonDoUong - 1].cost;
            } else {
                cout << "Lựa chọn không hợp lệ." << endl;
            }
        } else if (luaChon != 'Q' && luaChon != 'q') {
            cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
        }

    } while (luaChon != 'Q' && luaChon != 'q');

    cout << "Tổng doanh thu: $" << fixed << setprecision(2) << tongDoanhThu << endl;

    return 0;
}
