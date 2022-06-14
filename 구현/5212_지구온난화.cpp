#include<iostream>
using namespace std;

char map[10][10];
char map_clone[10][10];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
	int r,c;
	cin>>r>>c;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			char temp;
			cin>>temp;
			map[i][j]=temp;
			map_clone[i][j]=temp;
		}
	}
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(map[i][j]=='X'){
				int cnt=0;
				for(int k=0;k<4;k++){
					int nx = i+dx[k];
					int ny = j+dy[k];
					if(0<=nx&&nx<=r-1&&0<=ny&&ny<=c-1){
						if(map[nx][ny]=='.'){
							cnt++;
						}
					}
					else{
						cnt++;
					}
				}
				if(cnt==3 || cnt==4){
					map_clone[i][j]='.';
				}
			}
		}
	}
	/*
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<map_clone[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	
	int lx=r-1, ly=c-1, rx=0, ry=0;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(map_clone[i][j]=='X'){
				if(i>=rx) rx=i;
				if(i<=lx) lx=i;
				if(j>=ry) ry=j;
				if(j<=ly) ly=j;
			}
		}
	}
	
	//cout<<lx<<' '<<ly<<' '<<rx<<' '<<ry<<endl;
	
	for(int i=lx;i<=rx;i++){
		for(int j=ly; j<=ry; j++){
			cout<<map_clone[i][j];
		}
		cout<<'\n';
	}
}
