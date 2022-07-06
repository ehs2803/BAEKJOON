#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<pair<ll,ll>> v(n);
    ll total = 0;
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        total+=v[i].second;
    }
    
    sort(v.begin(), v.end());
    
    ll cur=0;
    for(int i=0;i<n;i++){
    	cur+=v[i].second;
    	if(cur>=(total+1)/2) {
    		cout<<v[i].first;
            break;
        }
	}
    /* 시간초과  
    vector<ull> dist(n);
    
    for(int i=0;i<n;i++){
        ull d=0;
        //int pcnt=v[i].second;
        for(int j=0;j<n;j++){
            if(i!=j){
                d+=(v[j].second*abs(v[i].first-v[j].first));
            }
        }
        dist[i]=d;
    }
    
    int minIndex=0;
    ull minValue=dist[0];
    for(int i=1;i<n;i++){
        if(dist[i]<minValue){
            minIndex=i;
            minValue=dist[i];
        }
    }
    */
    
}
