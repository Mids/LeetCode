//
// Created by jin on 4/19/2021.
//

#ifndef LEETCODE_78_SUBSETS_H
#define LEETCODE_78_SUBSETS_H

using namespace std;

#include <cmath>

// backtrack
class Solution {
public:
	vector<int> input;
	vector<vector<int>> result;
	int size;
	int end;

	vector<vector<int>> subsets(vector<int> &nums) {
		size = nums.size();
		input = nums;

		for (end = 0; end <= size; ++end) {
			vector<int> cur;
			backtrack(0, cur);
		}

		return result;
	}

	void backtrack(int start, vector<int> &cur) {
		if (cur.size() == end) {
			result.push_back(cur);
			return;
		}

		for (auto i = start; i < size; ++i) {
			cur.push_back(input[i]);
			backtrack(i + 1, cur);
			cur.pop_back();
		}
	}
};

// Bitmask
class Solution2 {
public:
	vector<vector<int>> subsets(vector<int> &nums) {
		vector<vector<int>> result;
		int size = nums.size();
		int allOne = 1 << size;

		vector<int> position(size);
		for (auto i = 0; i < size; ++i) {
			position[i] = 1 << i;
		}


		for (auto i = 0; i < allOne; ++i) {
			vector<int> cur;
			for (auto j = 0; j < size; ++j) {
				if ((i & position[j]) > 0) {
					cur.push_back(nums[j]);
				}
			}
			result.push_back(cur);
		}

		return result;
	}
};

#endif //LEETCODE_78_SUBSETS_H
