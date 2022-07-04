#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	
	vector<int> tell(n);
	for(int i=0;i<n;i++){
		cin>>tell[i];
	}
	
	if(k==n) cout<<0;
	else{
		sort(tell.begin(), tell.end());
		vector<int> cost(n-1);
		for(int i=0;i<n-1;i++){
			cost[i] = tell[i+1]-tell[i];
		}
		sort(cost.begin(), cost.end());
		
		long long ans=0;
		for (int i = 0; i < n - k; i++){
			ans += cost[i];
		}
		cout << ans;	
	}
}
