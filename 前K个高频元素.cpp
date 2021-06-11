#include "前K个高频元素.h"
#include <vector>
#include <queue>
#include <map>

void quickSort(vector<pair<int,int>>& nums, int left, int right) {
	if (left >= right) {
		return;
	}
	int l = left, r = right;
	int key = nums[l].second;
	while (l < r) {
		while (l < r && key < nums[r].second) {
			--r;
		}
		if (l < r) {
			nums[l++] = nums[r];
		}
		while (l < r && key > nums[l].second) {
			++l;
		}
		if (l < r) {
			nums[r--] = nums[l];
		}
	}
	nums[l].second = key;
	quickSort(nums, left, l - 1);
	quickSort(nums, l + 1, right);
}

void show(vector<pair<int,int>> nums) {
	for (auto n : nums) {
		cout << n.first << " " << n.second << endl;
	}
	cout << endl;
}

void TOPKFREQUENT::run()
{
	vector<int> nums = { 1,1,1,2,2,2,2,3,1,1,5 };
	vector<pair<int, int>> array;
	map<int, int> mp;
	for (int n : nums) {
		++mp[n];
	}
	for (auto m : mp) {
		array.push_back(make_pair(m.first, m.second));
	}
	/*quickSort(array, 0, array.size() - 1);
	show(array);*/
	for (int n : nums) {
		++mp[n];
		cout << n << " ";
	}
	cout << endl;
	int k;
	cin >> k;
	// priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> que; // 小顶堆
	priority_queue<pair<int, int>> que; // 大顶堆
	vector<pair<int, int>> vec;
	for (auto m : mp) {
		auto cur = make_pair(m.second, m.first);
		que.push(cur);
	}
	while (k-- && !que.empty()) {
		auto res = que.top();
		cout << res.second << " ";
		que.pop();
	}
	cout << endl;
}
