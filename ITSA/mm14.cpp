#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n, day, hour, mini, sec;
    while(cin >> n){
        day = n/86400;
        hour = (n%86400)/3600;
        mini = (n%3600)/60;
        sec = n%60;
        cout << day << " days" << endl;
        cout << hour << " hours" << endl;
        cout << mini << " minutes" << endl;
        cout << sec << " seconds" << endl;
    }


    return 0;
}


