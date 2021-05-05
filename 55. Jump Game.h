//
// Created by Jin on 5/5/2021.
//

#ifndef LEETCODE_55_JUMP_GAME_H
#define LEETCODE_55_JUMP_GAME_H

using namespace std;

class Solution {
public:
	bool canJump(vector<int> &nums) {
		int last = nums.size() - 1, maxIndex = nums[0];
		if (last == 0) return true;

		for (int i = 0; i <= maxIndex; ++i) {
			maxIndex = max(maxIndex, nums[i] + i);
			if (maxIndex >= last)
				return true;
		}

		return false;
	}
};

#endif //LEETCODE_55_JUMP_GAME_H
