#include <math.h>
#include <stdio.h>

class Function {
public:
    virtual double Value(double x) = 0;
    virtual double Derive(double x) = 0;
};

class Sin : public Function {
private:
    static Sin* instance;  // Biến tĩnh để lưu trữ đối tượng duy nhất

public:
    static Sin* GetInstance() {
        if (!instance) {
            instance = new Sin();
        }
        return instance;
    }

    double Value(double x) {
        return sin(x);
    }

    double Derive(double x) {
        return cos(x);
    }
};

// Khởi tạo đối tượng tĩnh
Sin* Sin::instance = nullptr;

double DeriveProduct(Function* f, Function* g, double x) {
    if (f != nullptr && g != nullptr) {
        return f->Derive(x) * g->Value(x) + f->Value(x) * g->Derive(x);
    }
    return 0;
}

double DeriveSum(Function* f, Function* g, double x) {
    if (f != nullptr && g != nullptr) {
        return f->Derive(x) + g->Derive(x);
    }
    return 0;
}

int main() {
    double x = 3.14 / 6; // PI/6
    Sin* s = Sin::GetInstance();  // Sử dụng GetInstance() để lấy đối tượng duy nhất

    double y = DeriveProduct(s, s, x);
    printf("sin(x) = %f; sin'(x) = %f\n", s->Value(x), s->Derive(x));
    printf("y = %f\n", y);

    // Không cần delete vì đối tượng được quản lý bởi GetInstance()
    return 0;
}
