#include<iostream>
#include<string>
using namespace std;

class Stack {
	int* stack;
	int sp;
public:
	Stack() {
		stack = new int[10000];
		sp = -1;
	}
	~Stack() { delete stack; }
	void push(int x) {
		stack[++sp] = x;
	}
	int pop() {
		if (IsEmpty())return -1;
		else return stack[sp--];
	}
	int size() {
		return sp + 1;
	}
	int IsEmpty() {
		if (sp == -1)return 1;
		else return 0;
	}
	void top() {
		if (IsEmpty()) cout << -1 << endl;
		else cout << stack[sp] << endl;
	}
};

int main(void) {
	class Stack s;
	int num; cin >> num;
	for (int i = 0; i < num+1; i++) {
		string temp; getline(cin,temp);

		string op; 
		int number;
		int temp_num;
		
		if (temp.find("push")==-1)
		{
			op = temp;
		}
		else 
		{
			op = "push";
			number = stoi(temp.substr(5, temp.length() - 5 ));
		}

		if (op == "push") {
			s.push(number);
		}
		else if (op == "pop") {
			temp_num = s.pop();
			cout << temp_num << endl;
		}
		else if (op == "size") {
			temp_num = s.size();
			cout << temp_num << endl;
		}
		else if (op == "empty") {
			temp_num = s.IsEmpty();
			cout << temp_num << endl;
		}
		else if (op == "top") {
			s.top();
		}
	}
}
