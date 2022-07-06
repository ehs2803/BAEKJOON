#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main(){
	int n;
	cin>>n;
	
	vector<pair<int,int>> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	
	sort(arr.begin(), arr.end());
	
	priority_queue<int, vector<int>, greater<int>> q;
	int ans=0;
	
	q.push(arr[0].second);
	ans++;
	for(int i=1;i<n;i++){
		while (!q.empty() && q.top() <= arr[i].first){
			q.pop();
		}	
		q.push(arr[i].second);
		ans = max(ans, (int)q.size());
	}
	
	cout<<ans;
}
