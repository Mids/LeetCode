//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_1_TWO_SUM_H
#define LEETCODE_1_TWO_SUM_H

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int size = nums.size();

		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; ++j) {
				if (nums[i] + nums[j] == target) {
					vector<int> newNums = {i, j};
					return  newNums;
				}
			}
		}

		return nums;
	}
};


#endif //LEETCODE_1_TWO_SUM_H
