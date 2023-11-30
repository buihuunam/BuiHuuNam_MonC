#include <iostream>

using namespace std;

int* doubleArraySize(const int *array, int size) {
    // Tạo một mảng mới có kích thước gấp đôi
    int *doubledArray = new int[2 * size];

    // Sao chép nội dung của mảng đầu vào vào mảng mới
    for (int i = 0; i < size; ++i) {
        doubledArray[i] = array[i];
    }

    // Khởi tạo các phần tử chưa sử dụng của mảng mới bằng 0
    for (int i = size; i < 2 * size; ++i) {
        doubledArray[i] = 0;
    }

    return doubledArray;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Gọi hàm để tạo một mảng mới có kích thước gấp đôi
    int *doubledArr = doubleArraySize(arr, size);

    // In ra mảng gốc
    cout << "Mang goc: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // In ra mảng mới có kích thước gấp đôi
    cout << "Mang moi co kich thuoc gap doi: ";
    for (int i = 0; i < 2 * size; ++i) {
        cout << doubledArr[i] << " ";
    }
    cout << endl;

    // Nhớ giải phóng bộ nhớ đã cấp phát cho mảng mới
    delete[] doubledArr;

    return 0;
}
