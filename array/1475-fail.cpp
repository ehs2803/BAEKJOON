#include<iostream>
#include<string>
using namespace std;

int main(){
	int innum; cin>>innum;
	string str = to_string(innum);
	
	int ans=0;
	int cnt = 0;
	for(int i=0;i<str.length(); i++){
		if(str[i]=='6' || str[i]=='9'){
			cnt++;
		}
		else{
			ans++;
		}
	}
	ans = ans + (cnt/2) + (cnt%2);
	cout<<ans;
}
