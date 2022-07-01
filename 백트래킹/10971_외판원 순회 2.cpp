#include<iostream>
using namespace std;

int n;
int map[10][10];
bool check[10];
int ans=1e9;

void initCheck(){
	for(int i=0;i<n;i++){
		check[i]=false;
	}	
}

void TSP(int depth, int start, int arrival, int cost){
	if(depth==n){
		if(map[start][arrival]==0) return;
		cost+=map[start][arrival];
		if(cost<ans) ans=cost;
		return;
	}
	
	for(int i=0;i<n;i++){
		if(check[i]) continue;
		if(start==i) continue;
		if(map[start][i]==0) continue;
		check[i]=true;
		int newCost=cost+map[start][i];
		TSP(depth+1, i, arrival, newCost);
		check[i]=false;
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		initCheck();
		check[i]=true;
		TSP(1, i, i, 0);
	}
	
	cout<<ans;
}
