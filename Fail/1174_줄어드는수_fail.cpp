#include<iostream>
#include<queue>
using namespace std;


long long bfs(int n){
	int cnt=0;
	
	queue<long long> q;
	for(int i=0;i<9;i++){
		q.push(i);
		cnt++;
		if(cnt==n){
			return i;
		}
	}
	
	while(!q.empty()){
		long long now = q.front();
		q.pop();
		
        for (int i=0; i<now%10; i++) {
            long long next = now*10+i;
            if(next>9876543210) continue;
            q.push(next);
            cnt++;
            if(cnt==n){
                return next;
            }
        }
	}
	
	return -1;
}

int main(){
	int n;
	cin>>n;
	
	cout<<bfs(n-1);
}
