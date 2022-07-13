#include<iostream>
#include<vector>
using namespace std;

int n,m;
int map[100][100];

int getDistance(int x, int y){
	int result=0;
	for(int i=1;i<=n;i++){
		result+=min(map[x][i],map[y][i]);
	}	
	return result;
}

int main(){
	cin>>n>>m;
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i==j) continue;	
			map[i][j]=1e9;
		}
	}
	
	for(int i=0;i<m;i++){
		int start, end;
		cin>>start>>end;
		map[start][end]=1;
		map[end][start]=1;		
	}
	
	// 플로이드 와샬 알고리즘
	for(int k=0;k<n;k++) {
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				map[i][j]=min(map[i][j], map[i][k]+map[k][j]);
			}
		}				
	}
	
	int point1=1e9;
	int point2=1e9;
	int minDist=1e9;
		
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			// 2개의 지점을 치킨집으로 선정
			int dis=getDistance(i,j);
			// 최소값 갱신
			if(minDist>dis) {
				point1=i;
				point2=j;
				minDist=dis;
			}
		}
	}
	
	cout<<point1<<' '<<point2<<' '<<minDist*2;
}
