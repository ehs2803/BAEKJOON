// OX퀴즈 - 구현
// Created by nec on 2021-10-18.
// 성공. 구현
#include <iostream>
using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        string str; cin>>str;
        int score=1, totalScore=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='O'){
                totalScore+=score;
                score+=1;
            }
            else score=1;
        }

        cout<<totalScore<<'\n';
    }
}
