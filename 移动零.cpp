#include "移动零.h"
#include <vector>

void MOVEZERO::run()
{
	vector<int> nums = { 0, 0 };
	int carry = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == 0) {
			++carry;
		}
		else {
			nums[i - carry] = nums[i];
		}
	}
	for (int i = nums.size() - 1; i >= (int)nums.size() - carry; i--) {
		nums[i] = 0;
	}
	for (int n : nums) {
		cout << n << " " ;
	}
}
