#include <iostream>

using namespace std;

int* addElement(const int *array, int size) {
    // Tạo một mảng mới có kích thước lớn hơn một phần tử
    int *newArray = new int[size + 1];

    // Thiết lập phần tử đầu tiên của mảng mới là 0
    newArray[0] = 0;

    // Sao chép các phần tử từ mảng đầu vào sang mảng mới
    for (int i = 0; i < size; ++i) {
        newArray[i + 1] = array[i];
    }

    return newArray;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Gọi hàm để tạo một mảng mới có kích thước lớn hơn một phần tử
    int *newArr = addElement(arr, size);

    // In ra mảng gốc
    cout << "Mang goc: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // In ra mảng mới có kích thước lớn hơn
    cout << "Mang moi co kich thuoc lon hon: ";
    for (int i = 0; i < size + 1; ++i) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    // Nhớ giải phóng bộ nhớ đã cấp phát cho mảng mới
    delete[] newArr;

    return 0;
}
