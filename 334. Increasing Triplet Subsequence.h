//
// Created by jin on 3/16/2021.
//

#ifndef LEETCODE_334_INCREASING_TRIPLET_SUBSEQUENCE_H
#define LEETCODE_334_INCREASING_TRIPLET_SUBSEQUENCE_H

using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int> &nums) {
		int lowest = INT_MAX;
		int second_lowest = INT_MAX;

		for (auto n : nums) {
			if (n > second_lowest)
				return true;

			if (n > lowest && n < second_lowest)
				second_lowest = n;

			else if (n < lowest)
				lowest = n;
		}

		return false;
	}
};

#endif //LEETCODE_334_INCREASING_TRIPLET_SUBSEQUENCE_H
