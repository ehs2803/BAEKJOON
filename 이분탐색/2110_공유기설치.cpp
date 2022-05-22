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
		
		// 간격을 mid로 했을 때 공유기 설치개수 구하기   
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
			left = mid+1; // 간격을 더 늘려보면서 최댓값 구해보기  
		}
		else{ // 공유기가 c개보다 더 적게 사용되었다면  
			right = mid-1; // 더많은 공유기 설치하기 위해 간격 줄이기  
		}
	}
	
	// 답 출력  
	cout<<ans;
	
}
