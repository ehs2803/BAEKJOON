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
    // prev_num에 직전에 골랐던 수를 저장
    int prev_num = -1;
    // 함수의 재귀 호출이 출력으로 인해 끝나게 되면
    // for문 안에서 다음 수를 고르게 되는데 그 때 prev_num에 저장된 수를 고르지 않기 위함
    for (int i = 0; i < n; i++) {
        // 직전에 골랐던 수가 아니고 이미 고른 수가 아니라면
        if (prev_num != num[i]) {
            result[count] = num[i];   // 배열에 넣고
            prev_num = num[i];        // 직전에 고른 수에 저장
            getResult(count + 1);     // 다음 수를 고르러 갑니다
        }
    }
}
 
int main(void) {
 
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    // 오름차순으로 정렬
    sort(num, num + n);
 
    getResult(0);
    return 0;
}
