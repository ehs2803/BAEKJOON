#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;

int main(){
	string str[5];
	
	for(int i=0;i<5;i++){
		cin>>str[i];
	}
	
	int maxSize = max(str[0].size(), max(str[1].size(), max(str[2].size(), max(str[3].size(), str[4].size()))));
	

	for(int i=0;i<maxSize;i++){
		for(int j=0;j<5;j++){
			if(str[j].size()-1>=i){
				cout<<str[j][i];
			}
			else{
				continue;
			}
		}
	}
	
}
