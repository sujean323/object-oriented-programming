#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int price, coin_10=0, coin_5=0, coin_1=0;
    while(cin >> price){
        coin_10 = price/10;
        coin_5 = price%10/5;
        coin_1 = price%10%5;

        cout << "NT10=" << coin_10 << endl;
        cout << "NT5=" << coin_5 << endl;
        cout << "NT1=" << coin_1 << endl;
    }


    return 0;
}

