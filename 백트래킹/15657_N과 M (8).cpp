#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
const int MAX = 8;
int N, M;
vector<int> list;
vector<int> ans;
 
void print() {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
 
void DFS(int cnt, int start) {
    if (cnt == M) {
        print();
        return;
    }
    for (int i = start; i < N; i++) {
        ans.push_back(list[i]);
        DFS(cnt + 1, i);
        ans.pop_back();
    }
}
 
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        list.push_back(n);
    }
 
    sort(list.begin(), list.end());
 
    DFS(0,0);
 
    return 0;
}

