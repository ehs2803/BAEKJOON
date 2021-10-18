// !밀비 급일 - 구현
// Created by nec on 2021-10-18.
// 성공. reverse 사용, 공백 문자열 입력
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    while(true){
        string in;
        getline(cin,in);
        if(in=="END") break;
        reverse(in.begin(), in.end());
        cout<<in<<'\n';
    }
}
