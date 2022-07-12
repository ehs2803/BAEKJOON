#include<iostream>
using namespace std;

int main(){
	string a, b;
	while (cin >> a >> b) {
		int aIdx = 0;
		bool isTrue = false;
		for (int i = 0; i < b.length(); i++) {
			if (a[aIdx] == b[i]) {
				aIdx++;
			}
			if (aIdx == a.length()) {
				isTrue = true;
				break;
			}
		}
		if (isTrue) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
}
