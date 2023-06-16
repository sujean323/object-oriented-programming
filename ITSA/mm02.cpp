#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double buttom, height, ans;
    while(cin >> buttom >> height){
        ans = buttom*height/2;
        cout << fixed << setprecision(1) << ans << endl;
    }
    return 0;
}
