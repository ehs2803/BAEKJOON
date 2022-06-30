#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// 시간초과문제로 문자를 하나씩 추가하면 않된다. 
void convert(string s, string t){
    if(s==t){ // 성공한 경우  
        cout << 1 << "\n";
        exit(0);
    }
    
    if(s.size()>=t.size()) return; // 실패한 경우 
	 
    if(t[t.size()-1]=='A'){ // 1
    	string temp = "";
        temp = t;
        temp.erase(temp.size()-1);
        convert(s,temp);
    }
    if(t[0]=='B'){ // 2
    	string temp = "";
        temp = t;
        temp.erase(temp.begin());
        reverse(temp.begin(),temp.end());
        convert(s,temp);
    }
}

int main(){
	string s,t;
	cin>>s>>t;
	
	convert(s,t);

	cout<<0;
}
