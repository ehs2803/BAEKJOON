#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<pair<string, int>, pair<int, int> > a, pair<pair<string, int>, pair<int, int> > b){

    if (a.first.second > b.first.second)
        return true;
    else if (a.first.second == b.first.second){
        if (a.second.first < b.second.first)
            return true;
        else if (a.second.first == b.second.first){
            if (a.second.second > b.second.second)
                return true;
            else if(a.second.second == b.second.second)
                if (a.first.first < b.first.first)
                    return true;
        }
    }
    return false;
}

int main(){
	int n; cin>>n;
	
	vector<pair<pair<string, int>, pair<int, int> > > v(n);
	
	for(int i=0;i<n;i++)
		cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;

	sort(v.begin(), v.end(), cmp);
	
	for(int i=0;i<n;i++){
		cout<<v[i].first.first<<'\n';
	}
}
