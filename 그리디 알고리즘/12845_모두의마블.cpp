#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n; 
	cin>>n;
	
	// �Է� 
	vector<int> cards(n);
	for(int i=0;i<n;i++) cin>>cards[i];
	
	// �������� ����  
	sort(cards.begin(), cards.end(), greater<int>());
	
	int gold=0;
	for(int i=1;i<n;i++){
		gold += cards[0]+cards[i]; // ���� ������ ū ī��� ��� �����ǰ� ��. 
	}
	
	// �� ���  
	cout<<gold;
}
