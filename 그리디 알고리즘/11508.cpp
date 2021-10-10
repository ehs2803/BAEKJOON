// 2+1 세일 - 그리디
// 성공.
#include<iostream>
#include<algorithm>
using namespace std;

bool desc(int a, int b){
    if(a>b) return true;
    else return false;
}

int main(){
    int n; cin>>n;
    int *arr = new int[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n, desc);

    int cnt=0;
    int minprice=0;
    for(int i=0;i<n;i++){
        cnt++;
        if(cnt==3){
            cnt=0;
        }
        else{
            minprice+=arr[i];
        }
    }

    cout<<minprice;
}
/*
int main(){
    int n; cin>>n;
    int *arr = new int[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);

    int sindex=-1;
    int lindex=n;
    ull minprice=0;
    while(true){
        if(lindex-sindex-1>=3){
            sindex++;
            minprice+=1L*arr[++sindex];
            minprice+=1L*arr[--lindex];
        }
        else{
            while(++sindex!=lindex){
                minprice+=1L*arr[sindex];
            }
            break;
        }
    }

    cout<<minprice;
}
 */