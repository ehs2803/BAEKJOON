#include<iostream>
using namespace std;

//后 沫 0, 寒 1
//0 合率, 1 悼率, 2 巢率, 3 辑率
int map[50][50];

int turn(int direction, char c){
	if(c=='L') direction = (direction==0)?3:diercitn-1;
	else direction = (direction+1)%4;
	return direction;
}

int main(){
	int n,m;
	cin>>n>>m;
	
	int r,c,d;
	cin>>r>>c>>d;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	
	while(true){
		
	}
	
	
}
