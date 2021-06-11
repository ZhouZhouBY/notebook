#include "无重复的最长字串.h"
#include <map>

void lengthOfLongestSubstring::run()
{
	string str;
	cin >> str;
	int left = 0, right = 0;
	map<char, int> mp;
	int cnt = 0;
	while (right < str.length()) {
		while (mp[str[right]] != 0) {
			--mp[str[left]];
			++left;
		}
		++mp[str[right]];
		++right;
		cnt = max(cnt, right - left);
	}
	cout << cnt << endl;
}