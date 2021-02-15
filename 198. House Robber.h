//
// Created by jin on 2/15/2021.
//

#ifndef LEETCODE_198_HOUSE_ROBBER_H
#define LEETCODE_198_HOUSE_ROBBER_H

using namespace std;

class Solution {
public:
	int rob(vector<int> &nums) {
		int size = nums.size();

		if (size == 0) {
			return 0;
		} else if (size == 1) {
			return nums[0];
		} else if (size == 2) {
			return max(nums[0], nums[1]);
		}

		nums[1] = max(nums[0], nums[1]);

		for (int i = 2; i < size; ++i) {
			nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);
		}

		return nums[size - 1];
	}
};

#endif //LEETCODE_198_HOUSE_ROBBER_H
