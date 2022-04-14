#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n; 
	cin>>n;
	
	// 입력 
	vector<int> cards(n);
	for(int i=0;i<n;i++) cin>>cards[i];
	
	// 내림차순 정렬  
	sort(cards.begin(), cards.end(), greater<int>());
	
	int gold=0;
	for(int i=1;i<n;i++){
		gold += cards[0]+cards[i]; // 가장 레벨이 큰 카드는 계속 유지되게 됨. 
	}
	
	// 답 출력  
	cout<<gold;
}
