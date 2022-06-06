#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	string str_num;
	cin>>str_num;
	
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=str_num[i]-'0';
	}
	
	cout<<ans;
}
