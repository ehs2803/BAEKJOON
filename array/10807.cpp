#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n; cin>>n;
	vector<int> v(n);
	
	for(int i=0;i<n;i++) cin>>v[i];
	
	int num; cin>>num;
	int ans = 0;
	for(int i=0;i<n;i++){
		if(v[i]==num) ans++; 
	}
	cout<<ans;
}
