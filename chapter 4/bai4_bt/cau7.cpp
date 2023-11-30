#include <iostream>
using namespace std;

int main(){
    long long second;
    cout << "press second: ";
    cin >> second;
    if(second >= 86400){
        int day;
        day = second / 86400;
        cout << "number of days: " << day << endl;
        second %= 86400;
    }
    if(second >= 3600){
        int hour;
        hour = second / 3600;
        cout << "number of hour: " << hour << endl;
        second %= 3600;
    }
    if(second >= 60){
        int min;
        min = second / 60;
        cout << "number of minutes: " << min << endl;
        second %= 60;
    }
    cout << "number of second: " << second << endl;
    return 0;
}
