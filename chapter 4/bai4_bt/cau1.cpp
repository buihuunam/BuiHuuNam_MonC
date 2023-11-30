#include <iostream>
using namespace std;
int main(){
    int a, b;
    cout << "nhap a=";
    cin >> a;
    cout << "nhap b=";
    cin >> b;
    if(a > b && b < a){
        cout << "a lon hon b";
    }
    else
    {
        cout << "a nho hon b";
        }
    return 0;
}