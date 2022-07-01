#include <iostream>
#define MAX 9
using namespace std;

int s[MAX], w[MAX];
int n, answer;

void DFS(int idx) {
    // 계란을 처음부터 끝까지 전부 집었을 때
    if(idx == n) {
        int cnt = 0;
        // 내구도가 0인 것을 찾아 더해줌
        for(int i = 0; i < n; i++) {
            if(s[i] <= 0) cnt++;
        }
        answer = max(answer, cnt);
        return;
    }
    
    // 현재 손에 든 계란이 깨진 경우 다음 계란
    if(s[idx] <= 0) DFS(idx + 1);
    else {
        bool flag = false; // 계란을 깼는지 안깼는지 확인
        for(int i = 0; i < n; i++) {
            if(idx == i || s[i] <= 0) continue; // 현재 손에 든 계란 또는 이미 깨진 계란은 넘어감
            s[idx] -= w[i]; // 현재 손에 든 계란의 내구도
            s[i] -= w[idx]; // 공격당한 계란
            flag = true; // 계란을 깸
            DFS(idx + 1); // 다음 계란을 집는다.
            s[i] += w[idx];
            s[idx] += w[i];
        }
        // 더이상 깰 계란이 없으면 바로 n으로 이동
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
