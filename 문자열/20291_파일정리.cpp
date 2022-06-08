#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	//�Է�  
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		v.push_back(temp);
	}

	// map�� key ������ �������� ���� ��. 
	map<string, int> m;
	for (int i = 0; i < n; i++) {
		string file = v[i].substr(v[i].find('.')+1);
		if (m.find(file) != m.end()) {
			m[file] += 1;
		}
		else {
			m[file] = 1;
		}
	}
	
	// �� ���  
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}
}
