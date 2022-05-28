#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
int binarySearch(const vector<int> &v, int target){
	int left=0;
	int right=v.size()-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(v[mid]==target) return mid;
		else if(v[mid]<target) left = mid+1;
		else if(v[mid]>target) right= mid-1;
	}
	return -1;
}
*/
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	// 입력  
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	
	// 오름차순 정렬  
	sort(v.begin(), v.end());
	
	for(int i=0;i<m;i++){
		int target;
		cin>>target;
		int index = lower_bound(v.begin(), v.end(), target) - v.begin();
		if (index!=n&&v[index]==target) {
			cout << index << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
} 
