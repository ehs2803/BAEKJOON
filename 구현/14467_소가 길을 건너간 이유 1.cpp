#include<iostream>
#include<vector>
using namespace std;

int cowLocation[11]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int main(){
	int n;
	cin>>n;
	
	int ans=0;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		int cow, location;
		cin>>cow>>location;
		
		if(cowLocation[cow]==-1){
			cowLocation[cow]=location;
		}
		else if(cowLocation[cow]!=location){
			cowLocation[cow]=location;
			ans++;
		}
	}
	// ´ä Ãâ·Â  
	cout<<ans;
}
