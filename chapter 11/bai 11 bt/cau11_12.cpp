#include <iostream>
#include <string>

using namespace std;

// Định nghĩa cấu trúc cho dữ liệu sinh viên
struct Student {
    string name;
    int idNum;
    int numTests;
    double* tests; // Con trỏ đến mảng điểm số kiểm tra
    double average;
    char grade;
};

// Hàm để nhập thông tin cho một sinh viên
void nhapThongTinSinhVien(Student& sv) {
    cout << "Nhập thông tin sinh viên:" << endl;

    cout << "Tên sinh viên: ";
    getline(cin, sv.name);

    cout << "ID sinh viên: ";
    cin >> sv.idNum;

    do {
        cout << "Số bài kiểm tra: ";
        cin >> sv.numTests;
        if (sv.numTests <= 0) {
            cout << "Vui lòng nhập một số dương cho số bài kiểm tra." << endl;
        }
    } while (sv.numTests <= 0);

    // Cấp phát động mảng cho bài kiểm tra
    sv.tests = new double[sv.numTests];

    cout << "Nhập điểm cho từng bài kiểm tra:" << endl;
    for (int i = 0; i < sv.numTests; ++i) {
        do {
            cout << "Bài kiểm tra #" << (i + 1) << ": ";
            cin >> sv.tests[i];
            if (sv.tests[i] < 0) {
                cout << "Vui lòng không nhập số âm cho điểm kiểm tra." << endl;
            }
        } while (sv.tests[i] < 0);
    }

    // Đặt giá trị mặc định cho average và grade
    sv.average = 0.0;
    sv.grade = ' ';
}

// Hàm để tính điểm trung bình và xếp loại
void tinhDiemTrungBinh(Student& sv) {
    // Tính điểm trung bình
    double total = 0.0;
    for (int i = 0; i < sv.numTests; ++i) {
        total += sv.tests[i];
    }
    sv.average = total / sv.numTests;

    // Xác định xếp loại dựa trên bảng xếp loại
    if (sv.average >= 91) {
        sv.grade = 'A';
    } else if (sv.average >= 81) {
        sv.grade = 'B';
    } else if (sv.average >= 71) {
        sv.grade = 'C';
    } else if (sv.average >= 61) {
        sv.grade = 'D';
    } else {
        sv.grade = 'F';
    }
}

// Hàm để hiển thị thông tin của một sinh viên
void hienThiThongTinSinhVien(const Student& sv) {
    cout << "\nThông tin sinh viên:" << endl;
    cout << "Tên sinh viên: " << sv.name << endl;
    cout << "ID sinh viên: " << sv.idNum << endl;
    cout << "Số bài kiểm tra: " << sv.numTests << endl;
    cout << "Điểm trung bình: " << sv.average << endl;
    cout << "Xếp loại: " << sv.grade << endl;
}

int main() {
    int soSinhVien;
    
    cout << "Nhập số lượng sinh viên: ";
    cin >> soSinhVien;
    cin.ignore(); // Đọc dấu xuống dòng còn lại

    // Cấp phát động mảng cho danh sách sinh viên
    Student* danhSachSinhVien = new Student[soSinhVien];

    // Nhập thông tin cho từng sinh viên
    for (int i = 0; i < soSinhVien; ++i) {
        nhapThongTinSinhVien(danhSachSinhVien[i]);
        tinhDiemTrungBinh(danhSachSinhVien[i]);
    }

    // Hiển thị thông tin của từng sinh viên
    for (int i = 0; i < soSinhVien; ++i) {
        hienThiThongTinSinhVien(danhSachSinhVien[i]);
    }

    // Giải phóng bộ nhớ động
    for (int i = 0; i < soSinhVien; ++i) {
        delete[] danhSachSinhVien[i].tests;
    }
    delete[] danhSachSinhVien;

    return 0;
}
