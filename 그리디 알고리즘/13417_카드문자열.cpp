#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;
        vector<char> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        
        string ans="";
        ans+=v[0];
        v.erase(v.begin());
        
        for(int i=0;i<v.size();i++){
            if(v[i]<ans[0]){
                ans = v[i] + ans;
            }
            else{
                ans+=v[i];
            }
        }
        
        cout<<ans<<'\n';
    }
}
