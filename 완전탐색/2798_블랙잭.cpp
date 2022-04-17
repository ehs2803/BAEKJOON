#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	
	// 입력  
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	
	int ans=0;
	// 모든 경우에 대해서 탐색  
	for(int i=0;i<n-2;i++){
		for(int j=i+1; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				if(v[i]+v[j]+v[k]<=m && (v[i]+v[j]+v[k])>ans){
					ans = v[i]+v[j]+v[k];
				}
			}
		}
	} 
	
	// 답 출력  
	cout<<ans;
}
