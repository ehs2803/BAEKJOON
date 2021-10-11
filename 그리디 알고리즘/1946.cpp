// 신입 사원 - 그리디
// 성공. 시간초과문제 해결.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        vector<pair<int, int> > v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].first>>v[i].second;
        }

        sort(v.begin(),v.end());

        /* 구버전 코드
        int ans=n;
        for(int i=n-1; i>=1; i--){
            for(int j=i-1;j>=0;j--){
                if(v[i].second>v[j].second){
                    ans--;
                    break;
                }
            }
        }
        */

        int ans=1;
        int highRank=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].second<highRank) {
                ans++;
                highRank = v[i].second;
            }
        }

        cout<<ans<<'\n';
    }
}

