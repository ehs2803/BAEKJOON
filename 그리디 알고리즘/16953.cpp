#include<iostream>
using namespace std;

int main(){
    int A,B; cin>>A>>B;

    int minop=0;
    while(true){
        string Bstr = to_string(B);
        if(Bstr[Bstr.size()-1]=='1'){
            Bstr = Bstr.substr(0,Bstr.size()-1);
            B = stoi(Bstr);
            minop++;
        }
        else if(B%2==0){
            B=B/2;
            minop++;
        }
        else{
            cout<<-1;
            break;
        }

        if(A==B) {
            cout<<minop+1;
            break;
        }
        if(A>B){
            cout<<-1;
            break;
        }
    }
}
