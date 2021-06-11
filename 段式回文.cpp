#include "段式回文.h"

void DUANSHIHUIWEN::run()
{
	string str;
	cin >> str;
	int res = longestDecomposition(str);
	cout << res << endl;
}

int DUANSHIHUIWEN::longestDecomposition(string str)
{
	if (str.length() <= 1) {
		return 1;
	}
	int left = 0, right = str.length() - 1;
	string strL = "", strR = "";
	int cnt = 0;
	while (left < right) {
		strL += str[left++];
		strR = str[right--] + strR;
		if (strL == strR) {
			cnt += 2;
			strL = "";
			strR = "";
		}
	}
	if (left == right || strL != "") {
		++cnt;
	}
	return cnt;
}
