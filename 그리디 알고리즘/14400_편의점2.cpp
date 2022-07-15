#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmpX(const pair<int,int> & a, const pair<int,int> & b){
	if(a.first<b.first) return true;
	else return false;	
}

bool cmpY(const pair<int,int> & a, const pair<int,int> & b){
	if(a.second<b.second) return true;
	else return false;
}

int main(){
	int n;
	cin>>n;
	
	vector<pair<int,int> > location(n);
	for(int i=0; i<n;i++){
		cin>>location[i].first>>location[i].second;
	}
	
	int middleX, middleY;
	
	sort(location.begin(), location.end(), cmpX);
	middleX = location[n/2].first;
	
	sort(location.begin(), location.end(), cmpY);
	middleY = location[n/2].second;
	
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+= abs(location[i].first-middleX) + abs(location[i].second-middleY);
	}
	
	cout<<ans;
}
