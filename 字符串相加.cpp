#include "字符串相加.h"

std::vector<std::string> StringAdd::init()
{
	string strA, strB;
	cin >> strA >> strB;
	return { strA, strB };
}

void StringAdd::run()
{
	vector<string> str = init();
	string strA = str[0];
	string strB = str[1];
	reverse(strA.begin(), strA.end());
	reverse(strB.begin(), strB.end());
	// cout << strA << endl << strB << endl;
	int carry = 0;
	int i = 0, j = 0;
	string res = "";
	while (i < strA.length() || j < strB.length() || carry != 0) {
		int cur = (i < strA.length() ? (strA[i] - '0') : 0) + (j < strB.length() ? strB[j] - '0' : 0) + carry;
		carry = cur / 10;
		res += (cur % 10) + '0';
		++i;
		++j;
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
}

