#include<iostream>
using namespace std;

//�� ĭ 0, �� 1
//0 ����, 1 ����, 2 ����, 3 ����
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
