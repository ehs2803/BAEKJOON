#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int compare(int i, int j) {
    if (i > j) return true;
    return false;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), compare);

    int max = v[0];
    for (int i = 1; i <= n; i++) {
        if (max < (i * v[i - 1])) max = i * v[i - 1];
    }

    cout << max;
}