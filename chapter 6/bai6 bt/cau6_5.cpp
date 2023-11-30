#include <iostream>
#include <cmath> // Thư viện cho hàm pow
using namespace std;

const double g = 9.8; // Hằng số trọng lực

// Hàm tính khoảng cách rơi của đối tượng trong thời gian t
double fallingDistance(int t) {
    return 0.5 * g * pow(t, 2);
}

int main() {
    // Hiển thị tiêu đề
    cout << "Thoi gian (s)\tKhoang cach roi (m)\n";
    cout << "----------------------------------\n";

    // Gọi hàm và hiển thị kết quả cho từng giá trị thời gian từ 1 đến 10 giây
    for (int time = 1; time <= 10; ++time) {
        double distance = fallingDistance(time);
        cout << time << "\t\t" << distance << endl;
    }

    return 0;
}
