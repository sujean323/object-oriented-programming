#include<iostream>
#include<bitset>
using namespace std;

int main(){
    int x;
    while(cin >> x){
        bitset<8> bs(x);
        cout << bs << endl;
    }
    return 0;
}

