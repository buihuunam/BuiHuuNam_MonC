#include <iostream>
using namespace std;

// Hàm để nhập chiều dài của hình chữ nhật từ người dùng
double getLength() {
    double length;
    cout << "Nhap chieu dai cua hinh chu nhat: ";
    cin >> length;
    return length;
}

// Hàm để nhập chiều rộng của hình chữ nhật từ người dùng
double getWidth() {
    double width;
    cout << "Nhap chieu rong cua hinh chu nhat: ";
    cin >> width;
    return width;
}

// Hàm để tính diện tích của hình chữ nhật
double getArea(double length, double width) {
    return length * width;
}

// Hàm để hiển thị thông tin về hình chữ nhật
void displayData(double length, double width, double area) {
    cout << "Chieu dai hinh chu nhat la: " << length << endl;
    cout << "Chieu rong hinh chu nhat la: " << width << endl;
    cout << "Dien tich hinh chu nhat la: " << area << endl;
}

int main() {
    // Gọi các hàm để nhận thông tin và tính diện tích hình chữ nhật
    double length = getLength();
    double width = getWidth();
    double area = getArea(length, width);

    // Hiển thị thông tin về hình chữ nhật
    displayData(length, width, area);

    return 0;
}
