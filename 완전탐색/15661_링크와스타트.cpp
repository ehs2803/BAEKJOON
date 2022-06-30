#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[20][20];

int main(){
	int n;
	cin>>n;

	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	
	int ans=1e9;
	for(int i=1;i<=n/2;i++){
		int r = i;
    	vector<bool> temp(n, false);
    	for(int i = 0; i < r; i ++) temp[i] = true;

    	do {
    		vector<int> start;
    		vector<int> link;
        	for (int i = 0; i < temp.size(); ++i) {
            	if (temp[i]) start.push_back(i);
            	else link.push_back(i);
        	}
        	
        	int start_function=0;
        	int link_fuction=0;
        	for(int m=0;m<start.size();m++){
        		for(int n=m+1;n<start.size();n++){
        			start_function+=map[start[m]][start[n]];
        			start_function+=map[start[n]][start[m]];
				}
			}
			for(int m=0;m<link.size();m++){
        		for(int n=m+1;n<link.size();n++){
        			link_fuction+=map[link[m]][link[n]];
        			link_fuction+=map[link[n]][link[m]];
				}
			}
        	
        	if(abs(start_function-link_fuction)<ans) ans=abs(start_function-link_fuction);
        	
    	} while (prev_permutation(temp.begin(), temp.end()));
	}
	
	cout<<ans;
	

}
