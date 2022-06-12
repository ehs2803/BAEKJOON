#include<iostream>
using namespace std;

int main(){
	int a,t,x;
	cin>>a>>t>>x;
	
	int T=2;
	int cnt=0;
	int person=0;
	while(true){
		person++;
		if(person==a+1) person=1;
		if(x==0){
			cnt++;
		}
		if(cnt==t) break;
		
		person++;
		if(person==a+1) person=1;
		if(x==1){
			cnt++;
		}
		if(cnt==t) break;
		
		person++;
		if(person==a+1) person=1;
		if(x==0){
			cnt++;
		}
		if(cnt==t) break;
		
		person++;
		if(person==a+1) person=1;
		if(x==1){
			cnt++;
		}
		if(cnt==t) break;
		
		for(int i=0;i<T;i++){
			person++;
			if(person==a+1) person=1;
			if(x==0){
				cnt++;
			}
			if(cnt==t) break;
		}
		if(cnt==t) break;
		
		for(int i=0;i<T;i++){
			person++;
			if(person==a+1) person=1;
			if(x==1){
				cnt++;
			}
			if(cnt==t) break;
		}
		if(cnt==t) break;
		
		T++;
	}
	
	cout<<person-1;
} 
