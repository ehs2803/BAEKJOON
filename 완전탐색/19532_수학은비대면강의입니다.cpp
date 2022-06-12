#include<iostream>
using namespace std;

//이 때 x와 y가 각각 -999 이상 999 이하의 정수인 경우만 입력으로 주어짐이 보장
int main(){
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	
	// 완전탐색  
	for(int i=-999;i<1000;i++){
		for(int j=-999; j<1000; j++){
			if(a*i+b*j==c && d*i+e*j==f){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}	
}
