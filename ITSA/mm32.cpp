#include<iostream>
using namespace std;

int main(){
    int x;
    while(cin >> x){
        int a = x/100;
        int b = x/10%10;
        int c = x%10;
        int armstrong = a*a*a + b*b*b + c*c*c;
        if(armstrong==x)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}




