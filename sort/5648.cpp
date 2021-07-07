#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int n; cin>>n;
	vector<long long> v;
	
	for(int i=0;i<n;i++){
		string str; cin>>str;
		reverse(str.begin(), str.end());
		v.push_back(stoll(str));
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0;i<n;i++) cout<<v[i]<<'\n';
}
