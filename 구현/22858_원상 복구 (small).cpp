#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	
	vector<int> s(n), d(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	
	vector<int> ans(n);
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			int temp_d = d[j];
			ans[temp_d-1]=s[j];
		}
		s=ans;
	}
	
	for(int i=0;i<n;i++){
		cout<<ans[i]<<' ';
	}
}
