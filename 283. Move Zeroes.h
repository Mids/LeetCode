//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_283_MOVE_ZEROES_H
#define LEETCODE_283_MOVE_ZEROES_H

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int size = nums.size();

		int j =0;
		for (int i = 0; i < size; i++) {
			if(nums[i] != 0)
				nums[j++] = nums[i];
		}

		while (j < size) {
			nums[j++] = 0;
		}
	}
};

#endif //LEETCODE_283_MOVE_ZEROES_H
