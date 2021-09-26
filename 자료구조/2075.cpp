#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    priority_queue< int, vector<int>, greater<int> > q; // min heap

    for (int i = 0; i < n * n; i++) {
        int temp; cin >> temp;
        q.push(temp);
        if (q.size() == n + 1) q.pop();
    }

    cout << q.top();
}