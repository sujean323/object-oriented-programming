#include<iostream>
using namespace std;

int main(){
    int x, ans;
    while(cin >> x){
        for(int i=2; i<x; i++){
            for(int j=2; j<x; j++){
                if(i % j == 0 && i != j)
                    break;
                else  if(i == j)
                    ans = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}




