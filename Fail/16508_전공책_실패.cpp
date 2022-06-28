#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	string target;
	cin>>target;
	
	int n;
	cin>>n;
	
	vector<pair<int,string> > arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	
	int ans=1e9;
	bool check=false;
	for(int i=1;i<=n;i++){
		int r = i;
    
    	vector<bool> temp(arr.size(), false);
    	for(int i = 0; i < r; i ++) temp[i] = true;
 
    	do {
    		int temp_ans=0;
    		vector<bool> check_in_string(target.size(), false);
        	for (int i = 0; i < arr.size(); ++i) {
            	if (temp[i]){
            		bool check_istring=false;
            		for(int m=0;m<target.size();m++){
            			if(check_in_string[m]) continue;
            			for(int n=0;n<arr[i].second.size();n++){
            				if(arr[i].second[n]==target[m]){
            					check_in_string[m]=true;
            					check_istring=true;
            					break;
							}
						}
					}
					if(check_istring) temp_ans+=arr[i].first;
				}
        	}
        	
    		bool available=true;
    		for(int i=0;i<target.size();i++){
    			if(check_in_string[i]==false){
    				available=false;
    				break;
				}
			}
			if(available){
				if(temp_ans<ans) {
					ans=temp_ans;
					check=true;
				}
			}
    	} while (prev_permutation(temp.begin(), temp.end()));
    	
	}
	
	if(check==false) cout<<-1;
	else cout<<ans;
}
