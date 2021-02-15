//
// Created by jin on 2/15/2021.
//

#ifndef LEETCODE_53_MAXIMUM_SUBARRAY_H
#define LEETCODE_53_MAXIMUM_SUBARRAY_H

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int> &nums) {
		int result = nums[0];
		int subMax = 0;

		for (int num : nums) {
			subMax += num;

			result = max(result, subMax);
			subMax = max(subMax, 0);
		}

		return result;
	}
};

#endif //LEETCODE_53_MAXIMUM_SUBARRAY_H
