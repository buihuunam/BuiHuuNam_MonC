#include <iostream>
using namespace std;

class Base {
public:
    // Hàm hủy ảo
    virtual ~Base() {
        cout << "Base destructor\n";
    }
};

class Derived : public Base {
public:
    // Hàm hủy ảo
    ~Derived() override {
        cout << "Derived destructor\n";
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Gọi hàm hủy của lớp dẫn xuất thông qua con trỏ của lớp cơ sở

    return 0;
}/*--       _
       .__(.)< (MEOW)
        \___)   
 ~~~~~~~~~~~~~~~~~~-->
<!-- sp:eh:tosmZ1NoLQ1+h/R+GkpuCA6EigEYDWPFGA7GmrhKyJhXdEUN/M/ITROiotFwGjGsMnBrSNR00XTZZr8xbsZCUZHdWZMyxqnyG6uotdXDEMG0M5qsKKfyxgObNVo= -->*/
