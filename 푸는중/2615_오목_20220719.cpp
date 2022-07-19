#include<iostream>
using namespace std;

int map[19][19];

int dx[]={0,1,1,-1};
int dy[]={1,0,1,1};

bool IsWinner(int sx, int sy, int & wx, int & wy){
	int standard = map[sx][sy];
	
	bool check=true;
	
	int cloneX=sx, cloneY=sy;
	for(int i=0;i<4;i++){
		cloneX+=dx[0];
		cloneY+=dy[0];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]!=standard){
				check=false;
				break;
			}
		}
		else{
			check=false;
			break;
		}
	}
	if(check){
		wx=sx;
		wy=sy;
		cloneX+=dx[0];
		cloneY+=dy[0];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]==standard){
				check=false;
			}
		}
		cloneX=sx;
		cloneY=sy;
		cloneX-=dx[0];
		cloneY-=dy[0];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]==standard){
				check=false;
			}
		}	
	}
	if(check) return true;	
	
	
	
	check=true;
	cloneX=sx, cloneY=sy;
	for(int i=0;i<4;i++){
		cloneX+=dx[1];
		cloneY+=dy[1];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]!=standard){
				check=false;
				break;
			}
		}
		else{
			check=false;
			break;
		}
	}
	if(check){
		wx=sx;
		wy=sy;
		cloneX+=dx[1];
		cloneY+=dy[1];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]==standard){
				check=false;
			}
		}	
		cloneX=sx;
		cloneY=sy;
		cloneX-=dx[1];
		cloneY-=dy[1];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]==standard){
				check=false;
			}
		}
	}
	if(check) return true;
	
	check=true;
	cloneX=sx, cloneY=sy;
	for(int i=0;i<4;i++){
		cloneX+=dx[2];
		cloneY+=dy[2];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]!=standard){
				check=false;
				break;
			}
		}
		else{
			check=false;
			break;
		}
	}
	if(check){
		wx=sx;
		wy=sy;
		cloneX+=dx[2];
		cloneY+=dy[2];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]==standard){
				check=false;
			}
		}
		cloneX=sx;
		cloneY=sy;
		cloneX-=dx[2];
		cloneY-=dy[2];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]==standard){
				check=false;
			}
		}
	}
	
	check=true;
	cloneX=sx, cloneY=sy;
	for(int i=0;i<4;i++){
		cloneX+=dx[3];
		cloneY+=dy[3];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]!=standard){
				check=false;
				break;
			}
		}
		else{
			check=false;
			break;
		}
	}
	if(check){
		wx=sx;
		wy=sy;
		cloneX+=dx[3];
		cloneY+=dy[3];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]==standard){
				check=false;
			}
		}
		cloneX=sx;
		cloneY=sy;
		cloneX-=dx[3];
		cloneY-=dy[3];
		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
			if(map[cloneX][cloneY]==standard){
				check=false;
			}
		}
	}
	
	if(check) return true;
	else return false;
}

int main(){
	for(int i=0;i<19;i++){
		for(int j=0;j<19;j++){
			cin>>map[i][j];
		}
	}
	
	int winner=-1;
	int wx, wy;
	bool check=false;
	for(int i=0;i<19;i++){
		for(int j=0;j<19;j++){
			if(map[i][j]==1 || map[i][j]==2){
				if(IsWinner(i,j,wx,wy)){
					check=true;
					winner=map[i][j];
					//wx=i;
					//wy=j;
					break;
				}
			}
		}
		if(check) break;
	}
	
	if(check){
		cout<<winner<<'\n';
		cout<<wx+1<<' '<<wy+1;
	}
	else{
		cout<<0;
	}
} 
// 5% ¿À·ù  
//#include<iostream>
//using namespace std;
//
//int map[19][19];
//
//int dx[]={0,1,1,-1};
//int dy[]={1,0,1,1};
//
//bool IsWinner(int sx, int sy, int & wx, int & wy){
//	int standard = map[sx][sy];
//	
//	bool check=true;
//	
//	int cloneX=sx, cloneY=sy;
//	for(int i=0;i<4;i++){
//		cloneX+=dx[0];
//		cloneY+=dy[0];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]!=standard){
//				check=false;
//				break;
//			}
//		}
//		else{
//			check=false;
//			break;
//		}
//	}
//	if(check){
//		wx=sx;
//		wy=sy;
//		cloneX+=dx[0];
//		cloneY+=dy[0];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]==standard){
//				check=false;
//			}
//		}
//		cloneX=sx;
//		cloneY=sy;
//		cloneX-=dx[0];
//		cloneY-=dy[0];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]==standard){
//				check=false;
//			}
//		}	
//	}
//	if(check) return true;	
//	
//	
//	
//	check=true;
//	cloneX=sx, cloneY=sy;
//	for(int i=0;i<4;i++){
//		cloneX+=dx[1];
//		cloneY+=dy[1];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]!=standard){
//				check=false;
//				break;
//			}
//		}
//		else{
//			check=false;
//			break;
//		}
//	}
//	if(check){
//		wx=sx;
//		wy=sy;
//		cloneX+=dx[1];
//		cloneY+=dy[1];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]==standard){
//				check=false;
//			}
//		}	
//		cloneX=sx;
//		cloneY=sy;
//		cloneX-=dx[1];
//		cloneY-=dy[1];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]==standard){
//				check=false;
//			}
//		}
//	}
//	if(check) return true;
//	
//	check=true;
//	cloneX=sx, cloneY=sy;
//	for(int i=0;i<4;i++){
//		cloneX+=dx[2];
//		cloneY+=dy[2];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]!=standard){
//				check=false;
//				break;
//			}
//		}
//		else{
//			check=false;
//			break;
//		}
//	}
//	if(check){
//		wx=sx;
//		wy=sy;
//		cloneX+=dx[2];
//		cloneY+=dy[2];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]==standard){
//				check=false;
//			}
//		}
//		cloneX=sx;
//		cloneY=sy;
//		cloneX-=dx[2];
//		cloneY-=dy[2];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]==standard){
//				check=false;
//			}
//		}
//	}
//	
//	check=true;
//	cloneX=sx, cloneY=sy;
//	for(int i=0;i<4;i++){
//		cloneX+=dx[3];
//		cloneY+=dy[3];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]!=standard){
//				check=false;
//				break;
//			}
//		}
//		else{
//			check=false;
//			break;
//		}
//	}
//	if(check){
//		wx=cloneX;
//		wy=cloneY;
//		cloneX+=dx[3];
//		cloneY+=dy[3];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]==standard){
//				check=false;
//			}
//		}
//		cloneX=sx;
//		cloneY=sy;
//		cloneX-=dx[3];
//		cloneY-=dy[3];
//		if(0<=cloneX&&cloneX<19 && 0<=cloneY&&cloneY<19){
//			if(map[cloneX][cloneY]==standard){
//				check=false;
//			}
//		}
//	}
//	
//	if(check) return true;
//	else return false;
//}
//
//int main(){
//	for(int i=0;i<19;i++){
//		for(int j=0;j<19;j++){
//			cin>>map[i][j];
//		}
//	}
//	
//	int winner=-1;
//	int wx, wy;
//	bool check=false;
//	for(int i=0;i<19;i++){
//		for(int j=0;j<19;j++){
//			if(map[i][j]==1 || map[i][j]==2){
//				if(IsWinner(i,j,wx,wy)){
//					check=true;
//					winner=map[i][j];
//					//wx=i;
//					//wy=j;
//					break;
//				}
//			}
//		}
//		if(check) break;
//	}
//	
//	if(check){
//		cout<<winner<<'\n';
//		cout<<wx+1<<' '<<wy+1;
//	}
//	else{
//		cout<<0;
//	}
//} 
