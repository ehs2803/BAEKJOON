#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	string str; cin>>str;
	
	vector<string> v(str.length());
	
	for(int i=0;i<str.length();i++){
		v[i]=str.substr(i, str.length()-i);
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0;i<str.length();i++) cout<<v[i]<<'\n';
}
