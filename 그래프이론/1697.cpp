// 숨바꼭질
// 그래프이론 - bfs
#include<iostream>
#include<queue>
using namespace std;

bool visited[100001];

int main(){
    int n,k; cin>>n>>k;

    queue<pair<int,int> > q;

    q.push({n, 0});
    visited[n]= true;
    int answer;
    while(true){
        int cn = q.front().first;
        int cnt = q.front().second;

        q.pop();
        if(cn==k) {
            answer=cnt;
            break;
        }

        cnt+=1;
        int pn = cn+1;
        int mn = cn-1;
        int dn = cn*2;


        if(pn>=0&&pn<=100000&&visited[pn]== false) {
            q.push({pn,cnt});
            visited[pn]= true;
        }
        if(mn>=0&&mn<=100000&&visited[mn]== false){
            q.push({mn,cnt});
            visited[mn]= true;
        }
        if(dn>=0&&dn<=100000&&visited[dn]== false){
            q.push({dn,cnt});
            visited[dn]= true;
        }
    }

    cout<<answer;
}
