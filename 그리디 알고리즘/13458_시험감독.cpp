#include<iostream>
#include<vector> 
using namespace std;

int main(){
	int n; cin>>n;
	vector<int> people(n);
	for(int i=0;i<n;i++) cin>>people[i];
	
	int B,C; 
	cin>>B>>C;
	
	long long ans=n; // n�� ���ǿ� �Ѱ����� ��ġ  
	for(int i=0;i<people.size();i++){
		people[i]-=B; // �Ѱ����� 1�� ��ġ�� ���� ����  
		if(people[i]<=0) continue; // ���� ������� �л����� 0�����϶�� �ΰ����� �ʿ� x 
		else{
			int mod = people[i]%C; 
			ans+=people[i]/C; // �ΰ����� ��ġ  
			if(mod!=0) ans+=1; // �������� �ִٸ� �ΰ����� 1�� �߰��� ��ġ  
		}
	}
	
	// �� ���  
	cout<<ans;
}
