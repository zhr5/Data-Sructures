#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool IsValid(char *expr) {
	//括号匹配的检验, 匹配返回TRUE，不匹配返回FALSE
	//用-1表示 (		-2表示[		-3表示{
	int i = 0;

	stack <int> S;

	int e=0;

	while ('\0' != *(expr + i)) {

		switch (*(expr + i)) {

		case '(':

			S.push(-1);

			break;

		case '[':

			S.push(-2);

			break;

		case '{':

			S.push(-3);

			break;

		case ')':

			if (! S.empty() ){		//栈非空，得到栈顶元素

				e = S.top();
				if (-1 == e) {		//栈顶元素与‘）’匹配

					S.pop();		// 删除栈顶元素
				}

				else				// 不匹配，返回ERROR

					return false;

			}
			else

				return false;

			break;

		case ']':

			if (!S.empty()) {

				e = S.top();

				if (-2 == e) {

					S.pop();
				}

				else

					return false;
			}
			else

				return false;

			break;

		case '}':

			if (!S.empty()) {

				e = S.top();

				if (-3 == e)

					S.pop();

				else

					return false;

			}
			else

				return false;

			break;

		default:

			break;

		} //switch



		i++;

	} // while



	if (S.empty())

		return true;

	else

		return false;
}

int main() {
	char bracket[100];
	char *s = &bracket[0];
	cin >> bracket;
	string str= IsValid(s) == 1 ? "匹配正确" : "匹配失败";
	cout << str << endl;
	return 0;
}