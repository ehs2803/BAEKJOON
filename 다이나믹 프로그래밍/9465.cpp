#include<iostream>
#include <algorithm>
using namespace std;

long long a[100001][2];
long long d[100001][3];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    d[0][0]=0; d[0][1]=0; d[0][2]=0;

    int t; cin>>t;
    for(int i=0;i<t;i++){
        int n; cin>>n;
        for(int j=0;j<2;j++){
             for(int k=1;k<=n;k++) cin>>a[k][j];
        }
         for (int i=1; i<=n; i++) {
            d[i][0] = max({d[i-1][0],d[i-1][1],d[i-1][2]});
            d[i][1] = max(d[i-1][0],d[i-1][2])+a[i][0];
            d[i][2] = max(d[i-1][0],d[i-1][1])+a[i][1];
        }
        long long ans = max({d[n][0], d[n][1], d[n][2]});
        cout << ans << '\n';
    }
}
