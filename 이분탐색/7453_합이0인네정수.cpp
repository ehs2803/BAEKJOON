#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){	
	int n;
	cin>>n;
	
	int a[4000], b[4000], c[4000], d[4000];
	vector<int> x,y;
	
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			x.push_back(a[i]+b[j]);
			y.push_back(c[i]+d[j]);
		}
	}
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
	long long ans=0;
	for(int i=0;i<n*n;i++){
		ans+=upper_bound(y.begin(), y.end(), -x[i]) - lower_bound(y.begin(), y.end(), -x[i]);
	}
	
	cout<<ans;
}
