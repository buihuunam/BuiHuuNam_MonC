#include <math.h>
#include <stdio.h>

// Định nghĩa một lớp cơ sở Abstract Function
class Function {
public:
    // Hàm ảo để tính giá trị của hàm tại điểm x
    virtual double Value(double x) = 0;
    
    // Hàm ảo để tính đạo hàm của hàm tại điểm x
    virtual double Derive(double x) = 0;
};

// Lớp kế thừa từ lớp Function, biểu diễn hàm sin(x)
class Sin : public Function {
public:
    // Tính giá trị của hàm sin(x)
    double Value(double x) {
        return sin(x);
    }

    // Tính đạo hàm của hàm sin(x)
    double Derive(double x) {
        return cos(x);
    }
};

// Hàm tính đạo hàm của tích của hai hàm tại một điểm x
double DeriveProduct(Function* f, Function* g, double x) {
    if (f != NULL && g != NULL) {
        // Áp dụng quy tắc nhân đạo hàm
        return f->Derive(x) * g->Value(x) + f->Value(x) * g->Derive(x);
    }
    return 0;
}

// Hàm tính đạo hàm của tổng của hai hàm tại một điểm x
double DeriveSum(Function* f, Function* g, double x) {
    if (f != NULL && g != NULL) {
        // Áp dụng quy tắc cộng đạo hàm
        return f->Derive(x) + g->Derive(x);
    }
    return 0;
}

int main() {
    double x = 3.14 / 6; // PI/6

    // Tạo một đối tượng Sin
    Sin* s = new Sin();

    // Tính giá trị và đạo hàm của sin(x) tại điểm x
    double y = DeriveProduct(s, s, x);

    // In kết quả ra màn hình
    printf("sin(x) = %f; sin'(x) = %f\n", s->Value(x), s->Derive(x));
    printf("y = %f\n", y);

    // Giải phóng bộ nhớ
    delete s;

    return 0;
}
