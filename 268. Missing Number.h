//
// Created by jin on 2/23/2021.
//

#ifndef LEETCODE_268_MISSING_NUMBER_H
#define LEETCODE_268_MISSING_NUMBER_H

using namespace std;

class Solution {
public:
	int missingNumber(vector<int> &nums) {
		int size = nums.size() + 1;
		bool map[10000];

		for (auto i = 0; i < size; ++i) {
			map[i] = 0;
		}

		for (auto n : nums) {
			map[n] = 1;
		}

		for (auto i = 0; i < size; ++i) {
			if (map[i] != 1) return i;
		}
		return 0;
	}
};

#endif //LEETCODE_268_MISSING_NUMBER_H
