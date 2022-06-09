#include<iostream>
#include<string>
using namespace std;

int PseudoPalin(string str, int left, int right);

// 회문이면 0, 유사회문이면 1, 그 외는 2를 출력
int Palindrome(string str){
    int left=0, right = str.size()-1;

    while (left < right){
        if (str[left] == str[right]){
            left += 1;
            right -= 1;
        }
        else {
            int leftChk = PseudoPalin(str, left+1, right);
            int rightChk = PseudoPalin(str, left, right-1);
            if (leftChk || rightChk){
                return 1;
            }
            else {
                return 2;
            }
        }
    }
    return 0;
}

int PseudoPalin(string str, int left, int right){
    while (left < right){
        if (str[left] == str[right]){
            left += 1;
            right -= 1;
        }
        else {
            return 0;
        }
    }
    return 1;
}

int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		
		
		int ans = Palindrome(str);
		
		cout<<ans<<'\n';
	}
}
