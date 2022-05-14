#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, pair<int, int> > > edges;

int parent[100001];

// Ư�� ���Ұ� ���� ���� ã��  
int find_parent(int x){
    if(parent[x]!=x) return find_parent(parent[x]);
    return x;
}

// �� ���Ұ� ���� ���� ��ġ��  
void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back({c,{a,b}});
	}
	
	for(int i=1;i<=n;i++) parent[i]=i;
	
	// ���� ����� ���� ������ ��������  
    sort(edges.begin(), edges.end());

    long long mst = 0;
    long long total=0; 
    int cnt=0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        total+=cost;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // �� ��尡 ���� ���տ� ������ ���� ��� ��ġ�� �� cost ���ϱ�  
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            mst += cost;
            cnt++;
        }
    }

	
	long long ans = total-mst;
	// �� ���  
	if(cnt==n-1) cout<<ans;
	else cout<<-1;
}
