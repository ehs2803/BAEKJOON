#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int cnt=0;
	
	while(true){
		int L,P,V;
		cin>>L>>P>>V; // �Է�  
		
		if(L==0 && P==0 && V==0) break; // ����  
		cnt++;
		
		int ans=0;
		int mod = V%P;
		int cycle = V/P;
		
		ans += cycle*L;
		if(mod>L) ans+=L; // ������ �Ⱓ�� L���� ũ�ٸ�  
		else ans += mod; 
		
		// �� ���  
		cout<<"Case "<<cnt<<": "<<ans<<'\n';
	}	
}
