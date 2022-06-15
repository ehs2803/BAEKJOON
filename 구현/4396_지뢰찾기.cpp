#include<iostream>
using namespace std;

int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};

int main(){
	int n;
	cin>>n;
	// 배열 동적할당1 
	char** map = new char*[n]; 
	for(int i=0; i<n; i++) 
		map[i] = new char[n];
	// 배열 동적할당2 
	char** excute = new char*[n]; 
	for(int i=0; i<n; i++) 
		excute[i] = new char[n];
	// 입력 1 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	// 입력 2 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>excute[i][j];
		}
	}
	
	// 정답 배열 동적할당  
	int** ans = new int*[n];
	for(int i=0;i<n;i++)
		ans[i] = new int[n];
		
	bool check=false;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(excute[i][j]=='x'){
				if(map[i][j]=='*') check=true;
				int cnt=0;
				for(int k=0;k<8;k++){
					int nx = i+dx[k];
					int ny = j+dy[k];
					if(0<=nx&&nx<=n-1&&0<=ny&&ny<=n-1){
						if(map[nx][ny]=='*'){
							cnt++;
						}
					}
				}
				ans[i][j]=cnt;
			}
		}
	}
	
	// 답 출력
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(check && map[i][j]=='*'){
				cout<<'*';
			}
			else if(excute[i][j]=='.'){
				cout<<'.';
			}
			else{
				cout<<ans[i][j];
			}
		}
		cout<<'\n';
	} 
}
