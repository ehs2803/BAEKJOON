#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); //시간 초과 문제 해결  
	
	int n;
	cin>>n;
	
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	
	sort(v.begin(), v.end());
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int target;
		cin>>target;
		if(binary_search(v.begin(), v.end(), target)) cout<<"1"<<'\n';
		else cout<<"0"<<'\n';
	}
}
