#include<iostream>
using namespace std;

int col[15];
int n;
int cnt=0;

bool check(int level){
	for(int i = 0; i < level; i++){
		if(col[i] == col[level] || abs(col[level] - col[i]) == level - i){
			return false;
		}
	}
	return true;
}

void nqueen(int index){
	if(index==n) cnt++;
	else{
		for(int i=0;i<n;i++){
			col[index]=i;
			if(check(index)) nqueen(index+1);
		}
	} 
}

int main(){
	cin>>n;
	
	nqueen(0);
	
	cout<<cnt;
	
}
