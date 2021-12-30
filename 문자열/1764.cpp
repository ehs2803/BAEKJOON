#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> v(n),result;
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());
    
    for(int i=0;i<m;i++) {
        string temp; cin>>temp;
        if(binary_search(v.begin(), v.end(),temp)){
            result.push_back(temp);
        }
    }
    
    sort(result.begin(), result.end());
    
    cout<<result.size()<<'\n';
    for(int i=0;i<result.size();i++) cout<<result[i]<<'\n';
}