#include<iostream>
using namespace std;

int main(){
	string content, search;
	
	cin>>content>>search;
	
	// �Է� ���� ���ڿ����� �����ڸ� �̾� ���ο� ���ڿ� �����  
	string str="";
	for(int i=0;i<content.size();i++){
		if(('a'<=content[i]&&content[i]<='z')||('A'<=content[i]&&content[i]<='Z')){
			str+=content[i];
		}
	}
	
	// find �޼ҵ� �̿��� ���ڿ��� ������ 1 ���  
	if(str.find(search)!= string::npos){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
