#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(const pair<int,char> & a, const pair<int,char> & b) {
	return a.first > b.first;
}

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string str;
		getline(cin, str);
		pair<int, char> chList[26] = { {0,' '} };
		for (int i = 0; i < str.length(); i++) {
			if (isspace(str[i])) continue;
			chList[str[i] - 'a'] = { chList[str[i] - 'a'].first+1, str[i] };
		}
		sort(chList, chList + 26, cmp);

		if (chList[0].first != chList[1].first) {
			cout << chList[0].second<<'\n';
		}
		else {
			cout << '?' << '\n';
		}
	}
}
