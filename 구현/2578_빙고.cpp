#include<iostream>
using namespace std;

int map[5][5];
bool check[5][5];

// 빙고인지 확인  
bool IsBingo(){
	int cnt=0;
	for(int i=0;i<5;i++){
		bool bingocheck=true;
		for(int j=0;j<5;j++){
			if(check[i][j]==false){
				bingocheck=false;
				break;
			}
		}
		if(bingocheck) cnt++;
	}
	
	for(int i=0;i<5;i++){
		bool bingocheck=true;
		for(int j=0;j<5;j++){
			if(check[j][i]==false){
				bingocheck=false;
				break;
			}
		}
		if(bingocheck) cnt++;
	}
	
	bool bingocheck=true;
	for(int i=0;i<5;i++){
		if(check[i][i]==false){
			bingocheck=false;
			break;
		}
	}
	if(bingocheck) cnt++;
	
	if(check[4][0]&&check[3][1]&&check[2][2]&&check[1][3]&&check[0][4]){
		cnt++;
	}
	
	if(cnt>=3) return true;
	else return false;
}

// 사회자가 부른 number check 
void checkNumberInMap(int number){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(map[i][j]==number){
				check[i][j]=true;
				return;
			}
		}
	}
}

int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>map[i][j];
		}
	}
	
	int ans=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			int num;
			cin>>num;
			checkNumberInMap(num);
			ans++;
			if(IsBingo()){
				cout<<ans;
				return 0;
			}
		}
	}
}
