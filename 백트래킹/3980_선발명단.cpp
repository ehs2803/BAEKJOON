#include<iostream>
using namespace std;

int ability[11][11];
bool check_player[11];
int ans=0;

void init(){
	for(int i=0;i<12;i++){
		check_player[i]=false;
	}
	ans=0;
}	

void dfs(int depth, int sum){
	if(depth==11){
		if(sum>ans) ans=sum;
		return;
	}

	for(int i=0;i<11;i++){
		if(check_player[i]==false&& ability[i][depth]>0){
			check_player[i]=true;
			dfs(depth+1, sum+ability[i][depth]);
			check_player[i]=false;
		}	
	}
}

int main(){
	int t;
	cin>>t;
	
	while(t--){
		init();
		for(int i=0;i<11;i++){
			for(int j=0;j<11;j++){
				cin>>ability[i][j];
			}
		}
		
		dfs(0, 0);
		cout<<ans<<'\n';
	}
}
