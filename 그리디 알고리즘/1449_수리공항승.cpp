#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool location[1001];

int main(){
	int n,k;
	cin>>n>>k;
	
	vector<int> leak(n);
	for(int i=0;i<n;i++){
		cin>>leak[i];
	}
	
	sort(leak.begin(), leak.end());
	
	int ans=0;
	for(int i=0;i<n;i++){
		if(location[leak[i]]==false){
			int leakLocation = leak[i];
			for(int j=0;j<k;j++){
				location[leakLocation+j]=true;	
			}
			ans++;
		}
	}	
	
	cout<<ans;
}
