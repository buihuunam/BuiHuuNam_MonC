#include <iostream>
#include <fstream>
using namespace std;

// Hàm tính toán chi phí cho bệnh nhân nhập viện
double calculateTotalCharges(int days, double dailyRate, double medicationCharges, double servicesCharges) {
    return (days * dailyRate) + medicationCharges + servicesCharges;
}

// Hàm tính toán chi phí cho bệnh nhân ngoại trú
double calculateTotalCharges(double servicesCharges, double medicationCharges) {
    return servicesCharges + medicationCharges;
}

// Hàm chính
int main() {
    // Khai báo biến để lưu trữ thông tin bệnh nhân
    char patientType;
    int days;
    double dailyRate, medicationCharges, servicesCharges;

    // Mở file để ghi báo cáo
    ofstream outputFile("hospital_report.txt");

    // Kiểm tra xem file có mở thành công không
    if (!outputFile.is_open()) {
        cerr << "Unable to open the output file." << endl;
        return 1; // Thoát chương trình với mã lỗi
    }

    // Nhập loại bệnh nhân (i: nhập viện, o: ngoại trú)
    cout << "Enter the patient type (i for in-patient, o for out-patient): ";
    cin >> patientType;

    // Nhập thông tin tùy thuộc vào loại bệnh nhân
    if (patientType == 'i' || patientType == 'I') {
        // Bệnh nhân nhập viện
        cout << "Enter the number of days spent in the hospital: ";
        cin >> days;

        cout << "Enter the daily rate: $";
        cin >> dailyRate;

        cout << "Enter the hospital medication charges: $";
        cin >> medicationCharges;

        cout << "Enter the charges for hospital services: $";
        cin >> servicesCharges;

        // Tính toán tổng chi phí cho bệnh nhân nhập viện
        double totalCharges = calculateTotalCharges(days, dailyRate, medicationCharges, servicesCharges);

        // Hiển thị thông tin và ghi vào file
        cout << "\nTotal charges for in-patient: $" << totalCharges << endl;
        outputFile << "Patient Type: In-Patient\n";
        outputFile << "Days Spent in Hospital: " << days << "\n";
        outputFile << "Daily Rate: $" << dailyRate << "\n";
        outputFile << "Medication Charges: $" << medicationCharges << "\n";
        outputFile << "Charges for Hospital Services: $" << servicesCharges << "\n";
        outputFile << "Total Charges: $" << totalCharges << "\n";
    } else if (patientType == 'o' || patientType == 'O') {
        // Bệnh nhân ngoại trú
        cout << "Enter the charges for hospital services: $";
        cin >> servicesCharges;

        cout << "Enter the hospital medication charges: $";
        cin >> medicationCharges;

        // Tính toán tổng chi phí cho bệnh nhân ngoại trú
        double totalCharges = calculateTotalCharges(servicesCharges, medicationCharges);

        // Hiển thị thông tin và ghi vào file
        cout << "\nTotal charges for out-patient: $" << totalCharges << endl;
        outputFile << "Patient Type: Out-Patient\n";
        outputFile << "Charges for Hospital Services: $" << servicesCharges << "\n";
        outputFile << "Medication Charges: $" << medicationCharges << "\n";
        outputFile << "Total Charges: $" << totalCharges << "\n";
    } else {
        // Loại bệnh nhân không hợp lệ
        cerr << "Invalid patient type. Please enter 'i' for in-patient or 'o' for out-patient." << endl;
        return 1; // Thoát chương trình với mã lỗi
    }

    // Đóng file
    outputFile.close();

    return 0;
}
