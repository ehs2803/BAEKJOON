#include<iostream>
#include<vector>
using namespace std;

int main(){
	int h,w;
	cin>>h>>w;
	
	vector<int> v;
	for(int i=0;i<w;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	int ans=0;
	for(int i=1;i<w-1;i++){
		int left_max = 0, right_max=0;
		// ¿ÞÂÊ ÃÖ´ñ°ª Ã£±â 
		for(int j=0;j<i;j++) left_max = max(left_max, v[j]);
		// ¿À¸¥ÂÊ ÃÖ´ñ°ª Ã£±â  
		for(int j=i+1;j<w;j++) right_max = max(right_max, v[j]);
		
		ans+=max(0, min(left_max, right_max)-v[i]);
	}
	
	cout<<ans;
}
