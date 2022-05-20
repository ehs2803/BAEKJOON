#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> & requestBudget, int high, long long totalBudget){
	long long totalCost=0;
	for(int i=0;i<requestBudget.size();i++){
		if(requestBudget[i]>=high) totalCost+=high;
		else totalCost+=requestBudget[i];
	}	
	if(totalCost>totalBudget) return false;
	else return true;
}

int main(){
	int n;
	cin>>n;
	
	// 입력  
	int max = 0;
	vector<int> requestBudget;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		if(temp>max) max=temp;
		requestBudget.push_back(temp);
	}
	
	long long m;
	cin>>m;
	
	int left=1;
	int right=max;
	int mid, ans;
	while(left<=right){
		mid = (left+right)/2;
		if(isPossible(requestBudget, mid, m)){
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
