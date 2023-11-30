#include <iostream>
#include <iomanip>
using namespace std;

// Hàm tính toán số lượng sơn cần thiết
double calculatePaintGallons(double squareFeet) {
    const double GALLON_PER_SQUARE_FEET = 110.0;
    return squareFeet / GALLON_PER_SQUARE_FEET;
}

// Hàm tính toán số giờ lao động cần thiết
double calculateLaborHours(double squareFeet) {
    const double HOURS_PER_SQUARE_FEET = 8.0;
    return squareFeet / HOURS_PER_SQUARE_FEET;
}

// Hàm tính toán chi phí lao động
double calculateLaborCost(double laborHours, double laborRate) {
    return laborHours * laborRate;
}

// Hàm chính
int main() {
    // Nhập dữ liệu từ người dùng
    int numberOfRooms;
    double paintPrice, squareFeet;

    // Nhập số lượng phòng
    cout << "Enter the number of rooms to be painted: ";
    cin >> numberOfRooms;

    // Kiểm tra đầu vào
    if (numberOfRooms < 1) {
        cerr << "Invalid input. Number of rooms must be at least 1." << endl;
        return 1; // Thoát chương trình với mã lỗi
    }

    // Nhập giá sơn
    cout << "Enter the price of paint per gallon: $";
    cin >> paintPrice;

    // Kiểm tra đầu vào
    if (paintPrice < 10.0) {
        cerr << "Invalid input. Price of paint per gallon must be at least $10.00." << endl;
        return 1; // Thoát chương trình với mã lỗi
    }

    // Khởi tạo biến tổng chi phí
    double totalCost = 0.0;

    // Nhập thông tin cho từng phòng và tính toán chi phí
    for (int room = 1; room <= numberOfRooms; ++room) {
        cout << "\nEnter the square feet of wall space in room " << room << ": ";
        cin >> squareFeet;

        // Kiểm tra đầu vào
        if (squareFeet < 0) {
            cerr << "Invalid input. Square footage of wall space cannot be negative." << endl;
            return 1; // Thoát chương trình với mã lỗi
        }

        // Tính toán và hiển thị thông tin cho từng phòng
        double gallons = calculatePaintGallons(squareFeet);
        double hours = calculateLaborHours(squareFeet);
        double laborCost = calculateLaborCost(hours, 25.0);
        double paintCost = gallons * paintPrice;

        cout << fixed << setprecision(2);
        cout << "Gallons of paint required: " << gallons << endl;
        cout << "Hours of labor required: " << hours << endl;
        cout << "Cost of the paint: $" << paintCost << endl;
        cout << "Labor charges: $" << laborCost << endl;

        // Tổng chi phí
        totalCost += paintCost + laborCost;
    }

    // Hiển thị tổng chi phí cho toàn bộ công việc
    cout << "\nTotal cost of the paint job: $" << totalCost << endl;

    return 0;
}
