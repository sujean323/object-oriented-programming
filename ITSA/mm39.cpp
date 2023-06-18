#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        if((a+b>c) && (b+c>a) && (a+c>b)){
            if((a*a+b*b==c*c) || (b*b+c*c==a*a) || (a*a+c*c==b*b)){
                cout << "Right Triangle" << endl;
            }
            else if((a*a+b*b<c*c) || (b*b+c*c<a*a) || (a*a+c*c<b*b)){
                cout << "Obtuse Triangle" << endl;
            }
            else if((a*a+b*b>c*c) || (b*b+c*c>a*a) || (a*a+c*c>b*b)){
                cout << "Acute Triangle" << endl;
            }
        }
        else{
            cout << "Not Triangle" << endl;
        }
    }
    return 0;
}
