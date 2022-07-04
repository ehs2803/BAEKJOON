#include<iostream>
#include<queue>
using namespace std;

int r,c;
char map[200][200];
int bomb[200][200];
bool IsBomb[200][200];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void printMap(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(IsBomb[i][j]) cout<<'0';
			else cout<<'.';
		}
		cout<<'\n';
	}
}

void setBomb(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(IsBomb[i][j]==false){
				IsBomb[i][j]=true;
				bomb[i][j]=0;
			}
		}
	}
}

void increaseTime(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(IsBomb[i][j]){
				bomb[i][j]++;
			}
		}
	}	
}

void deleteBomb(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(IsBomb[i][j]&&bomb[i][j]>=3){
				bomb[i][j]=0;
				IsBomb[i][j]=false;
				for(int k=0;k<4;k++){
					int nx = i+dx[k];
					int ny = j+dy[k];
					if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
					if(IsBomb[nx][ny]){
						IsBomb[nx][ny]=false;
						bomb[nx][ny]=0;
					}
				}
			}
		}
	}	
}

int main(){
	int n;
	cin>>r>>c>>n;
	// input
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>map[i][j];	
			if(map[i][j]=='.') IsBomb[i][j]=false;
			else IsBomb[i][j]=true;		
		}
	}
	
	int totalTime=1;
	int time=0;
	
	if(n==1){
		printMap();
		exit(0);
	}
	while(true){
		totalTime++;
		time++;
		
		if(time==1){
			increaseTime();
			setBomb();
		}
		else if(time==2){
			increaseTime();
			time=0;
		}
		
		deleteBomb();
		
		if(totalTime==n){
			printMap();
			break;
		}
	}
}
