#include<iostream>
using namespace std;

int main(){
    int x;
    while(cin >> x){
        int sum=0;
        for(int i=1; i<=x; i++){
            if(i%3==0) sum += i;
        }
        cout << sum << endl;
    }
    return 0;
}




