#include <iostream>

using namespace std;

int main() {
    // Khai báo và khởi tạo biến
    double gallonsOfGas = 15.0;   // Số gallon xăng trong bình
    double milesDriven = 375.0;   // Số dặm đã đi được

    // Tính mức tiêu thụ nhiên liệu trung bình (Miles Per Gallon - MPG)
    double mpg = milesDriven / gallonsOfGas;

    // Hiển thị kết quả
    cout << "Xe co the di duoc " << mpg << " dặm cho mỗi gallon xăng." << endl;

    return 0;
}
