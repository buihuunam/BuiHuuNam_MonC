#include <iostream>
using namespace std;
int main(){
    int s1, s2, x1, x2, y1, y2;
    cout << "press length of first of rectangle: ";
    cin >> x1;
    cout << "press width of first of rectangle: ";
    cin >> y1;
    cout << "press length of second of rectangle: ";
    cin >> x2;
    cout << "press width of second of rectangle: ";
    cin >> y2;
    s1 = x1 * y1;
    s2 = x2 * y2;
    if (s1 > s2){
        cout << "dien tich hinh thu 1 lon hon dien tich hinh thu 2";
    }
    else if(s1 < s2)
    {
        cout << "dien tich hinh thu 1 be hon dien tich hinh thu 2";
        }
    else{
        cout << "dien tich hinh thu 1 bang dien tich hinh thu 2";
    }
    return 0;
}