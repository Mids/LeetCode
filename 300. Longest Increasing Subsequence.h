//
// Created by Jin on 5/5/2021.
//

#ifndef LEETCODE_300_LONGEST_INCREASING_SUBSEQUENCE_H
#define LEETCODE_300_LONGEST_INCREASING_SUBSEQUENCE_H

#include <climits>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int> &nums) {
		vector<int> result(nums.size(), INT_MAX);

		int seqMax = 0;
		for (auto &n:nums) {
			auto lb = lower_bound(result.begin(), result.end(), n);

			if (*lb == INT_MAX)
				++seqMax;

			*lb = min(*lb, n);
		}

		return seqMax;
	}
};

#endif //LEETCODE_300_LONGEST_INCREASING_SUBSEQUENCE_H
