#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t; cin>>t;
	
	while(t--){
		int n; cin>>n;
		vector<int> v(n);
		
		for(int i=0;i<n;i++) cin>>v[i];
		
		int ans = 0;
		
		for(int i=0;i<n;i++){
			int main = v[i];
			int best = main;
			int maxIndex;
			bool check=false;
			for(int j=i+1;j<n;j++){
				if(v[j]>best) {
					best=v[j];
					maxIndex=j;
					check=true;	
				}
			}
			if(check) ans = ans+(best-main);
		}
		cout<<ans<<'\n';
	}
}
