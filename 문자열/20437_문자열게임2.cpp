#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		vector<vector<int>> alphaCnt(26);
		
		string w;
		int k;
		
		cin>>w>>k;
		
		int mini = 100000;
        int maxi = 0;
		for(int i=0;i<w.size();i++){
			int num = w[i]-97;
			alphaCnt[num].push_back(i);
		}
		
		for(int i=0;i<26;i++){
			if(alphaCnt[i].size()>=k){
				for(int j = 0; j<=alphaCnt[i].size() - k; j++){ 
                    mini = min(mini, alphaCnt[i][j+k-1] - alphaCnt[i][j] + 1);
                    maxi = max(maxi, alphaCnt[i][j+k-1] - alphaCnt[i][j] + 1);
                }
			}
		}
		
		if(mini == 100000 || maxi == 0) cout << -1 << "\n";
        else cout << mini << " " << maxi << "\n";
	}
}
