#include<iostream>
#include<queue>
using namespace std;

int n;

// �켱���� ť (��������)  
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
	// �Է�  
	cin>>n;
	
	// �Է�  
	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		pq.push(temp);
	}	
	
	// �Է��� �Ѱ��� ��� 
	if(pq.size()==1){
		// �Է��� 1���̸鼭 �Է°��� 1�ΰ��  
		if(pq.top()==1){
			cout<<0;
			return 0;
		}
		
		cout<<pq.size();
		return 0;
	}
	
	int ans=0;
	while(true){
		int x = pq.top(); pq.pop();	
		int y = pq.top(); pq.pop();
		
		ans = ans + (x+y);
		
		if(pq.size()==0) break;
		
		pq.push(x+y);
	}	
	
	// �� ���  
	cout<<ans;
} 
