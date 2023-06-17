#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int t;
    double pay, a, b, c;
    while(cin >> t >> pay){
        while(t>0){
            if(t>120){
                a = pay*1.66*(t-120);
                t = 120;
            }
            else if(t>60 && t<=120){
                b = pay*1.33*(t-60);
                t = 60;
            }
            else if(t<=60){
                c = pay*t;
                t = 0;
            }
        }
        cout << fixed << setprecision(1) << a+b+c << endl;
    }
    return 0;
}



