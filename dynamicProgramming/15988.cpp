#include<iostream>
using namespace std;

long long mod=1000000009;
long long d[1000001];

int main(void){
    int t; cin>>t;
    d[0]=1;
    for(int i=1;i<=1000000;i++){
        if(i-1>=0){
            d[i]+=d[i-1];
        }
        if(i-2>=0){
            d[i]+=d[i-2];
        }
        if(i-3>=0){
            d[i]+=d[i-3];
        }
        d[i]%=mod;
    }
    for(int i=0;i<t;i++){
        int temp; cin>>temp;
        cout<<d[temp]<<'\n';
    }
}
