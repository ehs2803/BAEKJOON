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
