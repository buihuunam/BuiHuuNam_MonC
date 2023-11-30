#include <iostream>
using namespace std;

// Hàm nạp chồng tính toán chi phí cho bệnh nhân nội trú
double calculateCharges(int days, double dailyRate, double medicationCharges, double serviceCharges) {
    // Kiểm tra giá trị không âm
    if (days < 0 || dailyRate < 0 || medicationCharges < 0 || serviceCharges < 0) {
        cerr << "Invalid input. Please enter non-negative values." << endl;
        return 0.0;
    }

    // Tính toán tổng chi phí cho bệnh nhân nội trú
    return days * dailyRate + medicationCharges + serviceCharges;
}

// Hàm nạp chồng tính toán chi phí cho bệnh nhân ngoại trú
double calculateCharges(double medicationCharges, double serviceCharges) {
    // Kiểm tra giá trị không âm
    if (medicationCharges < 0 || serviceCharges < 0) {
        cerr << "Invalid input. Please enter non-negative values." << endl;
        return 0.0;
    }

    // Tính toán tổng chi phí cho bệnh nhân ngoại trú
    return medicationCharges + serviceCharges;
}

int main() {
    char patientType;
    cout << "Enter 'I' for in-patient or 'O' for out-patient: ";
    cin >> patientType;

    // Biến để lưu tổng chi phí
    double totalCharges = 0.0;

    // Xử lý dựa trên loại bệnh nhân
    if (patientType == 'I' || patientType == 'i') {
        // Nhập dữ liệu cho bệnh nhân nội trú
        int days;
        double dailyRate, medicationCharges, serviceCharges;

        cout << "Enter the number of days spent in the hospital: ";
        cin >> days;
        cout << "Enter the daily rate: ";
        cin >> dailyRate;
        cout << "Enter hospital medication charges: ";
        cin >> medicationCharges;
        cout << "Enter charges for hospital services: ";
        cin >> serviceCharges;

        // Gọi hàm nạp chồng cho bệnh nhân nội trú
        totalCharges = calculateCharges(days, dailyRate, medicationCharges, serviceCharges);
    } else if (patientType == 'O' || patientType == 'o') {
        // Nhập dữ liệu cho bệnh nhân ngoại trú
        double medicationCharges, serviceCharges;

        cout << "Enter charges for hospital services: ";
        cin >> serviceCharges;
        cout << "Enter hospital medication charges: ";
        cin >> medicationCharges;

        // Gọi hàm nạp chồng cho bệnh nhân ngoại trú
        totalCharges = calculateCharges(medicationCharges, serviceCharges);
    } else {
        cerr << "Invalid input. Please enter 'I' or 'O'." << endl;
        return 1; // Thoát chương trình với mã lỗi
    }

    // Hiển thị tổng chi phí
    cout << "Total charges: $" << totalCharges << endl;

    return 0;
}
