#include<iostream>
using namespace std;

int main() {
    int n; cin >> n;

    int cnt = 0;

    if (n % 5 == 0) {
        cout << n / 5;
        return 0;
    }
    int five = n / 5;
    if (five == 0) {
        if (n % 2 != 0) cout << -1;
        else {
            cout << n / 2;
        }
    }
    else {
        while ((n - (5 * five)) % 2 != 0) {
            five--;
            if (five == 0) break;
        }
        n = n - (five * 5);
        if (n % 2 != 0) cout << -1;
        else {
            int two = n / 2;
            cnt = two + five;
            cout << cnt;
        }
    }
}