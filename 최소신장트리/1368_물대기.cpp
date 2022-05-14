#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> costs;

vector<pair<int, pair<int, int> > > edges;

int parent[301];

// 특정 원소가 속한 집합 찾기  
int find_parent(int x){
    if(parent[x]!=x) return find_parent(parent[x]);
    return x;
}

// 두 원소가 속한 집합 합치기  
void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++) {
		int temp;
		cin>>temp;
		edges.push_back({temp,{0,i}});
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int temp;
			cin>>temp; 
			if(i!=j && i<j){
				edges.push_back({temp,{i+1, j+1}});
			}
		}
	}
	
	for(int i=1;i<=n;i++) parent[i]=i;
	
	// 간선 비용이 적은 순으로 오름차순  
    sort(edges.begin(), edges.end());

    int ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // 두 노드가 같은 집합에 속하지 않은 경우 합치기 및 cost 더하기  
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            ans += cost;
        }
    }
	
	// 답 출력  
    cout<<ans;
}
