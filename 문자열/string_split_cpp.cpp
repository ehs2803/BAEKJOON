#include <sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string input1="a:b:c:d:e";
	string input2="f g h i j";
	
	stringstream ss1(input1);
	stringstream ss2(input2);
	
	vector<string> ret1, ret2;
	string tmp;
	
	while(getline(ss1, tmp, ':')){
		ret1.push_back(tmp);
	}
	
	while(getline(ss2, tmp, ' ')){
		ret2.push_back(tmp);
	}
	
	for(int i=0;i<ret1.size();i++){
		cout<<ret1[i]<<' ';
	}
	cout<<'\n';
	
	for(int i=0;i<ret2.size();i++){
		cout<<ret2[i]<<' ';
	}
	cout<<'\n';
}

