#include<algorithm>
#include<iostream>
using namespace std;
 
bool check[8]; // �ߺ��� ���� ���� �ʱ� ���� �迭
int n, m, num[8], result[8];
 
void getResult(int count, int start) {
 
    if (count == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    // prev_num�� ������ ����� ���� ����
    int prev_num = -1;
    // �Լ��� ��� ȣ���� ������� ���� ������ �Ǹ�
    // for�� �ȿ��� ���� ���� ���� �Ǵµ� �� �� prev_num�� ����� ���� ���� �ʱ� ����
    for (int i = start; i < n; i++) {
        // ������ ����� ���� �ƴϰ� �̹� �� ���� �ƴ϶��
        if (!check[i] && prev_num != num[i]) {
            check[i] = true;          // ����ְ�
            result[count] = num[i];   // �迭�� �ְ�
            prev_num = num[i];        // ������ �� ���� ����
            getResult(count + 1, i+1);     // ���� ���� ���� ���ϴ�
            check[i] = false;
        }
    }
}
 
int main(void) {
 
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    // ������������ ����
    sort(num, num + n);
 
    getResult(0,0);
    return 0;
}
