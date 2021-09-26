#include<iostream>
using namespace std;

int main(void){
    int n; cin>>n;
    int p[1001];
    int d[1000];
    d[0]=0;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            d[i]=max(d[i-j]+p[j],d[i]);
        }
    }
    cout<<d[n];
}
