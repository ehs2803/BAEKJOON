#include<iostream>
#include<vector>
using namespace std;

int n,s;
vector<int> v;
int cnt=0;

void dfs(int index, int sum){
	if(index==n) return;
	
	if(sum+v[index]==s) cnt++;
	
	dfs(index+1, sum);
	
	dfs(index+1, sum+v[index]);
}

int main(){
	cin>>n>>s;

	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}

	dfs(0,0);
	
	cout<<cnt;
}
