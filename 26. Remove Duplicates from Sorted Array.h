//
// Created by jin on 1/11/2021.
//

#ifndef LEETCODE_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define LEETCODE_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H

using namespace std;

class Solution {
public:
	int result = 0, val;
	int size;

	int removeDuplicates(vector<int> &nums) {
		size = nums.size();
		if (size == 0) return 0;

		for (int i = 1; i < size; ++i) {
			val = nums[i];
			if (nums[result] != val) {
				nums[++result] = val;
			}
		}

		return result + 1;
	}
};

#endif //LEETCODE_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
