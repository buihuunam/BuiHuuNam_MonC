#include <math.h>
#include <stdio.h>

class Function {
public:
    virtual double Value(double x) = 0;
    virtual double Derive(double x) = 0;
};

class Sin : public Function {
public:
    double Value(double x) {
        return sin(x);
    }

    double Derive(double x) {
        return cos(x);
    }
};

double DeriveProduct(Function* f, Function* g, double x) {
    if (f != NULL && g != NULL) {
        return f->Derive(x) * g->Value(x) + f->Value(x) * g->Derive(x);
    }
    return 0;
}

double DeriveQuotient(Function* f, Function* g, double x) {
    if (f != NULL && g != NULL) {
        double numerator = f->Derive(x) * g->Value(x) - f->Value(x) * g->Derive(x);
        double denominator = pow(g->Value(x), 2);
        if (denominator != 0) {
            return numerator / denominator;
        }
    }
    return 0;
}

double DeriveComposition(Function* f, Function* g, double x) {
    if (f != NULL && g != NULL) {
        return f->Derive(g->Value(x)) * g->Derive(x);
    }
    return 0;
}

int main() {
    double x = 3.14 / 6; // PI/6
    Sin* s = new Sin();

    double y_product = DeriveProduct(s, s, x);
    double y_quotient = DeriveQuotient(s, s, x);
    double y_composition = DeriveComposition(s, s, x);

    printf("sin(x) = %f; sin'(x) = %f\n", s->Value(x), s->Derive(x));
    printf("Derivative of product: y_product = %f\n", y_product);
    printf("Derivative of quotient: y_quotient = %f\n", y_quotient);
    printf("Derivative of composition: y_composition = %f\n", y_composition);

    delete s;
    return 0;
}
