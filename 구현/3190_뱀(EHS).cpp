#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, K, L;

int map[101][101]; // ���� �ִ� ��ǥ�� 1, ���� ��ǥ�� 0  

vector<pair<int, int> > apple;
vector<pair<int, char> > command; 

queue<pair<int, int> > searchTail; // ���� ��ǥ�� �˾Ƴ��� ���� ť  

int direction = 0;  // 0: �� 1: �� 2: ��, 3: ��  
int cx=1, cy=1;  // �Ӹ���ǥ  

// ���� ����  
void setDirection(char c){
	if(c=='L'){
		if(direction==0){
			direction=3;
		}
		else if(direction==1){
			direction=2;
		}
		else if(direction==2){
			direction=0;
		}
		else if(direction==3){
			direction=1;
		}
	}
	else if(c=='D'){
		if(direction==0){
			direction=2;
		}
		else if(direction==1){
			direction=3;
		}
		else if(direction==2){
			direction=1;
		}
		else if(direction==3){
			direction=0;
		}
	}
}

// �Ű������� ���� ��ǥ���� ����� �ִ��� ���θ� ��ȯ  
bool IsApple(int x, int y){
	for(int i=0;i<apple.size(); i++){
		if(apple[i].first==x && apple[i].second==y) {
			apple[i].first=-1;
			apple[i].second=-1;
			return true;
		}
	}	
	return false;
} 

// ���� ¥����  
void updateTail(){
	int x = searchTail.front().first;
	int y= searchTail.front().second;
	searchTail.pop();
	map[x][y]=0;
}

int main(){
	// ����� �������� ���� 
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin>>N;
	cin>>K;
	
	// ��� ��ġ��ǥ �Է�  
	for(int i=0;i<K;i++){
		int x,y;
		cin>>x>>y;
		apple.push_back({x,y});
	}
	
	map[1][1]=1;
	searchTail.push({1,1});
	
	// ���ʿ� � �������� ȸ������ �Է�  
	cin>>L;
	for(int i=0; i<L; i++){
		int x; char c;
		cin>>x>>c;
		command.push_back({x,c});  
	}
	
	// 0�ʺ��� 1�ʾ� �÷���  
	int ans=0;
	while(true){
		ans++;
		if(direction==0){
			if(cy+1> N) break;
			if(map[cx][cy+1]) break;
			cy+=1;
 			searchTail.push({cx,cy});
			if(IsApple(cx,cy)) map[cx][cy]=1;
			else{
				map[cx][cy]=1;
				updateTail();
			}
		}
		else if(direction==1){
			if(cy-1< 1) break;
			if(map[cx][cy-1]) break;
			cy-=1;
			searchTail.push({cx,cy});
			if(IsApple(cx,cy)) map[cx][cy]=1;
			else{
				map[cx][cy]=1;
				updateTail();
			}
		}
		else if(direction==2){
			if(cx+1> N) break;
			if(map[cx+1][cy]) break;
			cx+=1;
			searchTail.push({cx,cy});
			if(IsApple(cx,cy)) map[cx][cy]=1;
			else{
				map[cx][cy]=1;
				updateTail();
			}
		}
		else{
			if(cx-1< 1) break;
			if(map[cx-1][cy]) break;
			cx-=1;
			searchTail.push({cx,cy});
			if(IsApple(cx,cy)) map[cx][cy]=1;
			else{
				map[cx][cy]=1;
				updateTail();
			}
		}
		if(command.size()!=0){
			if(command[0].first==ans){
				setDirection(command[0].second);
				command.erase(command.begin());
			}  	
		}
	}
	
	// �� ���  
	cout<<ans;
}
