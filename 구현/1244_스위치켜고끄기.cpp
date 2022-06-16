#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	// 전구 상태 입력  
	vector<int> light(n+1);
	for(int i=1;i<=n;i++){
		cin>>light[i];
	}
	
	int m;
	cin>>m;
	// 성별, 학생이 받은 수 입력  
	vector<pair<int,int> > v(m);
	for(int i=0;i<m;i++){
		cin>>v[i].first>>v[i].second;
	}
	
	for(int i=0;i<m;i++){
		int number = v[i].second;
		if(v[i].first==1){ // men
			for(int k=1;k<=n;k++){
				if(k%number==0){
					if(light[k]==1) light[k]=0;
					else light[k]=1;
				}
			}
		}
		else{ // women
			int cnt=0;
			int sub=1;
			while(true){
				int pre = number-sub;
				int next = number+sub;
				if(pre<=0 || next>n){
					break;
				}
				if(light[pre]!=light[next]){
					break;
				}
				sub++;
				cnt++;
			}
			if(light[number]==0) light[number]=1;
			else light[number]=0;
			if(cnt>0){
				for(int k=1;k<=cnt;k++){
					if(light[number-k]==0) light[number-k]=1;
					else light[number-k]=0;
					if(light[number+k]==0) light[number+k]=1;
					else light[number+k]=0;
				}
			}
		}
	}
	
	// 답 출력
	for(int i=1;i<=n;i++){
		cout<<light[i]<<' ';
		if(i%20==0) cout<<'\n';
	} 
}
