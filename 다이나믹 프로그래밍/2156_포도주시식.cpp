#include<iostream>
using namespace std;

int dp[10001];
int graph[10001];

int main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>graph[i];
	}	
	
	dp[1]=graph[1];
	dp[2]=graph[1]+graph[2];
	//dp[3]=max(graph[1]+graph[3], graph[2]+graph[3]);
	for(int i=3;i<=n;i++){
		dp[i]=max(graph[i]+dp[i-2], graph[i]+graph[i-1]+dp[i-3]);
		dp[i]=max(dp[i], dp[i-1]);
	}
	
	cout<<dp[n];
} 
