#include<iostream>
#include<queue>
#define INF 987654321
using namespace std;

int Dist[100001];

// 다익스트라 알고리즘  
void dijkstra(int start){
    priority_queue<pair<int , int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({0,start});
    Dist[start]=0;

    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(Dist[now]<dist) continue;
        
        int next, cost;
		
        next = now-1;
        if(!(next < 0 || next > 100000)){
        	cost = dist+1;
        	if(cost<Dist[next]){
            	Dist[next]=cost;
            	pq.push({cost, next});
        	}	
		}

        next = now+1;
        if(!(next < 0 || next > 100000)) {
        	cost = dist + 1;
        	if(cost<Dist[next]) {
            	Dist[next]=cost;
            	pq.push({cost, next});
        	} 
		}
        cost = dist+1;
      
        next = now*2;
        if(!(next < 0 || next > 100000)){
        	cost = dist;
        	if(cost<Dist[next]){ 
            	Dist[next]=cost;
            	pq.push({cost, next});
        	}
		}
    }
}

int main(){
    int n, k; 
    cin>>n>>k;
    
    for(int i=0;i<100001;i++) Dist[i]=INF;
    
    dijkstra(n);
    
    cout<<Dist[k];
}
