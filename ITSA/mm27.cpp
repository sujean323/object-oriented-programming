#include<iostream>
using namespace std;

int main(){
    int x, y;
    while(cin >> x >> y){
        int sum=0;
        if(x>y){
            int tmp;
            tmp = x;
            x = y;
            y = tmp;
        }
        for(int i=x; i<=y; i++){
            sum += i;
        }
        cout << sum << endl;
    }
    return 0;
}




