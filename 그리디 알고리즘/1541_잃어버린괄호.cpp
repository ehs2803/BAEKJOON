#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string s; 
	cin>>s; // �Է�  
	
	int ans=0;
	bool isMinus=false; // ���� ����  
	int index=-1; // ���ڿ� ��ȸ �ε���  
	int sindex=0; // string->int �ٲٱ� ���� ������  
	int cnt=1; // string->int �ٲٱ� ���� ���ڿ� �ڸ���  
	while(true){
		index++; 
		if(s[index]=='-'){ // - �� ���  
			int num = stoi(s.substr(sindex,cnt)); // string->int 
			sindex = index+1; // sindex�� index+1�� �ʱ�ȭ  
			cnt=0; // cnt=0 �ʱ�ȭ  
			if(!isMinus){
				ans+=num; // ���ϱ�  
				isMinus=true; // �� ���� �����ʹ� ����  
			}
			else{
				ans = ans - num; // �����ϴ� ��� ����  
			}
		}
		else if(s[index]=='+'){ // + �� �� 
			int num = stoi(s.substr(sindex, cnt)); // string->int 
			sindex = index+1; // sindex�� index+1�� �ʱ�ȭ  
			cnt=0; // cnt=0 �ʱ�ȭ 
			if(isMinus) ans = ans - num; // �����ϴ� ��� ����  
			else ans += num; // ���ϱ�  
		}
		else if(index==s.size()-1){ // ���ڿ� ������ ��ȸ�� ���  
			int num = stoi(s.substr(sindex, cnt+1)); // string->int 
			if(isMinus) ans=ans-num; // �����ϴ� ��� ����  
			else ans+=num; // ���ϱ�  
			break; // ���� �ݺ��� ���� ������  
		}
		else{ // ������ ���  
			cnt++; // cnt 1 ����  
			
		}
	}
	
	// �� ���  
	cout<<ans;
}
