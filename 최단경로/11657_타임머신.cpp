#include<iostream>
#include<vector>
#define INF 987654321
using namespace std;

vector<pair<pair<int, int>, int> > Edge;
long long Dist[501];

void Bellman_Ford(int n){
	for(int i=0;i<=n;i++) Dist[i]=INF;
	
	Dist[1] = 0;
    for (int i = 1; i <= n - 1; i++){
        for (int j = 0; j < Edge.size(); j++){
            int From = Edge[j].first.first;
            int To = Edge[j].first.second;
            int Cost = Edge[j].second;
 
            if (Dist[From] == INF) continue;
 
            if (Dist[To] > Dist[From] + Cost) Dist[To] = Dist[From] + Cost;
        }
    }
}

int main(){
	int n,m;
	cin>>n>>m;
	
    for (int i = 0; i < m; i++){
        int From, To, Cost;
        cin >> From >> To >> Cost;
        Edge.push_back(make_pair(make_pair(From, To), Cost));
    }

	Bellman_Ford(n);
	
    for (int i = 0; i < Edge.size(); i++){
        int From = Edge[i].first.first;
        int To = Edge[i].first.second;
        int Cost = Edge[i].second;
 
        if (Dist[From] == INF) continue;
        if (Dist[To] > Dist[From] + Cost){
            cout << -1 << endl;
            exit(0);
        }
    }
 
    for (int i = 2; i <= n; i++){
        if (Dist[i] == INF) cout << -1 << endl;
        else cout << Dist[i] << endl;
    }

}
