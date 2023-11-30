#include<iostream>
using namespace std;
int main(){
    int i;
    float h;
    //hien muc nuoc dang sau 25 nam
    for(i = 1; i <= 25; i++){
        cout << "muc nuoc dang sau " << i << " nam la:" << endl;
        h = 1.5 * i;
        cout << h << endl;
    }
    return 0;
}