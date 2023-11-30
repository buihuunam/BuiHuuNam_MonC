#include <iostream>
using namespace std;
int main(){
    double mass, weight;
    cout << "press mass: ";
    cin >> mass;
    weight = mass * 9.8;
    if(weight > 1000){
        cout << "too heavy";
    }
    else if(weight < 10){
        cout << "too light";
    }
    else{
        cout << "normal";
    }
    return 0;
}