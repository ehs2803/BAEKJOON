#include<iostream>
using namespace std;

int main(void){
    int t; cin>>t;
    int d[12]={0};
    d[0]=1;
    for(int i=1;i<12;i++){
        if(i-1>=0){
            d[i]+=d[i-1];
        }
        if(i-2>=0){
            d[i]+=d[i-2];
        }
        if(i-3>=0){
            d[i]+=d[i-3];
        }
    }

    for(int i=0;i<t;i++){
        int n; cin>>n;
        cout<<d[n]<<endl;
    }
}
