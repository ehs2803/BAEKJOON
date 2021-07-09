#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,k; cin>>n>>k;
	
	vector<long long> v(n);
	
	for(int i=0;i<n;i++) cin>>v[i];
	
	sort(v.begin(), v.end());
	
	for(int i=0;i<k;i++){
		long long one = v[0], two, twoIndex;
		two=v[1];
		twoIndex=1;
		/*
		for(int j=1;j<n;j++){
			if(v[j]!=one) {
				two=v[j];
				twoIndex=j;
				break;
			}
		}
		*/
		long long sum = one+two;
		v[0]=sum;
		v[twoIndex]=sum;
		sort(v.begin(), v.end());
	}
	
	long long ans = 0;
	for(int i=0;i<n;i++) ans+=v[i];
	
	cout<<ans;
}
