#include<iostream>
#include<map>
#include<set> 
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		
		map<string, set<string>> m;
		for(int i=0;i<n;i++){
			string name, sort;
			cin>>name>>sort;
			
			m[sort].insert(name);
		}
		/*
		if(m.size()==1) {
			cout<<m.begin()->second.size();
			continue;
		}
		*/
		int ans=1;
		for (map<string,set<string>>::iterator iter = m.begin(); iter != m.end(); ++iter){
        	ans*=(iter->second.size()+1);
    	}
    	
    	ans-=1;
    	cout<<ans<<'\n';
	}
}
