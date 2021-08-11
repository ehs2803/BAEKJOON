#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M;

int lab[8][8]; // ������   
int tmp[8][8]; // ������ ����  

bool check[8][8]; 

vector<pair<int,int> > zero; // lab��ǥ �� 0�� ��ǥ ����  

// ������ ����  
void copyLab(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) tmp[i][j]=lab[i][j];
	}
}

// ���̷��� ��Ʈ����  
void dfs(int x, int y) {
    // �־��� ������ ����� ��쿡�� ��� ����  
    if (x <= -1 || x >=N || y <= -1 || y >= M)  return;
    // ���� ������ ����  
    if(tmp[x][y]==1) {
    	check[x][y]=true;
    	return;
	}
	 
    if(check[x][y]==true) return; // �̹� üũ�� ��ġ��� ���� 
    
    check[x][y]=true;
    
    // ���� �ƴϸ鼭 ���̷����� ������ ���� �����̶��  
	if(tmp[x][y] == 0) {
        tmp[x][y] = 2; // ���̷��� ��Ʈ����  
    }
    
    // ��, ��, ��, ���� ��ġ�鵵 ��� ��������� ȣ��
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x + 1, y);
    dfs(x, y + 1);
}

// �������� count  
int countSafeZone(){
	int cnt=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
	    	if(tmp[i][j]==0) cnt++;
		}
	}
	return cnt;
}

int main(){
	// ����� �������� ����. 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// �Է�  
	cin>>N>>M;
	
	// �Է�  
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) cin>>lab[i][j];
	}
	
	// '0' ��ǥ zero ���Ϳ� ����  
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(lab[i][j]==0) zero.push_back({i,j});	
		}
	}
	
	// ������ ���� �ڵ�  
	vector<int> ind;
	int k=3;
	for(int i=0; i<k; i++){
		ind.push_back(1);
	}
	for(int i=0; i<zero.size()-k; i++){
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end());
	
	
	int ans=0;	
	do{
		copyLab();
		
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++) check[i][j]=false;
		}
		
		// ����  
		for(int i=0; i<ind.size(); i++){
			if(ind[i] == 1){
				tmp[zero[i].first][zero[i].second]=1;
			}
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(tmp[i][j]==2 && check[i][j]==false) dfs(i,j);
			}
		}
		
		ans = max(ans, countSafeZone());
		
	}while(next_permutation(ind.begin(), ind.end()));		
	
	// ���� ���  
	cout<<ans;
}
