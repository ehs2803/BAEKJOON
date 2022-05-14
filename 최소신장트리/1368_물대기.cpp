#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> costs;

vector<pair<int, pair<int, int> > > edges;

int parent[301];

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
	
	// ���� ����� ���� ������ ��������  
    sort(edges.begin(), edges.end());

    int ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // �� ��尡 ���� ���տ� ������ ���� ��� ��ġ�� �� cost ���ϱ�  
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            ans += cost;
        }
    }
	
	// �� ���  
    cout<<ans;
}
