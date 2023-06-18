#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int x;
    while(cin >> x){
        double sum=0;
        for(int i=1; i<=x; i++){
            sum += pow(-1.0, (i+1)*1.0)*1/(2*i-1);
        }
        cout << fixed << setprecision(3) << sum << endl;
    }
    return 0;
}

