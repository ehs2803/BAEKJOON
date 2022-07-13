#include<iostream>
using namespace std;

bool case1(string str){
	if(str[0]=='A'){
		int index=1;
		for(int i=1; i<str.size();i++){
			if(str[i]!='A'){
				index=i;
				break;
			}
		}
		
		if(str[index]=='F'){
			for(int i=index;i<str.size();i++){
				if(str[i]!='F'){
					index=i;
					break;
				}
			}
			
			if(str[index]=='C'){
				for(int i=index;i<str.size(); i++){
					if(str[i]!='C'){
						index=i;
						break;
					}
				}
				
			}
			else return false;
		}
		else return false;
	}	
	else return false;
}

int main(){
	int n;
	cin>>n;
	
	while(n--){
		string str;
		cin>>str;
		
		
	}
}
