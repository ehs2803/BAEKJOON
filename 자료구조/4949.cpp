#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
    while (true) {
        stack<char> s;
        string str;
        getline(cin, str);
        if (str == ".") break;
        else {
            bool check = false;
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == '(') {
                    s.push('(');
                }
                else if (str[i] == ')') {
                    if (s.size() == 0 || s.top() == '[') {
                        cout << "no" << '\n';
                        check = true;
                        break;
                    }
                    else {
                        s.pop();
                    }
                }
                else if (str[i] == '[') {
                    s.push('[');
                }
                else if (str[i] == ']') {
                    if (s.size() == 0 || s.top() == '(') {
                        cout << "no" << '\n';
                        check = true;
                        break;
                    }
                    else {
                        s.pop();
                    }
                }
            }
            if (check == false) {
                if (s.size() == 0) cout << "yes" << '\n';
                else cout << "no" << '\n';
            }
        }
    }
}