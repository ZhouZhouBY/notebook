#include "有效的括号.h"
#include <stack>

void VALIDKUOHAO::run()
{
	string s;
	cin >> s;
	stack<char> stk;
	for (char c : s) {
		if (c == '(' || c == '[' || c == '{') {
			stk.push(c);
		}
		else if (c == ')') {
			if (stk.empty() || stk.top() != '(') {
				cout << "false" << endl;
				return;
			}
			stk.pop();
		}
		else if (c == ']') {
			if (stk.empty() || stk.top() != '[') {
				cout << "false" << endl;
				return;
			}
			stk.pop();
		}
		else if (c == '}') {
			if (stk.empty() || stk.top() != '{') {
				cout << "false" << endl;
				return;
			}
			stk.pop();
		}
	}
	if (stk.empty()) {
		cout << "true" << endl;
		return;
	}
	cout << "false" << endl;
}
