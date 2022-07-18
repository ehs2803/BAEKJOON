#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int paper[101][101];
bool visited[101][101]; // 방문표시
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(int sx, int sy, int m, int n){
	int cnt=0;
	
	queue<pair<int,int>> q;
	q.push({sx, sy});
	visited[sx][sy]=true;
	cnt++;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(0<=nx&&nx<m&& 0<=ny&&ny<n){
				if(visited[nx][ny]) continue;
				if(paper[nx][ny]==1) continue;
				q.push({nx,ny});
				visited[nx][ny]=true;
				cnt++;
			}
		}
	}
	
	return cnt;
}

int main() {
   int M, N, K;
   cin >> M >> N >> K;
   /*int paper1[M][N];*/

   int x1, y1,x2,y2;
   for (int i = 0; i < K; i++) {   
      cin >> x1 >> y1 >> x2 >> y2;
      /*cout << x1 <<  " " <<M - y1 << " " << x2 << " " << M - y2 << "\n";*/
      //cout << M - y1 - 1 << " " << x1 << " " << M - y2 << " " << x2 - 1 << "\n";

      if (x1 == x2 - 1 && M - y1 - 1 == M - y2) {
         paper[M - y1 - 1][x1] = 1;
      }
      else if (x1 == x2 - 1) {
         for (int k = M - y2; k <= M - y1 - 1; k++) {
            paper[k][x1] = 1;
         }
      }
      else if (M - y1 - 1 == M - y2) {
         for (int k = x1; k <= x2 - 1; k++)
            paper[M - y1 - 1][k] = 1;
      }
      else {//둘다 다를때
         for (int k = M - y2; k <= M - y1 - 1; k++) {
            for (int l = x1; l <= x2 - 1; l++) {
               paper[k][l] = 1;
            }
         }
      }   
   }

//   for (int i = 0; i < M; i++) {
//      for (int j = 0; j < N; j++) {
//         cout << paper[i][j];
//      }
//      cout << "\n";
//   }

	int cnt=0;
	vector<int> ans;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(visited[i][j]==false && paper[i][j]==0){
				int temp = bfs(i,j,M,N);
				cnt++;
				ans.push_back(temp);
			}
		}
	}
	
	sort(ans.begin(), ans.end());
	
	cout<<cnt<<'\n';
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<' ';
	}
}

