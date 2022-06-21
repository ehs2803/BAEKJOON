#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,s,e;
vector<pair<int,int> > edge[10001];
bool visited[10001];
int small=0;
int big=0;

void Init() {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}

void DFS(int x, int mid) {
	for (int i = 0; i < edge[x].size(); i++) {
		if (!visited[edge[x][i].first] && (edge[x][i].second >= mid)) {
			visited[edge[x][i].first] = true;
			DFS(edge[x][i].first, mid);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edge[a].push_back({b,c});
		edge[b].push_back({a,c});
		big = max(big, c);
	}
	cin>>s>>e;
	
	while (small<=big) {
		Init();
		int mid = (small+big) / 2;
		visited[s] = true;
		DFS(s, mid);
		if (visited[e]) {
			small = mid + 1;
		}
		else {
			big = mid - 1;
		}
	}
	cout << big<< "\n";
}
