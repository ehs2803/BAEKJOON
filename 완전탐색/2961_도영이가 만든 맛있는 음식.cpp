#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	vector<pair<int,int> > ingredients(n);
	for(int i=0;i<n;i++){
		cin>>ingredients[i].first>>ingredients[i].second;
	}
	
	int ans=1e9;
	for(int i=1;i<=n;i++){
		int r = i;
    	vector<bool> temp(n, false);
    	for(int i = 0; i < r; i ++) temp[i] = true;

    	do {
    		int sour=1;
 			int bitter=0;
        	for (int i = 0; i < temp.size(); ++i) {
            	if (temp[i]){
            		sour*=ingredients[i].first;
            		bitter+=ingredients[i].second;
				}
        	}
        	
        	if(abs(sour-bitter)<ans) ans=abs(sour-bitter);
        	
    	} while (prev_permutation(temp.begin(), temp.end()));
	}
	
	cout<<ans;
}
