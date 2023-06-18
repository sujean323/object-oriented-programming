#include<iostream>
#include<vector>
using namespace std;

int main(){
    int x;
    vector<int> ans;
    while(cin >> x){
        for(int i=1; i<=x; i++){
            if((i%5==0) && (i%7==0)){
                ans.push_back(i);
            }
        }
        for(int i=0; i<ans.size(); i++){
            if(i != ans.size()-1){
                cout << ans[i] << " ";
            }
            else{
                cout << ans[i];
            }
        }
        cout << endl;
    }
    return 0;
}




