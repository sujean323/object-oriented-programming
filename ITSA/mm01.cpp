#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double upper, lower, height, ans;
    while(cin >> upper >> lower >> height){
        ans = (upper+lower)*height/2;
        cout << "Trapezoid area:" << fixed << setprecision(1) << ans << endl;
    }
    return 0;
}
