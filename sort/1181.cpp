#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string &a, string &b){
	if(a.size()<b.size()){
		return 1;
	}
	else if(a.size()>b.size()){
		return 0;
	}
	else{
		return a<b;
	}
}

int main(){
	int n; cin>>n;
	vector<string> v(n);
	
	for(int i=0;i<n;i++) cin>>v[i];
	
	sort(v.begin(), v.end(), cmp);
	
	string temp;
	for(int i=0;i<n;i++) {
		if(temp==v[i]) continue;
		cout<<v[i]<<'\n';
		temp = v[i];	
	}
}
