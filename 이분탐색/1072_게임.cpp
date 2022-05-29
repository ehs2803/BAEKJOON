#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	long long x,y;
	cin>>x>>y;
	
	long long z = y*100/x;
	
	if(z>=99) {
		cout<<-1;
		return 0;	
	}
	else{
		int left=0;
		int right=1000000000;
		while(left<=right){
			int mid=(left+right)/2;
			int temp=(y+mid) * 100 / (x+mid);
			if(z<temp) right=mid-1;
			else left=mid+1;
		}	
		
		cout<<left;
	}
}
