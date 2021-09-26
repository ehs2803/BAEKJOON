#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	if(a.first.first==b.first.first){
		return a.first.second<b.first.second;
	}
	else{
		return a.first.first<b.first.first;
	}
}

int main(){
	int n, w, t; cin>>n>>w>>t;
	
	vector<pair<pair<int, int>, int> > v(t);
	for(int i=0;i<t;i++){
		cin>>v[i].first.first>>v[i].first.second>>v[i].second;
	}
	
	sort(v.begin(), v.end(), cmp);
	
	int weigth=0;
	for(int i=1;i<=n;i++){
		
	}
	/*
	for(int i=0;i<t;i++){
		cout<<v[i].first.first<<' '<<v[i].first.second<<' '<<v[i].second;
	}
	*/
}
