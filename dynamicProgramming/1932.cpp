#include<iostream>
using namespace std;
int a[501][501];
int d[501][501];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) cin>>a[i][j];
    }
    d[1][1] = a[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            d[i][j]=d[i-1][j];
            if(d[i][j]<d[i-1][j-1]) d[i][j]=d[i-1][j-1];
            d[i][j]+=a[i][j];
        }
    }
    int ans=d[n][1];
    for(int i=1;i<=n;i++){
        if(ans<d[n][i]) ans=d[n][i];
    }
    cout<<ans;
}
