#include<iostream>
#include<deque>
using namespace std;

int main() {
    int n; cin >> n;
    deque<pair<int, int> > dq;

    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        dq.push_back({ temp,i + 1 });
    }

    while (!dq.empty()) {
        int temp = dq.front().first;
        int index = dq.front().second;
        dq.pop_front();
        cout << index << ' ';
        if (dq.size() != 0) {
            if (temp > 0) {
                for (int i = 0; i < temp - 1; i++) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            }
            else {
                temp = -temp;
                for (int i = 0; i < temp; i++) {
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
            }
        }
    }
}