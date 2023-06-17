#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int d;
    while(cin >> d){
        double ans = d*1.6;
        cout << fixed << setprecision(1) << ans << endl;
    }

    return 0;
}


