#include<iostream>
#include<string>
using namespace std;

int main(){
	while(true){
		string str;
		cin>>str;
		
		if(str=="end") break;
		
		// 1. a e i o u
		bool check1 = false;
		for(int i=0; i<str.size();i++){
			if(str[i]=='a'||str[i]=='e'||str[i]=='i'||
				str[i]=='o'||str[i]=='u'){
					check1=true;
					break;
			}
		}
		
		if(check1==false){
			cout<<"<"<<str<<"> is not acceptable."<<'\n';
			continue;
		}
		
		//2. 연속 3개
		bool check2=true;
		int cnt=0;
		int Case;
		if(str[0]=='a'||str[0]=='e'||str[0]=='i'|| str[0]=='o'||str[0]=='u'){
			Case=0;
			cnt++;
		}
		else{
			Case=1;
			cnt++;
		}
		
		for(int i=1;i<str.size();i++){
			if(str[i]=='a'||str[i]=='e'||str[i]=='i'|| str[i]=='o'||str[i]=='u'){
				if(Case==1){
					Case=0;
					cnt=1;
				}
				else{
					cnt++;
					if(cnt==3){
						check2=false;
						break;
					}
				}	
			}
			else{
				if(Case==0){
					Case=1;
					cnt=1;
				}
				else{
					cnt++;
					if(cnt==3){
						check2=false;
						break;
					}
				}
			}
		}
		
		if(check2==false){
			cout<<"<"<<str<<"> is not acceptable."<<'\n';
			continue;
		}
		
		// 3. 같은글자 두개 연속 x / ee oo 허용 
		bool check3 = true;
		char pre=str[0];
		for(int i=1;i<str.size();i++){
			if(str[i]==pre){
				if(str[i]=='e' || str[i]=='o'){
					pre=str[i];
				}
				else{
					check3=false;
					break;
				}
			}
			else{
				pre=str[i];
			}
		}
		
		if(check3==false){
			cout<<"<"<<str<<"> is not acceptable."<<'\n';
			continue;
		}
		
		cout<<"<"<<str<<"> is acceptable."<<'\n';
	}
}
