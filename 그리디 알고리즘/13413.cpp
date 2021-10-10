// 오셀로 재배치 - 그리디
// 성공.
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        int n, B=0, W=0;
        string target, state;
        cin>>n>>state>>target;

        for(int i=0;i<n;i++){
            if(target[i]!=state[i]){
                if(target[i]=='B') B++;
                else W++;
            }
        }

        int ans=0;
        while(B>0 && W>0){
            ans++;
            B--;
            W--;
        }
        ans += B;
        ans += W;
        cout<<ans<<'\n';
    }
}
