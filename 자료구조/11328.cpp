#include<iostream>
#include<vector>
using namespace std;

int alpSrc[26], alpDes[26];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin>>t;
	
	while(t--){
		string src, des;
		cin>>src>>des;
		
		for(int i=0; i<src.length(); i++){
			alpSrc[src[i]-'a']++;
			alpDes[des[i]-'a']++;
		}
		bool check = true;
		for(int i=0; i<26; i++){
			if(alpSrc[i]!=alpDes[i]) {
				check=false;
				break;
			}
		}
		
		if(check) cout<<"Possible"<<'\n';
		else cout<<"Impossible"<<'\n';
		
		for(int i=0; i<26; i++){
			alpSrc[i]=0;
			alpDes[i]=0;
		}
	}
}
