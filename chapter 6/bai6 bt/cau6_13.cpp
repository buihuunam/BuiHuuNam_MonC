#include <iostream>
#include <limits> // Thư viện để sử dụng numeric_limits
using namespace std;

// Hàm để nhập số lượng nhân viên trong công ty
int getNumberOfEmployees() {
    int numEmployees;

    do {
        cout << "Nhap so luong nhan vien trong cong ty (lon hon 0): ";
        cin >> numEmployees;

        // Kiểm tra tính hợp lệ của số lượng nhân viên
        if (cin.fail() || numEmployees < 1) {
            cin.clear(); // Xóa trạng thái lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Loại bỏ dữ liệu nhập không hợp lệ
            cout << "So luong nhan vien khong hop le. Vui long nhap lai.\n";
        } else {
            break; // Nếu số lượng nhân viên hợp lệ, thoát khỏi vòng lặp
        }
    } while (true);

    return numEmployees;
}

// Hàm để nhập số ngày nghỉ của từng nhân viên và trả về tổng số ngày nghỉ
int getTotalDaysAbsent(int numEmployees) {
    int totalDaysAbsent = 0;

    for (int i = 1; i <= numEmployees; ++i) {
        int daysAbsent;

        do {
            cout << "Nhap so ngay nghi cua nhan vien " << i << " (khong am): ";
            cin >> daysAbsent;

            // Kiểm tra tính hợp lệ của số ngày nghỉ
            if (cin.fail() || daysAbsent < 0) {
                cin.clear(); // Xóa trạng thái lỗi
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Loại bỏ dữ liệu nhập không hợp lệ
                cout << "So ngay nghi khong hop le. Vui long nhap lai.\n";
            } else {
                break; // Nếu số ngày nghỉ hợp lệ, thoát khỏi vòng lặp
            }
        } while (true);

        totalDaysAbsent += daysAbsent;
    }

    return totalDaysAbsent;
}

// Hàm để tính và trả về số ngày nghỉ trung bình
double calculateAverageDaysAbsent(int numEmployees, int totalDaysAbsent) {
    return static_cast<double>(totalDaysAbsent) / numEmployees;
}

int main() {
    // Nhập số lượng nhân viên trong công ty
    int numEmployees = getNumberOfEmployees();

    // Nhập số ngày nghỉ của từng nhân viên và tính tổng số ngày nghỉ
    int totalDaysAbsent = getTotalDaysAbsent(numEmployees);

    // Tính và hiển thị số ngày nghỉ trung bình
    double averageDaysAbsent = calculateAverageDaysAbsent(numEmployees, totalDaysAbsent);
    cout << "So ngay nghi trung binh cua nhan vien la: " << averageDaysAbsent << endl;

    return 0;
}
