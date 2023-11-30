#include<iostream>
using namespace std;
int main(){
    //khai bao bien
    long int s;
    int n;
    cout << "nhap n: ";
    cin >> n;
    //lap vong lap de tinh tong tu 1 den n
    for (int i = 1; i < n; i++){
        s += i;
    }
    cout << s << endl;
    return 0;
}