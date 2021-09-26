#include<iostream>
using namespace std;

class Stack {
	int* stack;
	int sp;
public:
	Stack() {
		stack = new int[100000];
		sp = -1;
	}
	~Stack() { delete stack; }
	void push(int x) {
		stack[++sp] = x;
	}
	int pop() {
		return stack[sp--];
	}
	int sum() {
		int sum = 0;
		for (int i = 0; i <= sp; i++) {
			sum += stack[i];
		}
		return sum;
	}
};

int main(void) {
	int num; cin >> num;
	Stack s;
	for (int i = 0; i < num; i++) {
		int input_num; cin >> input_num;

		if (input_num == 0) {
			s.pop();
		}
		else {
			s.push(input_num);
		}
	}
	cout << s.sum();
}