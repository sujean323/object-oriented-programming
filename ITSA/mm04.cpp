#include<iostream>
using namespace std;

int main(){
    int a, b, ans, q, r;
    while(cin >> a >> b){
        cout << a << "+" << b << "="  << a+b << endl;
        cout << a << "*" << b << "="  << a*b << endl;
        cout << a << "-" << b << "="  << a-b << endl;
        r = a%b;
        if(r>=0) cout << a << "/" << b << "="  << a/b << "..." << r << endl;
        else{
            q = a/b;
            if(q<0) q--;
            else q++;
            r = a-b*q;
            cout << a << "/" << b << "="  << q << "..." << r << endl;
        }
    }
    return 0;
}


