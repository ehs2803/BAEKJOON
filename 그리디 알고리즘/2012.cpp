#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(arr[i] - (i + 1));
    }

    cout << sum;
}