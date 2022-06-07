#include<iostream>
#include<vector>
using namespace std;

int main(){
	int drawCnt[]={3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};
	
	string str;
	cin>>str;
	
	//-17
	vector<int> numbers;
	for(int i=0;i<str.size();i++){
		numbers.push_back(drawCnt[str[i]-65]);
	}

	while(true){
		if(numbers.size()==1) break;
		
		vector<int> temp;
		if(numbers.size()%2==0){
			int tempSum=0;
			for(int i=0;i<numbers.size();i++){
				if(i%2==0){
					tempSum+=numbers[i];
				}
				else{
					tempSum+=numbers[i];
					temp.push_back(tempSum);
					tempSum=0;
				}
			}
		}
		else{
			int tempSum=0;
			for(int i=0;i<numbers.size();i++){
				if(i%2==0){
					tempSum+=numbers[i];
				}
				else{
					tempSum+=numbers[i];
					temp.push_back(tempSum);
					tempSum=0;
				}
			}
			temp.push_back(numbers[numbers.size()-1]);
		}
		
		numbers = temp;
	
	}
	
	if(numbers[0]%2==0){
		cout<<"You're the winner?";
	}
	else{
		cout<<"I'm a winner!";
	}
	
}
