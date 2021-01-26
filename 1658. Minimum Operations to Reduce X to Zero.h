//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_1658_MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H
#define LEETCODE_1658_MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H

#include <algorithm>

using namespace std;

class Solution {
public:

	int minOperations(vector<int> &nums, int x) {
		int size = nums.size();
		int result = 100001;

		vector<int> left, right;

		for (int i = 0; i < size; ++i) {
			int newVal = left.size() > 0 ? left.back() + nums[i] : nums[i];
			if (newVal > x)
				break;
			left.push_back(newVal);
			if (newVal == x)
				result = left.size();
		}

		for (int i = size - 1; i >= 0; --i) {
			int newVal = right.size() > 0 ? right.back() + nums[i] : nums[i];
			if (newVal > x)
				break;
			right.push_back(newVal);
			if (newVal == x && result > right.size())
				result = right.size();
		}

		int leftSize = left.size();
		int rightSize = right.size();
		int i = 0, j = rightSize - 1;

		while (i < leftSize && j >= 0) {
			int newVal = left[i] + right[j];
			int count = i + j + 2;
			if (count < size && newVal == x) {
				if (result > count)
					result = count;
				--j, ++i;
				continue;
			}

			newVal < x ? ++i : --j;
		}

		if (result == 100001) return -1;
		return result;
	}
};


#endif //LEETCODE_1658_MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H
