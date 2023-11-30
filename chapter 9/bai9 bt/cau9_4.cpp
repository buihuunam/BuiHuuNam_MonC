#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

// Hàm nhập tên và điểm từ người dùng
void nhapDiemVaTen(string* ten, int* diem, int soLuong);

// Hàm sắp xếp mảng tên và điểm theo thứ tự tăng dần theo điểm
void sapXepDiemVaTen(string* ten, int* diem, int soLuong);

// Hàm tính điểm trung bình
double tinhDiemTrungBinh(int* diem, int soLuong);

// Hàm hiển thị mảng tên và điểm, cùng với điểm trung bình
void hienThiKetQua(string* ten, int* diem, int soLuong, double diemTrungBinh);

int main() {
    int soLuongDiem;

    // Nhập số lượng điểm kiểm tra từ người dùng
    cout << "Nhập số lượng sinh viên: ";
    cin >> soLuongDiem;

    // Kiểm tra nếu số lượng điểm là không hợp lệ
    while (soLuongDiem <= 0) {
        cout << "Số lượng sinh viên không hợp lệ. Vui lòng nhập lại: ";
        cin >> soLuongDiem;
    }

    // Cấp phát động mảng để lưu trữ tên và điểm của sinh viên
    string* tenSinhVien = new string[soLuongDiem];
    int* diemSinhVien = new int[soLuongDiem];

    // Nhập tên và điểm từ người dùng
    nhapDiemVaTen(tenSinhVien, diemSinhVien, soLuongDiem);

    // Sắp xếp mảng tên và điểm
    sapXepDiemVaTen(tenSinhVien, diemSinhVien, soLuongDiem);

    // Tính điểm trung bình
    double diemTrungBinh = tinhDiemTrungBinh(diemSinhVien, soLuongDiem);

    // Hiển thị kết quả
    hienThiKetQua(tenSinhVien, diemSinhVien, soLuongDiem, diemTrungBinh);

    // Giải phóng bộ nhớ động khi không cần thiết
    delete[] tenSinhVien;
    delete[] diemSinhVien;

    return 0;
}

void nhapDiemVaTen(string* ten, int* diem, int soLuong) {
    for (int i = 0; i < soLuong; ++i) {
        cout << "Nhập tên sinh viên #" << (i + 1) << ": ";
        cin.ignore(); // Xóa bộ đệm bàn phím trước khi nhập chuỗi
        getline(cin, ten[i]);

        do {
            cout << "Nhập điểm kiểm tra #" << (i + 1) << ": ";
            cin >> diem[i];
        } while (diem[i] < 0);  // Input Validation: Không chấp nhận điểm âm
    }
}

void sapXepDiemVaTen(string* ten, int* diem, int soLuong) {
    // Sử dụng hàm sort để sắp xếp mảng dựa trên điểm số
    // Sử dụng lambda function để so sánh cặp tên-điểm
    sort(begin(ten), end(ten),
         [diem](const string& a, const string& b) {
             return diem[&a - &ten[0]] < diem[&b - &ten[0]];
         });

    // Sắp xếp mảng điểm theo thứ tự tăng dần
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

void hienThiKetQua(string* ten, int* diem, int soLuong, double diemTrungBinh) {
    cout << "\nDanh sách điểm kiểm tra đã sắp xếp:\n";
    for (int i = 0; i < soLuong; ++i) {
        cout << "Sinh viên: " << ten[i] << ", Điểm kiểm tra: " << diem[i] << endl;
    }

    cout << fixed << setprecision(2);  // Đặt số lẻ sau dấu phẩy là 2 chữ số
    cout << "\nĐiểm trung bình: " << diemTrungBinh << endl;
}
