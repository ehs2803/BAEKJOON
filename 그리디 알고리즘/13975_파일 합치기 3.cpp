#include<iostream>
#include<queue>
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int k;
		cin>>k;
		priority_queue<long long, vector<long long>, greater<long long>> pq;//√÷º“»¸
		for(int i=0;i<k;i++){
			int temp;
			cin>>temp;
			pq.push(temp);
		}
		
		long long ans=0;
		while(!pq.empty()){
			if(pq.size()==1) break;
			
			long long first = pq.top(); pq.pop();
			long long second = pq.top(); pq.pop();
			long long sum = first+second;
			ans+=sum;
			pq.push(sum);
		}

		cout<<ans<<'\n';
	}
}
