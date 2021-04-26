#ifndef LEETCODE_75_SORT_COLORS_H
#define LEETCODE_75_SORT_COLORS_H

#include <algorithm>

using namespace std;

class Solution {
public:
	void sortColors(vector<int> &nums) {
		int start = 0, end = nums.size() - 1;

		for (auto i = 0; i <= end;) {
			if (nums[i] == 0 && start < i)
				swap(nums[i], nums[start++]);
			else if (nums[i] == 2 && i < end)
				swap(nums[i], nums[end--]);
			else ++i;
		}
	}
};

#endif //LEETCODE_75_SORT_COLORS_H
