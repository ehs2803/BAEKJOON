#include<iostream>
#include<stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  long long ans;
  int n;  cin >> n;
  long long h;
  stack<int> s;
  
  while (n--) {
    cin >> h;
    while(!s.empty() && s.top() <= h)
      s.pop();
    ans += s.size();
    s.push(h);
  }
  cout << ans;
  return 0;
}
