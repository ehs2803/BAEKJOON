#include<iostream>
#include<queue>
#include<vector>
#include<algorithm> // abs �Լ� ���  
using namespace std;

int N, L, R;

int map[50][50];    // �α� ��  
bool check[50][50]; // �α��̵�(����)  ���� Ȯ�� (�̵� �� true) 

// �̵��� �� ���� ���� ���� (��, ��, ��, ��) 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int inx, int iny) {	
    int cnt=0; // �Ѱ��� ������ �̷��  ���� ����  
    
    queue<pair<int, int> > q; // bfs�� ���� queue  
	vector<pair<int,int> > v; // ���� ���� ���� vector 
	
    q.push({inx, iny});
    v.push_back({inx,iny});
    check[inx][iny]=true;
    cnt++;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // ��,��,��,�Ͽ� ���ؼ� Ȯ��  
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // �־��� �� ũ�⸦ ��� ���  
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            
            // �̹� �α��̵��� �Ͼ ������ ���  
            if(check[nx][ny]==true) continue;
            
            // �α��� ���̰� L�� R ���� ���̶�� �α��̵�  
            int temp = abs(map[x][y]-map[nx][ny]);
            if (L<=temp && temp<=R) {
                q.push({nx, ny});
                v.push_back({nx,ny});
                check[nx][ny]=true;
                cnt++;
            } 
        } 
    }
    
    // �α��̵��� �Ͼ ������ڰ� 1�� ��, �� �α��̵��� �Ͼ�� �������  
    if(cnt==1) {
    	check[v[0].first][v[0].second]=false;
		v.clear();
		return; 	
	}
	
	// �α��̵��ϴ� ��� ������ �α� �� �հ� ���ϱ�  
    int sum=0;
    for(int i=0; i<v.size(); i++){
    	sum+=map[v[i].first][v[i].second];
	}
	
	// (������ �α���) / (������ �̷�� �ִ� ĭ�� ����) ���ϱ�  
	sum = sum/cnt;
	
	// ������ ���� ������ ���� ���� �α��� �ʱ�ȭ  
	for(int i=0; i<v.size(); i++){
    	map[v[i].first][v[i].second]=sum;
	}

}

int main(){
	// ����� �������� ����. 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // �Է�  
    cin>>N>>L>>R;
	
	// �α� �� �Է�  
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cin>>map[i][j];
	}
	
	
	int ans=0; 
	while(true){
		
		// check �迭 ��� false�� �ʱ�ȭ  
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++) check[i][j]=false;
		}
	
		// ��� ��ǥ�� ���ؼ� bfs�� ���漱 ����  
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(check[i][j]==false) bfs(i,j);
			}		
		}
		
		// ������  �߻����� ������ �ݺ��� ��������  
		bool ch = false;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(check[i][j]==true){
				    ch=true;
					break;	
				}
			}		
		}
		if(ch==false) break;
		
		ans++; // 1�� ����  	
	}
	
	// �� ���  
	cout<<ans;
}
