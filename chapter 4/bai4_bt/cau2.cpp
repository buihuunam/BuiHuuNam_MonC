#include <iostream>
using namespace std;
int main(){
    int a;
    //nhap gia tri
    cout << "nhap a= ";
    cin >> a;
    //neu so lon hon 10 hoac be hon 1 thi nhap lai
    if(a > 10 || a < 1)
    {
        cout << "press again: ";
        cin >> a;
    }
    //hien thi so la ma
    switch (a)
    {
    case 1:
        cout << "I";
        break;
    case 2:
        cout << "II";
        break;
    case 3:
        cout << "III";
        break;
    case 4:
        cout << "IV";
        break;
    case 5:
        cout << "V";
        break;
    case 6:
        cout << "VI";
        break;
    case 7:
        cout << "VII";
        break;
    case 8:
        cout << "VIII";
        break;
    case 9:
        cout << "IX";
        break;
    case 10:
        cout << "X";
        break;
    default:
        break;
    }
    return 0;
}