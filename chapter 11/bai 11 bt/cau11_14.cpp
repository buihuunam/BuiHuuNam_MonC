#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Định nghĩa hằng số cho số lượng tối đa của mỗi bin
const int MAX_PARTS_PER_BIN = 30;
const int NUM_BINS = 10;

// Định nghĩa cấu trúc cho dữ liệu bin
struct InventoryBin {
    string partDescription;
    int numParts;
};

// Hàm để hiển thị menu và danh sách bin
void hienThiDanhSachBin(const InventoryBin danhSachBin[], int soLuong) {
    cout << "\nDanh sách bin:" << endl;
    cout << setw(20) << left << "Mô tả phần" << "Số lượng" << endl;

    for (int i = 0; i < soLuong; ++i) {
        cout << setw(20) << left << danhSachBin[i].partDescription << danhSachBin[i].numParts << endl;
    }
}

// Hàm để thêm số lượng phần vào một bin cụ thể
void themPhanVaoBin(InventoryBin& bin, int soLuongThem) {
    // Kiểm tra số lượng hợp lệ
    if (soLuongThem > 0 && bin.numParts + soLuongThem <= MAX_PARTS_PER_BIN) {
        bin.numParts += soLuongThem;
        cout << "Đã thêm " << soLuongThem << " phần vào bin." << endl;
    } else {
        cout << "Không thể thêm số lượng phần này vào bin." << endl;
    }
}

// Hàm để giảm số lượng phần từ một bin cụ thể
void giamPhanTuBin(InventoryBin& bin, int soLuongGiam) {
    // Kiểm tra số lượng hợp lệ
    if (soLuongGiam > 0 && bin.numParts - soLuongGiam >= 0) {
        bin.numParts -= soLuongGiam;
        cout << "Đã giảm " << soLuongGiam << " phần từ bin." << endl;
    } else {
        cout << "Không thể giảm số lượng phần này từ bin." << endl;
    }
}

int main() {
    // Khởi tạo danh sách bin
    InventoryBin danhSachBin[NUM_BINS] = {
        {"Valve", 10},
        {"Bearing", 5},
        {"Bushing", 15},
        {"Coupling", 21},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear Housing", 5},
        {"Vacuum Gripper", 25},
        {"Cable", 18},
        {"Rod", 12}
    };

    char luaChon;
    int luaChonBin, soLuong;

    do {
        hienThiDanhSachBin(danhSachBin, NUM_BINS);

        cout << "\n(Q)uit or choose a (B)in: ";
        cin >> luaChon;

        if (luaChon == 'B' || luaChon == 'b') {
            cout << "Chọn một bin (1-" << NUM_BINS << "): ";
            cin >> luaChonBin;

            // Kiểm tra lựa chọn bin hợp lệ
            if (luaChonBin >= 1 && luaChonBin <= NUM_BINS) {
                cout << "(A)dd or (R)emove parts: ";
                cin >> luaChon;

                cout << "Nhập số lượng phần: ";
                cin >> soLuong;

                if (luaChon == 'A' || luaChon == 'a') {
                    themPhanVaoBin(danhSachBin[luaChonBin - 1], soLuong);
                } else if (luaChon == 'R' || luaChon == 'r') {
                    giamPhanTuBin(danhSachBin[luaChonBin - 1], soLuong);
                } else {
                    cout << "Lựa chọn không hợp lệ." << endl;
                }
            } else {
                cout << "Lựa chọn không hợp lệ." << endl;
            }
        } else if (luaChon != 'Q' && luaChon != 'q') {
            cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
        }

    } while (luaChon != 'Q' && luaChon != 'q');

    return 0;
}
