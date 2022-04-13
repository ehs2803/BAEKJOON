#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n; cin>>n;
	vector<pair<int, int> > v(n);
	
	for(int i=0; i<n; i++){
		cin>>v[i].first>>v[i].second;
	}
	
	vector<int> ans;
	for(int i=0;i<n;i++){
		int k=1;
		for(int j=0;j<n;j++){
			if(i!=j){
				if(v[i].first<v[j].first && v[i].second<v[j].second) k++;
			}
		}
		ans.push_back(k);
	}
	
	for(int i=0;i<n;i++) cout<<ans[i]<<' ';
}
