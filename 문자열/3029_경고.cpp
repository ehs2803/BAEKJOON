#include<iostream>
#include<string>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	int str1_h = stoi(str1.substr(0, 2));
	int str1_m = stoi(str1.substr(3, 2));
	int str1_s = stoi(str1.substr(6));

	int str2_h = stoi(str2.substr(0, 2));
	int str2_m = stoi(str2.substr(3, 2));
	int str2_s = stoi(str2.substr(6));

	if (str1_h == str2_h && str1_m == str2_m && str1_s == str2_s) {
		cout << "24:00:00";
		return 0;
	}

	int h, m, s;

	if (str2_s >= str1_s) {
		s = str2_s - str1_s;
	}
	else {
		str2_m -= 1;
		s = str2_s + (60 - str1_s);
	}

	if (str2_m >= str1_m) {
		m = str2_m - str1_m;
	}
	else {
		str2_h -= 1;
		m = str2_m + (60 - str1_m);
	}

	if (str2_h >= str1_h) {
		h = str2_h - str1_h;
	}
	else {
		h = str2_h + (24 - str1_h);
	}

	string ans = "";
	string str_h = to_string(h);
	string str_m = to_string(m);
	string str_s = to_string(s);

	if (str_h.size() == 1) str_h = "0" + str_h;
	if (str_m.size() == 1) str_m = "0" + str_m;
	if (str_s.size() == 1) str_s = "0" + str_s;

	ans = str_h + ":" + str_m + ":" + str_s;
	cout << ans;
}
