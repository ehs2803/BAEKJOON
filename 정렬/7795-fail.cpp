#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
	return a>b;
}

int main(){
	int t; cin>>t;
	
	while(t--){
		int n,m; cin>>n>>m;
		vector<int> a(n);
		vector<int> b(m);
		
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<m;i++) cin>>b[i];
		
		sort(b.begin(), b.end(), cmp);
		
		int an = 0;
		for(int i=0;i<a.size();i++){
			for(int j=0;j<b.size();j++){
				if(b[j]>=a[i]) break;
				an++;
			}
		}
		
		cout<<an<<'\n';
	}
}
