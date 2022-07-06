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
	// �����, �������� ����  
	sort(info.begin(), info.end(), cmp);
	
	int result=0;
	for (int i = 0; i < m; i++) { 
		int from = info[i].first.first; //���
		int to = info[i].first.second; //����
		int size = info[i].second; //�ƾ���� �ù��
		int maxcnt = 0;
		for (int j = from; j < to; j++)  //�����°����� �޴°�����
			maxcnt = max(capacity[j], maxcnt); //capacity�� �ִ밪�� �����մϴ�. �ڽ��� �󸶳� ���� �� �ִ� Ȯ���ϱ� ����

		int val = min(arr[i].cnt, c - maxcnt);
		result += val;
		
		for (int j = from; j < to; j++) {
			capacity[j] += val; // �̵��Ǹ鼭 �ش� ������ŭ �Ҵ����־�� �ڽ��� �� �Ǹ�����
		}
	}
	cout<<result;
}
