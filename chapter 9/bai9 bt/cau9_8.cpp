#include <iostream>

using namespace std;

int findMode(int *array, int size) {
    if (size <= 0) {
        // Kích thước mảng không hợp lệ
        return -1;
    }

    // Khởi tạo biến để lưu giá trị mode và tần suất của nó
    int mode = -1;
    int maxFrequency = 0;

    // Duyệt qua mảng để tìm giá trị mode
    for (int *current = array; current < array + size; ++current) {
        // Bỏ qua các phần tử đã được xử lý
        if (*current == -1) {
            continue;
        }

        // Đếm tần suất của phần tử hiện tại
        int currentFrequency = 1;
        for (int *compare = current + 1; compare < array + size; ++compare) {
            if (*compare == *current) {
                ++currentFrequency;
                // Đánh dấu phần tử lặp lại đã được xử lý
                *compare = -1;
            }
        }

        // Cập nhật giá trị mode nếu phần tử hiện tại có tần suất cao hơn
        if (currentFrequency > maxFrequency) {
            maxFrequency = currentFrequency;
            mode = *current;
        }
    }

    return maxFrequency > 1 ? mode : -1;  // Trả về mode nếu nó tồn tại, ngược lại trả về -1
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int mode = findMode(arr, size);

    if (mode != -1) {
        cout << "Giá trị mode là: " << mode << endl;
    } else {
        cout << "Mảng không có mode." << endl;
    }

    return 0;
}
