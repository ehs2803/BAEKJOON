#include<iostream>
using namespace std;

int map[100][100];

//bool IsFront(int n, int m){
//	bool check=true;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			if(map[i][j]==1){
//				check=false;
//				return check;
//			}
//		}
//	}
//	return check;
//}

void reverse(int n, int m){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			map[i][j]=1-map[i][j];
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp; 
		for(int j=0;j<m;j++){
			map[i][j]=temp[j]-'0';
		}
	}
	
	int ans=0;
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(map[i][j]==1){
				ans++;
				reverse(i,j);
			}	
		}
	}
	
	cout<<ans;
}
