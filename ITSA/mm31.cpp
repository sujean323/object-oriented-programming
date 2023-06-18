#include<iostream>
#include<vector>
using namespace std;

int main(){
    int x;
    vector<int> ans;
    while(cin >> x){
        for(int i=1; i<=x; i++){
            if((i%2==0) && (i%3==0) && (i%12!=0)){
                ans.push_back(i);
            }
        }
        int sum = 0;
        for(int i=0; i<ans.size(); i++){
            sum += ans[i];
        }
        cout << sum << endl;
        ans.clear();
    }
    return 0;
}




