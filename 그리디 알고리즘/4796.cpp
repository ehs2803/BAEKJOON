#include<iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt=0;
    while(true){
        cnt++;
        int L,P,V;
        cin>>L>>P>>V;
        if(L==0 && P==0 && V==0) break;

        int ans=0;
        ans += L*(V/P);
        if(V%P>L) ans+=L; // 예외처리
        else ans += V%P;

        cout<<"Case "<<cnt<<": "<<ans<<'\n';
    }
}
