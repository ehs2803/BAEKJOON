#include<iostream>
#include<algorithm>
using namespace std;

long long card[100000];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> card[i];

    sort(card, card + n);

    int maxIndex = 0, max = 1, cnt = 1;
    for (int i = 1; i < n; i++) {
        if (card[i] == card[i - 1]) {
            cnt++;
            if (max < cnt) {
                max = cnt;
                maxIndex = i;
            }
        }
        else {
            cnt = 1;
        }
    }

    cout << card[maxIndex];
}