#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	deque<int> d;
	int n, m; 
	cin>>n>>m;
	
	vector<int> v(m);
	
	for(int i=1;i<=n;i++) d.push_back(i);
	for(int i=0;i<m;i++){
		int num; cin>>num;
		v.push_back(num);
	}
	for(int i=0;i<m;i++){
		while(true){
			
		}
	}
}
