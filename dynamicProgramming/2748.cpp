#include<iostream>
using namespace std;

int main(){
	long long a[91]={0};
	int n; cin>>n;
	
	a[0]=0;
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=a[i-1]+a[i-2];
	}
	
	cout<<a[n];
}
