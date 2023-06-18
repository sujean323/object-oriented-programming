#include<iostream>
using namespace std;

int main(){
    int x;
    while(cin >> x){
        int sum=(1+x)*x/2;
        for(int i=1; i<=x; i++){
            if(i != x)
                cout << i << " + ";
            else
                cout << i << " = " << sum << endl;
        }
    }
    return 0;
}

