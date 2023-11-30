#include<iostream>
using namespace std;

class A {
public:
    A() { 
        a = new int[3]; 
        for ( int i = 0; i < 3; i++ ) {
            a[i] = i + 1; 
        }
    }

    ~A() { 
        delete[] a; 
    }

private:
    int *a;
};

// Hàm init nhận một tham chiếu đối tượng A và khởi tạo một đối tượng A mới, sau đó gán giá trị của đối tượng mới này cho đối tượng đầu vào.
void init( A &a ) {
    A b;  // Tạo một đối tượng A mới
    a = b; // Gán giá trị của đối tượng mới cho đối tượng đầu vào
}

int main() {
    A obj; // Tạo một đối tượng A tại main
    init( obj ); // Gọi hàm init với đối tượng A tại main
    return 0;
}
