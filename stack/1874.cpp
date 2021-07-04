#include<iostream>
#include<stack>
#include<string>
using namespace std;
int a[100000];
int main(void) {
    stack<int> s;
    int n; cin >> n;
    string ans;
    for (int i = 0; i < n; i++) cin >> a[i];
    int index = 0;
    for (int i = 1; i <= n; i++) {
        s.push(i); ans += '+';
        while (s.size() > 0 && s.top() == a[index]) {
            s.pop(); ans += '-';
            index++;
        }
        if (s.size() > 0 && s.top() > a[index]) {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 0; i < ans.length(); i++) cout << ans[i] << '\n';
}