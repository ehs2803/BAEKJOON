#include<iostream>
using namespace std;

int main(){
	string str; cin>>str;
	
	int n0=0, n1=0;
	bool ch0 = false, ch1 = false;
	
	if(str[0]=='0'){
	    n0++;
	    ch0=true;
	}
	else{
		n1++;
		ch1=true;
	}
	
	for(int i=0;i<str.length();i++){
		if(str[i]=='0'){
			if(ch1){
				ch1=false;
				ch0=true;
				n0++;
			}
		}
		else{
			if(ch0){
				ch0=false;
				ch1=true;
				n1++;
			}
		}
	}
	
	cout<<min(n0,n1);
}
