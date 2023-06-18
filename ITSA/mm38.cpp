#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        if((a+b>c) && (b+c>a) && (a+c>b)) cout << "fit" << endl;
        else cout << "unfit" << endl;
    }
    return 0;
}







