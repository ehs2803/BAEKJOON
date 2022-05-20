#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool isPossible(vector<long long> & lans, long long len, int targetCnt){
	int cnt=0;
	for(int i=0;i<lans.size();i++){
		int temp = lans[i]/len;
		cnt+=temp;
	}	
	
	if(cnt>=targetCnt) return true;
	else return false;
}

int main(){
	int k,n;
	cin>>k>>n;
	
	vector<long long> lans;
	// 입력  
	long long max=0;
	for(int i=0;i<k;i++) {
		int temp;
		cin>>temp;
		if(temp>max) max=temp;
		lans.push_back(temp);
	}
	
	long long left=1;
	long long right = max; // pow(2,31)-1; 가능  
	long long mid, ans;
	while(left<=right){
		mid = (left+right)/2;
		if(isPossible(lans, mid, n)){
			ans = mid;
			left = mid+1;
		}
		else{
			right = mid-1;
		}

	}
	// 답 출력  
	cout<<ans;
}
