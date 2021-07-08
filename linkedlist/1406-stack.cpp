#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void){
    stack<char> left, right;

    string str; cin>>str;
    for(int i=0;i<str.length();i++) left.push(str[i]);

    int t; cin>>t;
    for(int i=0;i<t;i++){
        char c; cin>>c;
        if(c=='L'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }
        else if(c=='D'){
            if(!right.empty()){
               left.push(right.top());
               right.pop(); 
            }
        }
        else if(c=='B'){
            if(!left.empty()) left.pop();
        }
        else if(c=='P'){
            char add; cin>>add;
            left.push(add);
        }
    }
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout<<right.top();
        right.pop();
    }
}
