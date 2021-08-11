#include<iostream>
#include<vector>
#include<algorithm> // min�Լ� ���  

#define INF 2147483647 // int�� �ִ� ���� ��  

using namespace std;

int n,m;
int homeCnt=0, chickenCnt=0;

vector<pair<int, int> > home;
vector<pair<int, int> > chicken;

// ����n�� 2���� 1��Ʈ ���� ��ȯ   
int count_OneBits(int n){
	int cnt_OneBit = 0;
	while(n){
		if(n&1) ++cnt_OneBit;
		n = n >> 1;
	}
	return cnt_OneBit;
}

// ġŲ���� �ִ� M���� ����� ��, ������ ġŲ �Ÿ��� �ּڰ��� ���
int get_distMinimum(){
	int distMinimum = INF;
	for(int set=0; set<1<<chickenCnt; set++){
		if(count_OneBits(set)==m){
			int sum=0;
			for(int i=0; i<homeCnt; i++){
				int dist = INF;
				for(int j=0; j<chickenCnt; j++){
					if(set&1<<j){
						dist = min(dist, 
						abs(home[i].first-chicken[j].first)+abs(home[i].second-chicken[j].second));
					}
				}
				sum += dist; 
			}
			distMinimum = min(distMinimum, sum);
		}
	}
	return distMinimum;
}

int main(){
	// ����� �������� ����. 
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	// �Է�
	cin>>n>>m;

	// �Է� 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int temp; cin>>temp;
			if(temp==1) {
				home.push_back({i,j});
				homeCnt++;	
			}
			else if(temp==2){
				chicken.push_back({i,j});
				chickenCnt++;	
			} 
		}
	}
	
	// �� ���  
	int ans = get_distMinimum();
	cout<<ans;
}


