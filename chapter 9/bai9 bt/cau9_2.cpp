#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;

// Hàm nhập điểm từ người dùng
void nhapDiem(int* diem, int soLuong);

// Hàm sắp xếp mảng điểm theo thứ tự tăng dần
void sapXepDiem(int* diem, int soLuong);

// Hàm tính điểm trung bình
double tinhDiemTrungBinh(int* diem, int soLuong);

// Hàm hiển thị mảng điểm và điểm trung bình
void hienThiKetQua(int* diem, int soLuong, double diemTrungBinh);

int main() {
    int soLuongDiem;

    // Nhập số lượng điểm kiểm tra từ người dùng
    cout << "Nhập số lượng điểm kiểm tra: ";
    cin >> soLuongDiem;

    // Kiểm tra nếu số lượng điểm là không hợp lệ
    while (soLuongDiem <= 0) {
        cout << "Số lượng điểm không hợp lệ. Vui lòng nhập lại: ";
        cin >> soLuongDiem;
    }

    // Cấp phát động mảng để lưu trữ các điểm
    int* diem = new int[soLuongDiem];

    // Nhập điểm từ người dùng
    nhapDiem(diem, soLuongDiem);

    // Sắp xếp mảng điểm
    sapXepDiem(diem, soLuongDiem);

    // Tính điểm trung bình
    double diemTrungBinh = tinhDiemTrungBinh(diem, soLuongDiem);

    // Hiển thị kết quả
    hienThiKetQua(diem, soLuongDiem, diemTrungBinh);

    // Giải phóng bộ nhớ động khi không cần thiết
    delete[] diem;

    return 0;
}

void nhapDiem(int* diem, int soLuong) {
    for (int i = 0; i < soLuong; ++i) {
        do {
            cout << "Nhập điểm kiểm tra #" << (i + 1) << ": ";
            cin >> diem[i];
        } while (diem[i] < 0);  // Input Validation: Không chấp nhận điểm âm
    }
}

void sapXepDiem(int* diem, int soLuong) {
    // Sử dụng hàm sort để sắp xếp mảng
    sort(diem, diem + soLuong);
}

double tinhDiemTrungBinh(int* diem, int soLuong) {
    int tongDiem = 0;
    for (int i = 0; i < soLuong; ++i) {
        tongDiem += diem[i];
    }

    // Ép kiểu sang double để tính trung bình
    return static_cast<double>(tongDiem) / soLuong;
}

void hienThiKetQua(int* diem, int soLuong, double diemTrungBinh) {
    cout << "\nDanh sách điểm kiểm tra đã sắp xếp:\n";
    for (int i = 0; i < soLuong; ++i) {
        cout << "Điểm kiểm tra #" << (i + 1) << ": " << diem[i] << endl;
    }

    cout << fixed << setprecision(2);  // Đặt số lẻ sau dấu phẩy là 2 chữ số
    cout << "\nĐiểm trung bình: " << diemTrungBinh << endl;
}
