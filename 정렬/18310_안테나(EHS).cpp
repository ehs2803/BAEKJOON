#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

vector<int> v;

int main(){
	// �Է�  
	cin>>n;
	
	// �Է�  
	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		v.push_back(temp);
	}
	
	// ����  
	sort(v.begin(), v.end());
	
	int ans = (n-1)/2;
	
	// �� ���  
	cout<<v[ans];
} 
