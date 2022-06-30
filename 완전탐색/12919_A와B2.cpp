#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool check=false;

void convert(string start, string target, int mode){
	if(start.size()==target.size()){
		if(start==target) check=true;
	}	
	
	if(mode==0){
		start+="A";
	}
	if(mode==1){
		start+="B";
		reverse(start.begin(), start.end());
	}
	
	convert(start, target, 0);
	convert(start, target, 1);
}

int main(){
	string s,t;
	
	cin>>s>>t;
	
	convert(s,t,0);
	convert(s,t,1);
	
	if(check){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
