#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int ans[100001];

// bfs
void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start]=true;
	
	while(!q.empty()){
		int parent = q.front();
		q.pop();
		
		for(int i=0;i<graph[parent].size();i++){
			int child = graph[parent][i];
			if(visited[child]==false){
				ans[child]=parent;
				visited[child]=true;
				q.push(child);
			}
		}
	}	
}

int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	bfs(1); 
	
	for(int i=2;i<=n;i++) cout<<ans[i]<<'\n';
}
