#include<iostream>
#include<vector>
using namespace std;

int main(){
	// 시간초과 문제 해결 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;
	cin>>n>>m;
	
	vector<int> a(n);
	vector<int> b(m);
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	
	int index_a=0, index_b=0;
	vector<int> c;
	
	while(index_a<n && index_b<m){
		if(a[index_a]<=b[index_b]){
			c.push_back(a[index_a++]);
		}
		else{
			c.push_back(b[index_b++]);
		}
	}
	
	while(index_a<n){
		c.push_back(a[index_a++]);
	}
	
	while(index_b<m){
		c.push_back(b[index_b++]);
	}

	for(int i=0;i<c.size();i++){
		cout<<c[i]<<' ';
	}
}
