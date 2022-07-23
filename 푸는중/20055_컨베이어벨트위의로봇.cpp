#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,k;
int belt[2][100];
int beltRobot[2][100];
int beltRobotSeq[2][100];

int seq=1;
vector<int> seqList;

void downRobot();

void printBelt(){
	for(int i=0;i<n;i++){
		cout<<belt[0][i]<<' ';
	}
	cout<<'\n';
	for(int i=0;i<n;i++){
		cout<<belt[1][i]<<' ';
	}
	cout<<'\n';cout<<'\n';
}

void turnBelt(){
	int fRowIdxN = belt[0][n-1];
	int fRowIdxN_Robot = beltRobot[0][n-1];
	int fRowInxN_RobotSeq = beltRobotSeq[0][n-1];
	for(int i=n-2;i>=0;i--){
		belt[0][i+1]=belt[0][i];
		beltRobot[0][i+1]=beltRobot[0][i];
		beltRobotSeq[0][i+1]=beltRobotSeq[0][i];
	}
	belt[0][0]=belt[1][0];
	beltRobot[0][0]=beltRobot[1][0];
	beltRobotSeq[0][0]=beltRobotSeq[1][0];
	for(int i=1;i<n;i++){
		belt[1][i-1]=belt[1][i];
		beltRobot[1][i-1]=beltRobot[1][i];
		beltRobotSeq[1][i-1]=beltRobotSeq[1][i];
	}
	belt[1][n-1]=fRowIdxN;
	beltRobot[1][n-1]=fRowIdxN_Robot;
	beltRobotSeq[1][n-1]=fRowInxN_RobotSeq;
}

void moveRobot(){
	sort(seqList.begin(), seqList.end());
	for(int s=0;s<seqList.size();s++){
		bool check=false;
		for(int i=0;i<n;i++){
			if(beltRobotSeq[0][i]==seqList[s]){
				check=true;
				if(i==n-1){
					if(beltRobot[1][n-1]==0 && belt[1][n-1]>0){
						beltRobot[1][n-1]=1;
						beltRobotSeq[1][n-1]=beltRobotSeq[0][i];
						belt[1][n-1]--;
						
						beltRobot[0][i]=0;
						beltRobotSeq[0][i]=0;
					}
				}
				else{
					if(beltRobot[0][i+1]==0 && belt[0][i+1]>0){
						beltRobot[0][i+1]=1;
						beltRobotSeq[0][i+1]=beltRobotSeq[0][i];
						belt[0][i+1]--;
						
						beltRobot[0][i]=0;
						beltRobotSeq[0][i]=0;
					}
				}
				downRobot();
				break;
			}
		}
		if(check) continue;
		for(int i=0;i<n;i++){
			if(beltRobotSeq[1][i]==seqList[s]){
				check=true;
				if(i==0){
					if(beltRobot[0][0]==0 && belt[0][0]>0){
						beltRobot[0][0]=1;
						beltRobotSeq[0][0]=beltRobotSeq[1][i];
						belt[0][0]--;
						
						beltRobot[1][i]=0;
						beltRobotSeq[1][i]=0;
					}
				}
				else{
					if(beltRobot[1][i-1]==0 && belt[1][i-1]>0){
						beltRobot[1][i-1]=1;
						beltRobotSeq[1][i-1]=beltRobotSeq[1][i];
						belt[1][i-1]--;
						
						beltRobot[1][i]=0;
						beltRobotSeq[1][i]=0;
					}
				}
				downRobot();
				break;
			}
		}
	}
} 

void upRobot(){
	if(belt[0][0]>0 && beltRobot[0][0]==0){
		beltRobot[0][0]=1;
		belt[0][0]--;
	}
	beltRobotSeq[0][0]=seq;
	seqList.push_back(seq);
	seq++;
}

void deleteRobotSeq(int element){
	for(int i=0;i<seqList.size();i++){
		if(seqList[i]==element){
			seqList.erase(seqList.begin()+i);
			break;
		}
	}
}

void downRobot(){
	if(beltRobot[0][n-1]==1){
		beltRobot[0][n-1]=0;
		int robotSeq=beltRobotSeq[0][n-1];
		deleteRobotSeq(robotSeq);
		beltRobotSeq[0][n-1]=0;
	}
}

int getDurabilityZeroCnt(){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(belt[0][i]==0) cnt++;
		if(belt[1][i]==0) cnt++;
	}
	return cnt;
}

int main(){
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		cin>>belt[0][i];
	}
	for(int i=n-1;i>=0;i--){
		cin>>belt[1][i];
	}

	
	int ans_step=0;
	while(true){
		ans_step++;
		
		turnBelt(); 
		
		downRobot();
		
		moveRobot(); 
		
		upRobot();
		
		printBelt();
		
		if(getDurabilityZeroCnt()>=k){
			break;
		}
	}
	//cout<< getDurabilityZeroCnt()<<endl;
	cout<<ans_step;
}




