#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// �ð��ʰ������� ���ڸ� �ϳ��� �߰��ϸ� �ʵȴ�. 
void convert(string s, string t){
    if(s==t){ // ������ ���  
        cout << 1 << "\n";
        exit(0);
    }
    
    if(s.size()>=t.size()) return; // ������ ��� 
	 
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
