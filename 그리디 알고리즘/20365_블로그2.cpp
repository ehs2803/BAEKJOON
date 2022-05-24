#include<iostream>
using namespace std;

int main(){ 
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	char prechar = s[0];
	int preCnt = 1;
	int oneCnt=1, twoCnt=0;
	for(int i=1;i<n;i++){
		if(s[i]!=prechar){
			prechar = s[i];
			if(preCnt==1){
				preCnt=2;
				twoCnt++;
			}
			else{
				preCnt=1;
				oneCnt++;
			}
		}
	}
	
	cout<<min(oneCnt,twoCnt)+1;
	/* 시간초과... 
	// 입력받은 문자열에서 연속되는 문자를 한개로 치환. 
	char prechar = s[0];
	string newStr="";
	newStr = newStr + prechar;
	for(int i=1;i<n;i++){
		if(s[i]!=prechar){
			newStr = newStr+s[i];
			prechar=s[i];
		}
	}

	// 바꾼 문자열에서 B,R 개수 구하기  
	int bCnt=0, rCnt=0;
	for(int i=0;i<newStr.size();i++){
		if(newStr[i]=='B') bCnt++;
		else rCnt++;
	}
	
	// B,R 개수 중 작은 거에다가 1증가 
	cout<<min(rCnt,bCnt)+1;
	*/
}
