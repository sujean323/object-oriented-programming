#include <iostream>
using namespace std;

int main(){
    int x,y,temp,i;
    cin >> x >> y;
    if(y>x){
        temp=x;
        x=y;
        y=temp;
    }
    for(i=y; i>=1; i--){
        if(x%i==0 and y%i==0){
            cout << i << endl;
            break;
        }
    }

    return 0;
}
