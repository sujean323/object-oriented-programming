#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int i;
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(0);
    while(cin >> i){
        if(i>31)
            cout << "Value of more than 31" << endl;
        else
            cout << pow(2,i) << endl;
    }

    return 0;
}

