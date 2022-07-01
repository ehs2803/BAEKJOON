#include <iostream>
#define MAX 9
using namespace std;

int s[MAX], w[MAX];
int n, answer;

void DFS(int idx) {
    // ����� ó������ ������ ���� ������ ��
    if(idx == n) {
        int cnt = 0;
        // �������� 0�� ���� ã�� ������
        for(int i = 0; i < n; i++) {
            if(s[i] <= 0) cnt++;
        }
        answer = max(answer, cnt);
        return;
    }
    
    // ���� �տ� �� ����� ���� ��� ���� ���
    if(s[idx] <= 0) DFS(idx + 1);
    else {
        bool flag = false; // ����� ������ �Ȳ����� Ȯ��
        for(int i = 0; i < n; i++) {
            if(idx == i || s[i] <= 0) continue; // ���� �տ� �� ��� �Ǵ� �̹� ���� ����� �Ѿ
            s[idx] -= w[i]; // ���� �տ� �� ����� ������
            s[i] -= w[idx]; // ���ݴ��� ���
            flag = true; // ����� ��
            DFS(idx + 1); // ���� ����� ���´�.
            s[i] += w[idx];
            s[idx] += w[i];
        }
        // ���̻� �� ����� ������ �ٷ� n���� �̵�
        if(!flag) DFS(n);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>s[i]>>w[i];
    }
    
    DFS(0);
    
    cout<<answer;
}
