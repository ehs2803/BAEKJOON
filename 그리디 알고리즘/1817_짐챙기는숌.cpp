#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	
	if (n == 0) {
		cout << 0 << "\n";
		return 0;
	}
	vector<int> weight(n);
	for(int i=0;i<n;i++){
		cin>>weight[i];
	}
	
	int ans=0;
	int temp=0;
	for(int i=0;i<n;i++){
		if(temp+weight[i]<=m){
			temp+=weight[i];
		}
		else{
			ans++;
			temp=weight[i];
		}
	}
	
	cout<<ans+1;
}
