#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
	return a>b;
}

int main(){
	int n, coin; cin>>n>>coin;
	vector<int> v(n);
	
	for(int i=0;i<n;i++) cin>>v[i];
	
	sort(v.begin(), v.end(), cmp);
	
	int ans = 0;
	
	for(int i=0;i<n;i++){
		ans = ans + (coin/v[i]);
		coin = coin % v[i];
		if(coin==0) break;
	}
	
	cout<<ans;
}
