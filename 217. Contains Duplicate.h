//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_217_CONTAINS_DUPLICATE_H
#define LEETCODE_217_CONTAINS_DUPLICATE_H

#include <algorithm>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int> &nums) {
		int size = nums.size();
		sort(nums.begin(), nums.end());

		for (int i = 1; i < size; ++i) {
			if (nums[i - 1] == nums[i]) {
				return true;
			}
		}
		return false;
	}
};

#endif //LEETCODE_217_CONTAINS_DUPLICATE_H
