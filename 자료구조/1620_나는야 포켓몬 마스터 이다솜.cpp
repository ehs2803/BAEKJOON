#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin>>n>>m;
	
	unordered_map<string, int> m1;
	unordered_map<int, string> m2;
	
	for(int i=1;i<=n;i++){
		string name;
		cin>>name;
		m1.insert({name,i});
		m2.insert({i,name});
	}
	
	for(int i=0;i<m;i++){
		string input;
		cin>>input;
		
		if('0'<=input[0]&&input[0]<='9'){
			int number = stoi(input);
			cout<<m2[number]<<'\n';
		}
		else{
			cout<<m1[input]<<'\n';
		}
	}
}
