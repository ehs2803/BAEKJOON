#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* 시간 초과  
int maxValueIndex(const vector<int> & v){
	int index=0;
	int maxValue = v[0];
	for(int i=1;i<v.size();i++){
		if(v[i]>maxValue){
			maxValue = v[i];
			index=i;
		}
	}
	return index;
}
*/
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	
	vector<int> length(n);
	vector<int> grow(n);
	long long ans=0;
	
	for(int i=0;i<n;i++){
		cin>>length[i];
		ans+=length[i];
	}
	for(int i=0;i<n;i++){
		cin>>grow[i];
	}
	
	/* 시간초과  
	long long ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			length[j]+=grow[j];
		}
		int index = maxValueIndex(length);
		ans+=length[index];
		length[index]=0;
	}
	*/
	
	sort(grow.begin(), grow.end());
	for(int i=0;i<n;i++){
		ans+=grow[i]*i;
	}
	
	cout<<ans;
}

