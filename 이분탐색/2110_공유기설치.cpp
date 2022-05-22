#include<iostream>
#include<algorithm>
using namespace std;

int homeLocation[200000];

int main(){
	int n,c;
	cin>>n>>c;
	
	for(int i=0;i<n;i++){
		cin>>homeLocation[i];
	}	
	
	sort(homeLocation, homeLocation+n);
	
	int ans=0;
	int left=1;
	int right=homeLocation[n-1]-homeLocation[0];
	while(left<=right){
		int mid = (left+right)/2;
		
		// ������ mid�� ���� �� ������ ��ġ���� ���ϱ�   
		int cnt=1;
		int installHouse=homeLocation[0];
		for(int i=1;i<n;i++){
			if(homeLocation[i]-installHouse>=mid){
				installHouse=homeLocation[i];
				cnt++;
			}
		}

		if(cnt>=c){
			ans = max(ans,mid);
			left = mid+1; // ������ �� �÷����鼭 �ִ� ���غ���  
		}
		else{ // �����Ⱑ c������ �� ���� ���Ǿ��ٸ�  
			right = mid-1; // ������ ������ ��ġ�ϱ� ���� ���� ���̱�  
		}
	}
	
	// �� ���  
	cout<<ans;
	
}
