#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        int ans = pow(a+b, 2);
        cout << ans << endl;
    }

    return 0;
}

