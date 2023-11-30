#include <iostream>

using namespace std;

// Hàm cấp phát động một mảng số nguyên
int* capPhatMang(int soLuongPhanTu) {
    // Sử dụng toán tử new để cấp phát bộ nhớ động
    int* mang = new int[soLuongPhanTu];

    // Kiểm tra xem việc cấp phát có thành công hay không
    if (mang == nullptr) {
        cout << "Lỗi: Không thể cấp phát bộ nhớ.\n";
        // Có thể thực hiện các xử lý khác ở đây nếu cần thiết
    }

    return mang;  // Trả về con trỏ đến mảng đã cấp phát
}

int main() {
    int soLuong;
    cout << "Nhập số lượng phần tử của mảng: ";
    cin >> soLuong;

    // Gọi hàm để cấp phát mảng động
    int* mangSoNguyen = capPhatMang(soLuong);

    // Sử dụng mảng theo cách mong muốn

    // Giải phóng bộ nhớ khi không cần thiết nữa
    delete[] mangSoNguyen;

    return 0;
}
