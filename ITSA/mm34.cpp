#include<iostream>
#include<vector>
using namespace std;

int main(){
    int x;
    while(cin >> x){
        vector<int> ans;
        for(int i=1; i<=x; i++){
            if(x%i==0){
                ans.push_back(i);
            }
            else continue;
        }
        for(int i=0; i<ans.size(); i++){
            if(i != ans.size()-1)
                cout << ans[i] << " ";
            else
                cout << ans[i] << endl;
        }
        ans.clear();
    }
    return 0;
}





