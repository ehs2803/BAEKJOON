#include<iostream>
using namespace std;

int n;

int a[501][501];
int d[501][501];

int main(){
	// �Է�  
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) cin>>a[i][j];
    }
    
    // ���̳��� ���α׷���  
    d[1][1] = a[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            d[i][j]=d[i-1][j];
            if(d[i][j]<d[i-1][j-1]) d[i][j]=d[i-1][j-1];
            d[i][j]+=a[i][j];
        }
    }
    
    // ���� �Ʒ��� �߿��� �ִ��� �������� ����  
    int ans=d[n][1];
    for(int i=1;i<=n;i++){
        if(ans<d[n][i]) ans=d[n][i];
    }
    
    // �� ���  
    cout<<ans;
}
