#include<iostream>
#include<queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	queue<int> q;
	
	int n; cin>>n;
	
	for(int i=1;i<=n;i++) q.push(i);
	
	bool check = true;
	while(q.size()!=1){
		if(check){
			q.pop();
			check=false;
		}
		else{
			int temp = q.front();
			q.pop();
			q.push(temp);
			check=true;
		}
	}
	cout<<q.front();
}
