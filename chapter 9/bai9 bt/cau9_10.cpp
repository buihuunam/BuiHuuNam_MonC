#include <iostream>

using namespace std;

int* reverseArray(const int *array, int size) {
    // Tạo một mảng mới để lưu bản sao với giá trị đảo ngược
    int *reversedArray = new int[size];

    // Sao chép giá trị từ mảng gốc và đảo ngược vào mảng mới
    for (int i = 0; i < size; ++i) {
        reversedArray[i] = array[size - 1 - i];
    }

    return reversedArray;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Gọi hàm để tạo một bản sao với giá trị đảo ngược
    int *reversedArr = reverseArray(arr, size);

    // In ra mảng gốc
    cout << "Mang goc: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // In ra mảng mới với giá trị đảo ngược
    cout << "Mang dao nguoc: ";
    for (int i = 0; i < size; ++i) {
        cout << reversedArr[i] << " ";
    }
    cout << endl;

    // Nhớ giải phóng bộ nhớ đã cấp phát cho mảng mới
    delete[] reversedArr;

    return 0;
}
