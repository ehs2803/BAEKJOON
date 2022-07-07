#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;


bool cmp(const pair<int, pair<int,int>> & a, const pair<int, pair<int, int>>& b) {
	if (a.second.first == b.second.first) return a.second.second < b.second.second;
	else if (a.second.first > b.second.first) return true;
	else return false;
}

int main() {
	int N, C;
	cin >> N >> C;

	unordered_map<int, pair<int, int>> m;

	int a;
	int j = 1;

	for (int i = 0; i < N; i++) {
		cin >> a;
		if (m.find(a) != m.end()) {
			m[a].first += 1;
		}
		else {
			m[a].first = 1;

		}
		
		if (m[a].first == 1) {
			m[a].second = j++;
		}
	
	}

	vector<pair<int, pair<int,int>>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].second.first; j++) {
			cout << v[i].first << " ";
		}		

		//cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << "\n";
	}




}
