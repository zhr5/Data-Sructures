#include<stdio.h>
#include<stack>
using namespace std;

void LineEdit() {
	//利用字符栈S,从终端接收一行并传送至调用过程的数据区
	stack<char> S;
	char ch = getchar();//从终端接收第一个字符
	while (ch != EOF) {//EOF为全文结束符
		while (ch != EOF&&ch != '\N') {
			switch (ch) {
			case '#':S.pop();	break;
			case '@':S.emplace();	break;
			default: S.push(ch);
			}
			ch = getchar();//从终端接收下一个字符
		}
		//将从栈底到栈顶的栈内字符传送至调用过程的数据区
		S.emplace();

		if (ch != EOF)	ch = getchar();
	}
	
}

int main() {
	LineEdit();
	return 0;
}
