#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	unordered_map<string,string> sitePwdMap;
	for(int i=0;i<n;i++){
		string site, pwd;
		cin>>site>>pwd;
		sitePwdMap.insert({site,pwd});
	}
	
	for(int i=0;i<m;i++){
		string site;
		cin>>site;
		cout<<sitePwdMap[site]<<'\n';
	}
}
