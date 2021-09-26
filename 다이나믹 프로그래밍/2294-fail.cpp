#include<iostream>
using namespace std;

int a[100];
int d[10001];

int main(){
	int n,k; cin>>n>>k;
	
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=1;i<=k;i++){
		d[i]=i;
		for(int j=0;j<n;j++){
			if(i-a[j]>=0 && d[i]>d[i-j]+1) d[i]=d[i-j]+1;
		}
	}
	cout<<d[k];
}
