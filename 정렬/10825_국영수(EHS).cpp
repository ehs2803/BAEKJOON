#include<iostream>
#include<algorithm>
using namespace std;

// 학생 정보 담는 구조체  
struct student{
	string name;
	int kor;
	int eng;
	int math;
};

int n;

bool cmp(struct student st1, struct student st2){
	if(st1.kor>st2.kor){
		return true;	
	}
	else if(st1.kor==st2.kor){
		if(st1.eng<st2.eng) {
			return true;	
		}
		else if(st1.eng==st2.eng){
			if(st1.math>st2.math) {
				return true;	
			}
			else if(st1.math==st2.math){
				if(st1.name<st2.name) {
					return true;	
				}
				else {
					return false;	
				}
			}
		}
	}
	return false;
}

int main(){
	// 입력  
	cin>>n;
	
	struct student s[n];
	
	// 입력  
	for(int i=0;i<n;i++){
		cin>>s[i].name;
		cin>>s[i].kor;
		cin>>s[i].eng;
		cin>>s[i].math;
	}	
	
	// 정렬  
	sort(s,s+n,cmp);
	
	// 답 출력  
	for(int i=0;i<n;i++){
		cout<<s[i].name<<'\n';
	}
}
