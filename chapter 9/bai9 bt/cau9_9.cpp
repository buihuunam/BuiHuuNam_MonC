#include <iostream>

using namespace std;

double findMedian(const int *array, int size) {
    if (size <= 0) {
        // Kích thước mảng không hợp lệ
        cerr << "Kích thước mảng không hợp lệ." << endl;
        return -1;
    }

    // Con trỏ trỏ đến giữa mảng
    const int *middle = array + size / 2;

    // Nếu số lượng phần tử là lẻ, trả về giá trị giữa
    if (size % 2 != 0) {
        return *middle;
    } else {
        // Nếu số lượng phần tử là chẵn, trả về trung bình của hai giá trị giữa
        const int *previousMiddle = middle - 1;
        return static_cast<double>(*middle + *previousMiddle) / 2.0;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    double median = findMedian(arr, size);

    if (median != -1) {
        cout << "Giá trị trung vị là: " << median << endl;
    }

    return 0;
}
