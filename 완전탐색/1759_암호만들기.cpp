#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int L,C;
char input[15], pwd[15];

// �������� ���� Ȯ��  
bool IsVowel(char c){
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
	else return false;
}

// �ּ� �� ���� ����(vowel)(a, e, i, o, u)�� �ּ� �� ���� ����(consonant) 
void makePassword(int len, int prev, int vowel, int consonant){
	// ��A��ȣ�� �ϼ�... 
	if(len==L){
		if(vowel>=1 && consonant>=2){ // ���� �Ѱ�, ���� �ΰ��̻��� ���  
			for(int i=0;i<L;i++) cout<<pwd[i]; // �� ���  
			cout<<'\n';
			return;
		}
	}
	
	// ���ĵ� ���ĺ� �Ѱ���...
	for(int i=prev+1; i<C; i++){
		char now = input[i]; // ���ĺ� ����  
		pwd[len] = now;
		if(IsVowel(now)) makePassword(len+1, i, vowel+1, consonant); // ������ ��� 
		else makePassword(len+1, i, vowel, consonant+1); // ������ ���  
	} 
	
}

int main(){
	cin>>L>>C;
	
	// �Է�  
	for(int i=0;i<C;i++) cin>>input[i];
	
	// ���ĺ� ���������� ����  
	sort(input, input+C);
	
	// ��й�ȣ �����  
	makePassword(0,-1,0,0);
}
