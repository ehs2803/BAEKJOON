#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    int cnt = 0;
    cout << "<";
    while (true) {
        cnt++;
        if (q.size() == 1) {
            cout << q.front();
            break;
        }
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();

        if (q.empty()) break;
    }
    cout << ">";
}
