#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

vector<int> v;

int main(){
	// 입력  
	cin>>n;
	
	// 입력  
	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		v.push_back(temp);
	}
	
	// 정렬  
	sort(v.begin(), v.end());
	
	int ans = (n-1)/2;
	
	// 답 출력  
	cout<<v[ans];
} 
