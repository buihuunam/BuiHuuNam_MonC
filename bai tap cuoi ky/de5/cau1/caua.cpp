#include<iostream>
using namespace std;

class A {
public:
    virtual void f( int x ) { 
        cout << x << " "; 
    }
};

class B: public A {
public:
    // Hàm f trong lớp B gọi lại chính nó với đối số tăng lên 1
    void f( int y ) { 
        f( y + 1 ); 
    }
};

// Hàm doSomething nhận đối tượng A và B, gọi phương thức f trên cả hai đối tượng
void doSomething( A a, B b ) { 
    a.f( 3 );   // In ra giá trị của a.f(3)
    b.f( 3 );   // Gọi đệ quy phương thức f trong lớp B, in ra dãy số tăng lên
}

int main() {
    B x, y;
    doSomething( x, y ); // Gọi hàm doSomething với đối tượng B x và y
    return 0;
}
