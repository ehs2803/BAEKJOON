#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void){
    string str; cin>>str;
    stack<char> s;
    int data[26]={0};

    for(int i=0;i<str.length();i++) s.push(str[i]);
    for(int i=0;i<str.length();i++){
        data[s.top()-97]+=1;
        s.pop();
    }
    for(int i=0;i<26;i++) cout<<data[i]<<' ';
}
