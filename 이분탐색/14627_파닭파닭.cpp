#include<iostream>
#include<vector>
using namespace std;

int main(){
	int s,c; // s:파, c:파닭의수  
	cin>>s>>c;
	
	vector<long long> paLength(s);
	long long sum=0;
	for(int i=0;i<s;i++){
		cin>>paLength[i];
		sum+=paLength[i];
	}
	
	long long left=1;
	long long right=1000000000; 
	long long maxPa=0;
	while(left<=right){
		long long mid=(left+right)/2;
		long long cnt=0;
		for(int i=0;i<paLength.size();i++){
			cnt+=paLength[i]/mid;
		}
		if(cnt>=c) {
			maxPa = mid;
			left=mid+1;
		}
		else right=mid-1;
	}
	
	long long ans=0;
	for(int i=0;i<paLength.size();i++){
		ans+=paLength[i]%maxPa;
	}
	ans=sum-maxPa*c;
	// 답 출력  
	cout<<ans;
}
