// 열 개씩 끊어 출력하기 - 구현
// Created by nec on 2021-10-18.
// 성공. string.
#include <iostream>
using namespace std;

int main(){
    string str; cin>>str;

    int index=0;
    while(true){
        if(index+9<=str.size()-1){
            string temp = str.substr(index,10);
            cout<<temp<<'\n';
            index+=10;
        }
        else{
            string temp = str.substr(index);
            cout<<temp;
            break;
        }
    }
}
