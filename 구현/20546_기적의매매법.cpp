#include<iostream>
#include<vector>
using namespace std;

int main(){
	int money;
	cin>>money;
	
	vector<int> price(14);
	for(int i=0;i<price.size();i++){
		cin>>price[i];
	}
	
	int j=money, s=money, jCnt=0, sCnt=0;
	int increaseCnt=0, decreaseCnt=0;
	int prePrice=0;
	for(int i=0;i<14;i++){
		if(j>=price[i]){
			int buyCnt=j/price[i];
			j-=(buyCnt*price[i]);
			jCnt+=buyCnt;
		}
		
		if(price[i]>prePrice){
			increaseCnt++;
			decreaseCnt=0;
		}
		else if(price[i]<prePrice){
			decreaseCnt++;
			increaseCnt=0;
		}
		else if(price[i]==prePrice){
			increaseCnt=0;
			decreaseCnt=0;
		}
		
		if(increaseCnt>=3){
			if(sCnt>0){
				s+=price[i]*sCnt;
				sCnt=0;
			}
			// increaseCnt=0;
		}
		else if(decreaseCnt>=3){
			if(s>=price[i]){
				int buyCnt=s/price[i];
				s-=(buyCnt*price[i]);
				sCnt+=buyCnt;
			}
			// decreaseCnt=0;
		}
		
		prePrice=price[i];	
	}
	
	int jResult=0, sResult=0;
	jResult+=j;
	jResult+=price[13]*jCnt;
	sResult+=s;
	sResult+=price[13]*sCnt;
	
	if(jResult==sResult){
		cout<<"SAMESAME";
	}
	else if(jResult>sResult){
		cout<<"BNP";
	}
	else{
		cout<<"TIMING";
	}
}
