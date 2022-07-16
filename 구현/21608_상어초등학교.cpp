#include<iostream>
using namespace std;

struct Friend{
	int num;
	int f1,f2,f3,f4;	
};

int map[20][20];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool IsLocate(int n, int r, int c, int & fCnt, int & bCnt, int f1, int f2, int f3, int f4){
	int temp_fcnt=0, temp_bcnt=0;
	
	for(int i=0;i<4;i++){
		int nx = r+dx[i];
		int ny = c+dy[i];
		if(0<=nx&&nx<n && 0<=ny&&ny<n){
			if(map[nx][ny]==f1||map[nx][ny]==f2||map[nx][ny]==f3||map[nx][ny]==f4){
				temp_fcnt++;
			}
			if(map[nx][ny]==0||map[nx][ny]==0||map[nx][ny]==0||map[nx][ny]==0){
				temp_bcnt++;
			}
		}
	}
	
	if(temp_fcnt>fCnt){
		fCnt=temp_fcnt;
		bCnt=temp_bcnt;
		return true;
	}
	else if(temp_fcnt==fCnt){
		if(temp_bcnt>bCnt){
			bCnt=temp_bcnt;
			return true;
		}
	}
	return false;
}

int getSatify(int n, int r, int c, int f1, int f2, int f3, int f4){
	int satify=0;
	for(int i=0;i<4;i++){
		int nx = r+dx[i];
		int ny = c+dy[i];
		if(0<=nx&&nx<n && 0<=ny&&ny<n){
			if(map[nx][ny]==f1||map[nx][ny]==f2||map[nx][ny]==f3||map[nx][ny]==f4){
				satify++;	
			}
		}
	}	
	if(satify==0) return 0;
	else if(satify==1) return 1;
	else if(satify==2) return 10;
	else if(satify==3) return 100;
	else return 1000;
}

int main(){
	int n;
	cin>>n;
	
	Friend * fs = new Friend[n*n];
	
	for(int i=0;i<n*n;i++){
		cin>>fs[i].num>>fs[i].f1>>fs[i].f2>>fs[i].f3>>fs[i].f4;
	}
	
	for(int i=0;i<n*n;i++){
		int num = fs[i].num;
		int f1=fs[i].f1, f2=fs[i].f2, f3=fs[i].f3, f4=fs[i].f4;
		int x=0,y=0;
		int fCnt=0, bCnt=0;
		bool check_first=true;
		
		for(int r=0; r<n; r++){
			for(int c=0; c<n; c++){
				if(map[r][c]==0){
					if(check_first){
						x=r;
						y=c;
						check_first=false;
					}
					if(IsLocate(n,r,c,fCnt,bCnt,f1,f2,f3,f4)){
						x=r;
						y=c;
					}
				}
				

			}
		}
		map[x][y]=num;
	}
	
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<map[i][j]<<' ';
//		}
//		cout<<endl;
//	}

	int ans=0;
	for(int i=0;i<n*n;i++){
		int num = fs[i].num;
		int f1=fs[i].f1, f2=fs[i].f2, f3=fs[i].f3, f4=fs[i].f4;
		
		for(int r=0;r<n;r++){
			for(int c=0;c<n;c++){
				if(map[r][c]==num){
					ans+=getSatify(n,r,c,f1,f2,f3,f4);
					break;
				}
			}
		}
	}	
	
	cout<<ans;
}
