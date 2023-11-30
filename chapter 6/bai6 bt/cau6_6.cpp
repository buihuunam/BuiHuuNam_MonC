#include <iostream>
using namespace std;

// Hàm để tính năng lượng động dựa trên công thức đã cho
double kineticEnergy(double mass, double velocity) {
    return 0.5 * mass * velocity * velocity;
}

int main() {
    // Nhập giá trị khối lượng và vận tốc từ người dùng
    double mass, velocity;

    cout << "Nhap khối lượng của đối tượng (kg): ";
    cin >> mass;

    cout << "Nhap vận tốc của đối tượng (m/s): ";
    cin >> velocity;

    // Gọi hàm để tính năng lượng động và hiển thị kết quả
    double energy = kineticEnergy(mass, velocity);
    cout << "Năng lượng động của đối tượng là: " << energy << " joules" << endl;

    return 0;
}
