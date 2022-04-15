#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int cnt=0;
	
	while(true){
		int L,P,V;
		cin>>L>>P>>V; // 입력  
		
		if(L==0 && P==0 && V==0) break; // 종료  
		cnt++;
		
		int ans=0;
		int mod = V%P;
		int cycle = V/P;
		
		ans += cycle*L;
		if(mod>L) ans+=L; // 나머지 기간이 L보다 크다면  
		else ans += mod; 
		
		// 답 출력  
		cout<<"Case "<<cnt<<": "<<ans<<'\n';
	}	
}
