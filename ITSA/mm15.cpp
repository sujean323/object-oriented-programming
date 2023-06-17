#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int x, y;
    while(cin >> x >> y){
        if(x>=0 && x<=100 && y>=0 && y<=100)
            cout << "inside" << endl;
        else cout << "outside" << endl;
    }


    return 0;
}


