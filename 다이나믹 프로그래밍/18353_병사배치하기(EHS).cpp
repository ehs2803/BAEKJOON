#include<iostream>
using namespace std;

int n;
int a[2001];
int d[2001];

int main(){
	// �Է�  
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	// ���� �� �����ϴ� ���� ���ϱ� 
	for(int i=1;i<=n;i++){
        d[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]>a[i] && d[i]<d[j]+1)
                d[i]=d[j]+1;
        }
    }
    
    // ���� �� �����ϴ� ���� ���ϱ�  
    int max=d[1];
    for(int i=1;i<=n;i++)
		if(max<d[i]) max=d[i];
	
	// �� ���  
	cout<<n-max;	
}
