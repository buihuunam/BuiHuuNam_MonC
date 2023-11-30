#include <iostream>

using namespace std;

int main() {
    // Khai báo và khởi tạo biến
    double gasTankCapacity = 20.0;   // Sức chứa của bình xăng (gallon)
    double townMilesPerGallon = 23.5;  // Mức tiêu thụ nhiên liệu trong thành phố (MPG)
    double highwayMilesPerGallon = 28.9;  // Mức tiêu thụ nhiên liệu trên đường cao tốc (MPG)

    // Tính khoảng cách khi lái trong thành phố
    double townDistance = gasTankCapacity * townMilesPerGallon;

    // Tính khoảng cách khi lái trên đường cao tốc
    double highwayDistance = gasTankCapacity * highwayMilesPerGallon;

    // Hiển thị kết quả
    cout << "Xe co the di duoc " << townDistance << " dặm khi lái trong thành phố." << endl;
    cout << "Xe co the di duoc " << highwayDistance << " dặm khi lái tren duong cao toc." << endl;

    return 0;
}
