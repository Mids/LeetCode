//
// Created by jin on 2/22/2021.
//

#ifndef LEETCODE_384_SHUFFLE_AN_ARRAY_H
#define LEETCODE_384_SHUFFLE_AN_ARRAY_H

#include <cstdlib>

using namespace std;

class Solution {
private:
	vector<int> internalNums;
	vector<int> result;
	int size;
public:
	Solution(vector<int> &nums) {
		internalNums = nums;
		result = internalNums;
		size = internalNums.size();
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return internalNums;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		for (int i = 0; i < size; ++i) {
			int index = rand() % size;
			int index2 = rand() % size;
			swap(result[index], result[index2]);
		}

		return result;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

#endif //LEETCODE_384_SHUFFLE_AN_ARRAY_H
