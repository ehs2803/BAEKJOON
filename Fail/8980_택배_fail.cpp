#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int capacity[10001];

bool cmp(pair<pair<int,int>,int>> & a, pair<pair<int,int>,int>> & b){
	if(a.first.first==b.first.first){
		if(a.first.second<b.first.second) return true;
		else return false;
	}
	else if(a.first.first<b.first.first) return true;
	else return false;
}

int main(){
	int n,c;
	cin>>n>>c;
	
	int m;
	cin>>m;
	vector<pair<pair<int,int>,int>> info(m);
	for(int i=0;i<m;i++){
		cin>>info[i].first.first>>info[i].first.second>>info[i].second;
	}
	// 출발지, 도착지로 정렬  
	sort(info.begin(), info.end(), cmp);
	
	int result=0;
	for (int i = 0; i < m; i++) { 
		int from = info[i].first.first; //출발
		int to = info[i].first.second; //도착
		int size = info[i].second; //싣어야할 택배수
		int maxcnt = 0;
		for (int j = from; j < to; j++)  //보내는곳부터 받는곳까지
			maxcnt = max(capacity[j], maxcnt); //capacity의 최대값을 저장합니다. 박스를 얼마나 넣을 수 있는 확인하기 위해

		int val = min(arr[i].cnt, c - maxcnt);
		result += val;
		
		for (int j = from; j < to; j++) {
			capacity[j] += val; // 이동되면서 해당 공간만큼 할당해주어야 박스가 못 실리겠죠
		}
	}
	cout<<result;
}
