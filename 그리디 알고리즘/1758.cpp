#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

bool cmp(int i, int j) {
    if (i > j)return true;
    else return false;
}

int main() {
    int n; cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n, cmp);

    ll tip = 0;
    for (int i = 0; i < n; i++) {
        int temp = 1L * arr[i] - (i + 1 - 1);
        if (temp < 0) continue;
        tip += temp;
    }

    cout << tip;
}