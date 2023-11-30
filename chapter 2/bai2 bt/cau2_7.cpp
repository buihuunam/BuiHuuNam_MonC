#include <iostream>

using namespace std;

int main() {
    // Định nghĩa và khởi tạo biến
    double hieuSuatTangHienTai = 1.5; // milimet mỗi năm
    int nam5 = 5;
    int nam7 = 7;
    int nam10 = 10;

    // Tính sự tăng dự kiến sau 5 năm
    double tangSau5Nam = hieuSuatTangHienTai * nam5;

    // Tính sự tăng dự kiến sau 7 năm
    double tangSau7Nam = hieuSuatTangHienTai * nam7;

    // Tính sự tăng dự kiến sau 10 năm
    double tangSau10Nam = hieuSuatTangHienTai * nam10;

    // Hiển thị kết quả
    cout << "Sau 5 năm, mực nước biển sẽ tăng thêm " << tangSau5Nam << " milimet." << endl;
    cout << "Sau 7 năm, mực nước biển sẽ tăng thêm " << tangSau7Nam << " milimet." << endl;
    cout << "Sau 10 năm, mực nước biển sẽ tăng thêm " << tangSau10Nam << " milimet." << endl;

    return 0;
}
