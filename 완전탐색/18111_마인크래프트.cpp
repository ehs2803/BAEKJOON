#include<iostream>
#include<vector>
using namespace std;

int map[500][500];

int main(){
	int n,m,b;
	cin>>n>>m>>b;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int temp;
			cin>>temp;
			map[i][j]=temp;
		}
	}
	
	int ans_cost=1e9;
	int ans_heigth;
	// dig 2sec, build 1sec
	for(int h=0; h<=256; h++){
		int temp_ans=0;
		int clone_b = b;
		bool check=false;
		bool checkAct[500][500];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				checkAct[i][j]=false;
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0;j<m;j++){
				if(h==map[i][j]){
					checkAct[i][j]=true;
				}
				else if(h<map[i][j]){ // dig
					int cnt = map[i][j]-h;
					temp_ans+=(2*cnt);
					clone_b+=cnt;
					checkAct[i][j]=true;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(checkAct[i][j]==false){
					checkAct[i][j]=true;
					int cnt=h-map[i][j];
					if(clone_b<cnt){
						check=true;
						break;
					}
					temp_ans+=cnt;
					clone_b-=cnt;
				}
			}
			if(check) break;
		}
		if(check==false && temp_ans<=ans_cost) {
			ans_cost=temp_ans;
			ans_heigth=h;
		}
	}
	
	cout<<ans_cost<<' '<<ans_heigth;
}
