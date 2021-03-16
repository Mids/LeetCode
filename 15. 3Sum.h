//
// Created by jin on 3/16/2021.
//

#ifndef LEETCODE_15_3SUM_H
#define LEETCODE_15_3SUM_H

#include <algorithm>

using namespace std;

class Solution {
public:

	// Inline
	vector<vector<int>> threeSum(vector<int> &nums) {
		int size = nums.size();
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < size; ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			int l = i + 1, r = size - 1;
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == 0) {
					result.push_back({nums[i], nums[l], nums[r]});
					while (l < r && nums[l] == nums[l + 1]) ++l;
					while (l < r && nums[r] == nums[r - 1]) --r;
					++l, --r;
				} else {
					sum > 0 ? --r : ++l;
				}
			}
		}

		return result;
	}

	// Faster
	vector<vector<int>> threeSum2(vector<int> &nums) {
		int size = nums.size();

		vector<vector<int>> result;

		int map[200001] = {0};

		vector<int> positive, negative;

		for (int i = 0; i < size; ++i) {
			if (++map[100000 + nums[i]] > 1) continue;

			if (nums[i] > 0)
				positive.push_back(nums[i]);
			else if (nums[i] < 0)
				negative.push_back(nums[i]);
		}

		int pSize = positive.size();

		for (int i = 0; i < pSize; ++i) {
			for (int j = i + 1; j < pSize; ++j) {
				int sum = positive[i] + positive[j];
				if (sum < 100001 && map[100000 - sum] > 0)
					result.push_back({-sum, positive[i], positive[j]});
			}

			if (positive[i] < 50001 && map[100000 + positive[i]] > 1 && map[100000 - positive[i] * 2] > 0)
				result.push_back({-positive[i] * 2, positive[i], positive[i]});

			if (map[100000] > 0 && map[100000 - positive[i]] > 0)
				result.push_back({0, positive[i], -positive[i]});
		}

		int nSize = negative.size();

		for (int i = 0; i < nSize; ++i) {
			for (int j = i + 1; j < nSize; ++j) {
				int sum = negative[i] + negative[j];
				if (sum > -100001 && map[100000 - sum] > 0)
					result.push_back({-sum, negative[i], negative[j]});
			}

			if (negative[i] > -50001 && map[100000 + negative[i]] > 1 && map[100000 - negative[i] * 2] > 0)
				result.push_back({-negative[i] * 2, negative[i], negative[i]});
		}

		if (map[100000] > 2)
			result.push_back({0, 0, 0});

		return result;
	}
};

#endif //LEETCODE_15_3SUM_H
