#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int preference[30][30];

int main(){
	int n,m;
	cin>>n>>m;
	// input 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>preference[i][j];
		}
	}
	
	// 조합 준비  
	int ans=0;
	vector<bool> temp(m, false);
	for(int i=0;i<3;i++){
		temp[i]=true;
	}
	// 조합. m개중에 3개 선택  
	do{
		int sum=0;
		vector<int> max_preference(n,0);
		for(int i=0;i<temp.size();i++){
			if(temp[i]==true){
				for(int j=0;j<n;j++){
					if(max_preference[j]<preference[j][i]) 
						max_preference[j]=preference[j][i];
				}
			}
		}
		for(int i=0;i<max_preference.size();i++){
			sum+=max_preference[i];
		}
		if(sum>ans) ans = sum;
		
	}while(prev_permutation(temp.begin(), temp.end()));
	// 답 출력  
	cout<<ans;
}
