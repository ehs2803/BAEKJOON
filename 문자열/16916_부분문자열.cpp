#include<iostream>
#include<vector>
using namespace std;

vector<int> makeTable(string pattern) {
    vector<int> table(pattern.size(), 0);

    for (int i = 1, j = 0; i < pattern.size(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

bool KMP(string text, string pattern) {
    vector<int> table = makeTable(pattern);

    for (int i = 0, j = 0; i < text.size(); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (text[i] == pattern[j]) {
            if (j == pattern.size() - 1) {
                return true;
                j = table[j];
            } else {
                j++;
            }
        }
    }
    return false;
}

int main(){
	string str1, str2;
	
	cin>>str1>>str2;
	
	// ?ð??ʰ? 
	/* 
	if(str1.find(str2)!=string::npos){
		cout<<1;
	}
	else{
		cout<<0;
	}
	*/
	
	if(KMP(str1,str2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
