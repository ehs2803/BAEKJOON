#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int ans=1;
	for(int i=1;i<n;i++){
		int sum=i;
		int start=i;
		while(sum<n){
			start++;
			sum+=start;
		}
		if(sum==n){
			ans++;
		}
	}
	
	cout<<ans;
}
