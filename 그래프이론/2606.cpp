// 바이러스
// 성공. 그래프 이론 - 서로소
#include<iostream>
using namespace std;

int find_parent(int parent[], int x){
    if(parent[x]!=x) return find_parent(parent, parent[x]);
    return x;
}

void union_parent(int parent[], int a, int b){
    a = find_parent(parent, a);
    b = find_parent(parent, b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main(){
    int n; cin>>n;
    int *parent = new int[n+1];
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    int k; cin>>k;
    for(int i=0;i<k;i++){
        int a, b; cin>>a>>b;
        union_parent(parent,a,b);
    }
    /*
    for(int i=0;i<n;i++){
        cout<<find_parent(parent,i+1)<<' ';
    }
     */
    int cnt=0;
    int onep = find_parent(parent, 1);
    for(int i=2;i<=n;i++){
        if(find_parent(parent,i)==onep) cnt++;
    }
    cout<<cnt;
}
