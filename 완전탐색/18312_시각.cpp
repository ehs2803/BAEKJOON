#include<iostream>
using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	
	int ans=0;
	for(int h=0;h<=n;h++){
		for(int m=0;m<=59;m++){
			for(int s=0;s<=59;s++){
				string hour = to_string(h);
				if(hour.size()==1) hour = "0"+hour;
				string minute = to_string(m);
				if(minute.size()==1) minute = "0"+minute;
				string second = to_string(s);
				if(second.size()==1) second = "0"+second;
				
				string time = hour+minute+second;
				if(time.find(to_string(k))!=string::npos){
					ans++;
				}
			}
		}
	}
	
	cout<<ans;
} 
