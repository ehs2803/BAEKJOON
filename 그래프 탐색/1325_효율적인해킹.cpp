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
	
	// ��� ��忡�� ���� bfs  
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		bfs(i);
	}
	
	// �ִ밪 ���ϱ�  
	int max=0;
	for(int i=1;i<=n;i++){
		if(max<hack_cnts[i]) max = hack_cnts[i];
	}
	
	// �ִ񰪰� ��ġ�ϴ� ��� ans vector�� �߰�  
	vector<int> ans;	
	for(int i=1;i<=n;i++){
		if(hack_cnts[i]==max) ans.push_back(i);
	}
	
	// �������� ����  
	sort(ans.begin(), ans.end());
	
	// �� ���  
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
	
}
