#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		vector<int> note1(n);
		for(int i=0;i<n;i++){
			cin>>note1[i];
		}
		
		// 오름차순 정렬  
		sort(note1.begin(), note1.end());
		
		int m;
		cin>>m;
		vector<int> note2(m);
		for(int i=0;i<m;i++){
			cin>>note2[i];
		}
		
		for(int i=0;i<m;i++){
			if(binary_search(note1.begin(), note1.end(), note2[i])) cout<<1<<'\n';
			else cout<<0<<'\n';
		}
	}
}
