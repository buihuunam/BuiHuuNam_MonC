#include <iostream>
#include <math.h>
using namespace std;
int main (){
    double weight, height, BMI;
    cout << "press your weight: ";
    cin >> weight;
    cout << "press your height: ";
    cin >> height;
    weight = weight * 2.2;
    height = height * 0.4;
    BMI = weight * 703 / pow(height, 2.0);
    if(BMI > 18.5 && BMI < 25){
        cout << "well health";
    }
    else if(BMI < 18.5){
        cout << "underweight";
    }
    else{
        cout << "overweight";
    }
    return 0;
}