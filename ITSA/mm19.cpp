#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int t;
    double ans;
    while(cin >> t){
        if(t>=1500){
            ans = t*0.9*0.79;
        }
        else if(t>800 && t<1500){
            ans = t*0.9*0.9;
        }
        else if(t<=800){
            ans = t*0.9;
        }
        cout << fixed << setprecision(1) << ans << endl;
    }

    return 0;
}
