#include<iostream>
using namespace std;

int main(){
	string content, search;
	
	cin>>content>>search;
	
	// 입력 받은 문자열에서 영문자만 뽑아 새로운 문자열 만들기  
	string str="";
	for(int i=0;i<content.size();i++){
		if(('a'<=content[i]&&content[i]<='z')||('A'<=content[i]&&content[i]<='Z')){
			str+=content[i];
		}
	}
	
	// find 메소드 이용해 문자열이 있으면 1 출력  
	if(str.find(search)!= string::npos){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
