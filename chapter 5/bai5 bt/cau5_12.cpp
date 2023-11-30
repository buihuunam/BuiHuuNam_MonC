#include<iostream>
using namespace std;
int main(){
    //khai bao bien do C  va F
    int C;
    float F;
    //xuat ra bang quy doi tu do C sang do F
    cout << "C" << "\t" << "F" << endl;
    for(C = 0; C <= 20; C++){
        F = 9/5 * (float)C + 32.0;
        cout << C << "\t" << F << endl;
    }
    return 0;
}