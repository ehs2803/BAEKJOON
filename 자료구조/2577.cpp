#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(1);
    int arr[10];
    fill(arr,arr+10,0);
    int a,b,c;
    cin>>a>>b>>c;
    int result = a*b*c;
    string str = to_string(result);
    //48 = 0
    for(int i=0;i<str.size();i++){
        arr[str[i]-48]+=1;
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<"\n";
    }
}
