#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int ans=1;
	while(true){
		if(ans>n){
			cout<<0;
			return 0;
		}
		
		int test=ans;
		string str_num = to_string(ans);
		for(int i=0;i<str_num.size();i++){
			test+=str_num[i]-48;
		}
		
		if(test==n){
			cout<<ans;
			return 0;
		}
		else{
			ans++;
		}
		
	}
} 
