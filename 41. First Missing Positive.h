//
// Created by jin on 6/28/2021.
//

#ifndef LEETCODE_41_FIRST_MISSING_POSITIVE_H
#define LEETCODE_41_FIRST_MISSING_POSITIVE_H

#include <set>

using namespace std;

// In-place
class Solution {
public:
	int firstMissingPositive(vector<int> &nums) {
		int size = nums.size();
		for (int i = 0; i < size; ++i)
			while (nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);

		for (int i = 0; i < size; ++i)
			if (nums[i] != i + 1)
				return i + 1;

		return size + 1;
	}
};


// O(n) space
class Solution1 {
public:
	int firstMissingPositive(vector<int> &nums) {
		bool array[500002] = {0};
		for (auto n : nums) {
			if (n > 0 && n <= 500000)
				array[n] = 1;
		}

		for (int i = 1; i < 500002; ++i) {
			if (!array[i]) {
				return i;
			}
		}

		return 0;
	}
};

#endif //LEETCODE_41_FIRST_MISSING_POSITIVE_H
