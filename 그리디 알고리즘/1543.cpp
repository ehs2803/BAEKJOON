#include<iostream>
#include<string>
using namespace std;

int main(){
    string doc;
    getline(cin,doc);
    string word;
    getline(cin,word);

    int ans=0;
    int index=0;
    while(true){
        if(doc.find(word,index)==string::npos) break;
        else{
            ans++;
            index = doc.find(word,index) + word.size();
        }
    }
    cout<<ans;
}
