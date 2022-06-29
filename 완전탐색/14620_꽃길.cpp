#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int map[10][10];
bool check[10][10];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void initCheck(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			check[i][j]=false;
		}
	}
}

bool isAvailable(int x, int y){
	if(check[x][y]==true) return false;
	else{
		check[x][y]=true;
	}
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(check[nx][ny]==true) return false;
		else{
			check[nx][ny]=true;
		}
	}
	return true;
}

int calculateCost(){
	int cost=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(check[i][j]){
				cost+=map[i][j];
			}
		}
	}
	return cost;
}

int main(){
	cin>>n;
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	
	vector<pair<int,int> > matrix;
	
	for(int i=1;i<n-1;i++){
		for(int j=1;j<n-1;j++){
			matrix.push_back({i,j});
		}
	}
	
	const int r = 3;
    
    vector<bool> temp(matrix.size(), false);
    for(int i = 0; i < r; i ++) temp[i] = true;
 
 	int ans=1e9;
 	
    do {
    	initCheck();
    	bool checking=true;
        for (int i = 0; i < temp.size(); ++i) {
            if (temp[i]){
            	int x = matrix[i].first;
            	int y = matrix[i].second;
            	if(isAvailable(x,y)==false){
            		checking=false;
            		break;
				}
			}
        }
        if(checking==true){
        	int cost = calculateCost();
        	if(cost<ans) ans=cost;
		}

    } while (prev_permutation(temp.begin(), temp.end()));
    
    cout<<ans;
}
