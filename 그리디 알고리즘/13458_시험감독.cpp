#include<iostream>
#include<vector> 
using namespace std;

int main(){
	int n; cin>>n;
	vector<int> people(n);
	for(int i=0;i<n;i++) cin>>people[i];
	
	int B,C; 
	cin>>B>>C;
	
	long long ans=n; // n개 고사실에 총감독감 배치  
	for(int i=0;i<people.size();i++){
		people[i]-=B; // 총강독관 1명 배치에 따른 빼기  
		if(people[i]<=0) continue; // 남은 감독대상 학생수가 0명이하라면 부감독관 필요 x 
		else{
			int mod = people[i]%C; 
			ans+=people[i]/C; // 부감독관 배치  
			if(mod!=0) ans+=1; // 나머지가 있다면 부감독관 1명 추가로 배치  
		}
	}
	
	// 답 출력  
	cout<<ans;
}
