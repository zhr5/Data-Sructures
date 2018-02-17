#include<iostream>
#include<stack>
using namespace std;

void conversion() {
	//对于任意一个非负十进制整数,打印输出与其等值的八进制数
	stack<int> S;//构造空栈
	
	int N;

	cin >> N;

	while(N) {
		S.push(N % 8);
		N = N / 8;
	}

	while (!S.empty()) {
		int e = S.top();
		cout << e;
		S.pop();		
	}

}

int main() {
	conversion();
	return 0;
}