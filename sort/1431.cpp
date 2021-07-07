#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int integer_sum(string a) {
	int len = a.length();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool cmp(const string &a, const string &b){
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() > b.length()) {
		return 0;
	}
	else {
		int sum_a = integer_sum(a);
		int sum_b = integer_sum(b);
		if (sum_a < sum_b) {
			return 1;
		}
		else if (sum_a > sum_b) {
			return 0;
		}
		else {
			return a < b;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin>>n;
	vector<string> v(n);
		
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end(), cmp);
	for(int i=0;i<n;i++) cout<<v[i]<<'\n';
}
