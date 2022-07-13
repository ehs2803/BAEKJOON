#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool IsExist(const vector<pair<int,pair<int,int>>> & frame, int person){
	bool check=false;
	for(int i=0;i<frame.size();i++){
		if(frame[i].first==person){
			check=true;
			break;
		}
	}
	return check;
}

void increaseCnt(vector<pair<int,pair<int,int>>> frame, int person, int history){
	for(int i=0;i<frame.size();i++){
		if(frame[i].first==person){
			frame[i].second.first++;
			frame[i].second.second=history;
			break;
		}	
	}
}

int deleteElement(const vector<pair<int,pair<int,int>>> & frame){
	int minValue=1e9;
	for(int i=0;i<frame.size();i++){
		if(frame[i].second.first<minValue){
			minValue = frame[i].second.first;
		}
	}	
	
	int delIndex;
	int oldhistory=1e9;
	for(int i=0;i<frame.size();i++){
		if(frame[i].second.first==minValue){
			if(frame[i].second.second<oldhistory){
				delIndex=i;
				oldhistory=frame[i].second.second;
			}
		}
	}
	return delIndex;
}

int main(){
	int n,k;
	cin>>n>>k;
	
	vector<pair<int,pair<int,int>>> pictureFrame; // person, {cnt,history}
	for(int i=0;i<k;i++){
		int person;
		cin>>person;
		
		if(IsExist(pictureFrame, person)){
			increaseCnt(pictureFrame, person, i);
		}
		else if(pictureFrame.size()==n){
			// del
			int delIndex = deleteElement(pictureFrame);
			pictureFrame.erase(pictureFrame.begin()+delIndex);
			pictureFrame.push_back({person, {1, i}});
		}
		else{
			pictureFrame.push_back({person, {1, i}});
		}
	}
	
	vector<int> ans;
	for(int i=0;i<pictureFrame.size();i++){
		ans.push_back(pictureFrame[i].first);
	}
	
	sort(ans.begin(), ans.end());
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<' ';
	}
}
