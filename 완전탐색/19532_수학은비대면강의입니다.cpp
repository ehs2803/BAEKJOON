#include<iostream>
using namespace std;

//�� �� x�� y�� ���� -999 �̻� 999 ������ ������ ��츸 �Է����� �־����� ����
int main(){
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	
	// ����Ž��  
	for(int i=-999;i<1000;i++){
		for(int j=-999; j<1000; j++){
			if(a*i+b*j==c && d*i+e*j==f){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}	
}
