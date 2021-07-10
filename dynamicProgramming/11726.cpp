#include<iostream>
using namespace std;

int main(void){
    int n; cin>>n;
    int d[1001]={0};
    d[0]=1;
    d[1]=1;
    for(int i=2;i<=n;i++){
        if(i-1>=0){
            d[i]+=d[i-1];
        }
        if(i-2>=0){
            d[i]+=d[i-2];
        }
        d[i] %= 10007;
    }
    cout<<d[n];
}
