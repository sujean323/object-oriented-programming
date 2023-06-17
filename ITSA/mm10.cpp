#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    float c, f;
    while(cin >> c){
        f = c*9/5+32;
        cout << fixed << setprecision(1) << f << endl;
    }

    return 0;
}

