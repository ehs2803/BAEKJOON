#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	vector<int> arr(n);
	int sum=0;
	int Cnt2=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		Cnt2+=arr[i]/2;
	}
	
	if(sum%3==0){
		if(Cnt2>=sum/3){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
	}
	else{
		cout<<"NO";
	}
}
