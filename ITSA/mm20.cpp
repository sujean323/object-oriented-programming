#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int x;
    while(cin >> x){
        cout << hex << uppercase << x << endl;
    }
    return 0;
}

