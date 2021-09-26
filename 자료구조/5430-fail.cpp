#include<iostream>
#include<deque>
#include<string>
using namespace std;

void printDeque(deque<int> &dq){
	cout<<"[";
	for(int i=0;i<dq.size()-1;i++){
		cout<<dq[i]<<',';
	}
	cout<<dq[dq.size()-1];
	cout<<"]"<<'\n';	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin>>t;
	while(t--){
		string str; cin>>str;
		int num; cin>>num;
		int n;
		deque<int> d;
		while(true){
			if(num==n) break;
			string instr; cin>>instr;
			if(instr!=',' && instr!='[' && instr!=']'){
				d.push_back(stoi(instr));
				n++;
			}
		}
		for(int i=0;i<str.size();i++){
			if(str[i]=='R'){
				
				for(int j=0;j<d.size();j++){
					
				}
			}
			else{
				if(d.size()==0) {
				    cout<<"error"<<'\n';
					break;	
				}
				else d.pop_front();
			}
		}
		printDeque(d);
	}
}
