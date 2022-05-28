#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin>>n;
	
	int m;
	cin>>m;
	
	// ���ε� ��ġ ��ġ ������������ �Է�  
	vector<int> location(m);
	for(int i=0;i<m;i++){
		cin>>location[i];	
	}
	
	int left=0;
	int right = 100000;
	while(left<=right){
		int mid=(left+right)/2;
		int flag=1; // ���ε� ���� ��ȿ ���� 
		if(mid<location[0]) flag=0;
		for(int i=0;i<m-1;i++){
			if(location[i+1]-location[i]>mid*2){
				flag=0;
				break;
			}
		}
		if(n-location[m-1]>mid) flag=0;
		
		if(flag) right=mid-1;
		else left=mid+1;
	}
	
	// �� ���  
	cout<<left;
} 
