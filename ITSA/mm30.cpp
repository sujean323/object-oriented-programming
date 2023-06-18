#include<iostream>
using namespace std;

int main(){
    int x;
    while(cin >> x){
        int flag=1;
        for(int i=2; i<x; i++){
            if(x%i==0){
                flag=0;
                break;
            }
            else continue;
        }
        if(flag==1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}




