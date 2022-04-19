#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string s; 
	cin>>s; // 입력  
	
	int ans=0;
	bool isMinus=false; // 뺄지 여부  
	int index=-1; // 문자열 순회 인덱스  
	int sindex=0; // string->int 바꾸기 위한 시작점  
	int cnt=1; // string->int 바꾸기 위한 문자열 자릿수  
	while(true){
		index++; 
		if(s[index]=='-'){ // - 일 경우  
			int num = stoi(s.substr(sindex,cnt)); // string->int 
			sindex = index+1; // sindex를 index+1로 초기화  
			cnt=0; // cnt=0 초기화  
			if(!isMinus){
				ans+=num; // 더하기  
				isMinus=true; // 이 다음 경우부터는 빼기  
			}
			else{
				ans = ans - num; // 빼야하는 경우 빼기  
			}
		}
		else if(s[index]=='+'){ // + 일 경 
			int num = stoi(s.substr(sindex, cnt)); // string->int 
			sindex = index+1; // sindex를 index+1로 초기화  
			cnt=0; // cnt=0 초기화 
			if(isMinus) ans = ans - num; // 빼야하는 경우 빼기  
			else ans += num; // 더하기  
		}
		else if(index==s.size()-1){ // 문자열 마지막 순회일 경우  
			int num = stoi(s.substr(sindex, cnt+1)); // string->int 
			if(isMinus) ans=ans-num; // 빼야하는 경우 빼기  
			else ans+=num; // 더하기  
			break; // 무한 반복문 빠져 나오기  
		}
		else{ // 숫자일 경우  
			cnt++; // cnt 1 증가  
			
		}
	}
	
	// 답 출력  
	cout<<ans;
}
