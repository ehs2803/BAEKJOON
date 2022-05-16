#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> graph[10001];
bool visited[10001];
int hack_cnts[10001];

void bfs(int start){
	int hack_cnt = 0;
	
	queue<int> q;
	q.push(start);
	visited[start]=true;
	hack_cnt++;
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		for(int i=0;i<graph[now].size();i++){
			int next = graph[now][i];
			if(visited[next]==false){
				q.push(next);
				visited[next]=true;
				hack_cnt++;
			}
		}
	}
	
	hack_cnts[start]=hack_cnt;
}

int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		graph[v].push_back(u);
	}	
	
	// 모든 노드에서 각각 bfs  
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		bfs(i);
	}
	
	// 최대값 구하기  
	int max=0;
	for(int i=1;i<=n;i++){
		if(max<hack_cnts[i]) max = hack_cnts[i];
	}
	
	// 최댓값과 일치하는 노드 ans vector에 추가  
	vector<int> ans;	
	for(int i=1;i<=n;i++){
		if(hack_cnts[i]==max) ans.push_back(i);
	}
	
	// 오름차순 정렬  
	sort(ans.begin(), ans.end());
	
	// 답 출력  
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
	
}
