#include<algorithm>
#include<iostream>
using namespace std;

int n, m, num[8], result[8];
 
void getResult(int count) {
 
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
    for (int i = 0; i < n; i++) {
        // ������ ����� ���� �ƴϰ� �̹� �� ���� �ƴ϶��
        if (prev_num != num[i]) {
            result[count] = num[i];   // �迭�� �ְ�
            prev_num = num[i];        // ������ �� ���� ����
            getResult(count + 1);     // ���� ���� ���� ���ϴ�
        }
    }
}
 
int main(void) {
 
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    // ������������ ����
    sort(num, num + n);
 
    getResult(0);
    return 0;
}
