#include<iostream>
#include<queue>
using namespace std;

int n,m,h; 
int map[100][100][100];
bool check[100][100][100];

int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dh[]={0,0,0,0,1,-1};

bool checkGrow(){
	bool growCheck=true;
	for(int k=0;k<h;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j][k]==0){
					growCheck=false;
					break;
				}
			}
			if(growCheck==false) break;
		}
		if(growCheck==false) break;
	}	
	return growCheck;
}

void initCheck(){
	for(int k=0;k<h;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				check[i][j][k]=false;
			}
		}
	}	
}

bool bfs(int sx, int sy, int sh){
	bool changeCheck=false;
	
	queue<pair<pair<int,int>,int>> q;
	q.push({{sx,sy}, sh});
	check[sx][sy][sh]=true;
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int h = q.front().second;
		q.pop();
		
		for(int i=0;i<6;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			int nh = h+dh[i];
			
			if(map[nx][ny][nh]==-1 || map[nx][ny][nh]==1) {
				check[nx][ny][nh]=true;
				continue;	
			}
			if(nx<0||ny<0||nh<0||nx>=n||ny>=m||nh>=h) continue;
			if(check[nx][ny][nh]==true) continue;
			
			check[nx][ny][nh]=true;
			map[nx][ny][nh]=1;
			q.push({{nx,ny},nh});
			changeCheck=true;
		}
	}
	return changeCheck;
}

int main(){
	cin>>n>>m>>h;
	
	for(int k=0;k<h;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>map[i][j][h];
			}
		}
	}	
	
	if(checkGrow()){
		cout<<0;
		exit(0);
	}
	
	int day=0;
	while(true){
		day++;
		
		initCheck();
		
		bool faultCheck=true;
		for(int k=0;k<h;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(check[i][j][h]==false && map[i][j][h]==1){
						if(bfs(i,j,k)) faultCheck=false;
					}
				}
			}
		}
		if(faultCheck){
			cout<<-1;
			exit(0);
		}
		if(checkGrow()) break;
	}
	
	cout<<day;
}
