#include "连续子数组的最大和.h"
#include <vector>

void MAXSUBARRAY::run()
{
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	/*for (int n : nums) {
		cout << n << " ";
	}
	cout << endl;*/
	int sumMax = nums[0];
	int curMax = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		curMax = max(curMax + nums[i], nums[i]);
		sumMax = max(sumMax, curMax);
	}
	cout << sumMax << endl;
}
