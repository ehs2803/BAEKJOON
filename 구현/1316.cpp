#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    int n; cin >> n;

    int cnt = 0; // 그룹단어 개수 
    for (int i = 0; i < n; i++) {
        bool gw = true; // 그룹단어일 경우 true, 아닐 경우 false
        string str; cin >> str;

        vector<char> v; // 그동안 나온 알파벳을 저장할 벡터
        char prestr = '.'; // 이전에 나온 문자

        for (int i = 0; i < str.size(); i++) { // 문자열 길이만큼 for문 돌면서 체크
            bool check = false; // 이전에 체크한 문자와 다른 문자가 나왔을 때 이전에 나온 문자라면 true
            if (prestr != str[i]) { // 바로 이전에 체크한 문자와 다른 문자가 나왔다면
                for (int j = 0; j < v.size(); j++) {
                    if (v[j] == str[i]) { // 이미 체크된 문자라면
                        check = true; 
                        gw = false;
                        break;
                    }
                }
                if (check == true) {
                    break;
                }
                else {
                    v.push_back(str[i]);
                }

            }
            prestr = str[i];
        }
        if (gw == true) cnt++; // 그룹단어일 경우 cnt 변수 1 증가
    }

    // 답 출력
    cout << cnt;
}