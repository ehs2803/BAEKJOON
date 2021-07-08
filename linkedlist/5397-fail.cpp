#include<iostream>
#include<list>
#include<string>
using namespace std;

int main(){
	int t; cin>>t;
	
	while(t--){
		list<char> L;
		list<char>::iterator it = L.begin();
		it--;
		string str; cin>>str;
		
		for(int i=0;i<str.length();i++){
			if(str[i]=='<'){
				if(it!=L.begin()) it--;
			}
			else if(str[i]=='>'){
				if(it!=L.end()) it++;
			}
			else if(str[i]=='-'){
				if(!L.empty()) L.erase(it);
			}
			else{
				L.insert(it, str[i]);
			}
		}
		for(list<char>::iterator t = L.begin(); t!=L.end(); t++)
        	cout<< *t;
        cout<<'\n';
	}
}
