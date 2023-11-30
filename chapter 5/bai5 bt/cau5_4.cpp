#include<iostream>
using namespace std;
int main(){
    //lay mang co ten la MINUTE
    const int MINUTE[] = {5, 10, 15, 20, 25, 30};
    float energy;
    //xuat ra bang luong nang luong tieu hao trong i phut
    for (int i = 0 ; i <= 5; i++)
    {
        int time = MINUTE[i];
        cout << "luong nang luong tieu hao trong " << time << " phut la: "<< endl;
        energy = 3.6 * time;
        cout << energy << endl;
    }
    return 0;
}