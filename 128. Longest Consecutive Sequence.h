//
// Created by jin on 7/5/2021.
//

#ifndef LEETCODE_128_LONGEST_CONSECUTIVE_SEQUENCE_H
#define LEETCODE_128_LONGEST_CONSECUTIVE_SEQUENCE_H

#include <algorithm>
#include <unordered_set>

using namespace std;

// 64ms n but slower;;
class Solution {
public:
	int longestConsecutive(vector<int> &nums) {
		int size = nums.size();
		if (size < 2) return size;

		unordered_set<int> s(nums.begin(), nums.end());

		int count = 1;
		int result = 0;

		for (auto n : s) {
			if (s.count(n - 1) == 0) {
				while (s.count(++n) > 0) {
					++count;
				}

				result = max(result, count);
				count = 1;
			}
		}

		return result;
	}
};


// 24ms n log n
class Solution1 {
public:
	int longestConsecutive(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		int size = nums.size();
		if (size < 2) return size;

		int count = 1;
		int result = 0;
		for (int i = 1; i < size; ++i) {
			if (nums[i - 1] == nums[i]) continue;
			if (nums[i - 1] + 1 == nums[i]) {
				++count;
			} else {
				if (count > result) {
					result = count;
				}
				count = 1;
			}
		}
		if (count > result) {
			result = count;
		}

		return result;
	}
};

#endif //LEETCODE_128_LONGEST_CONSECUTIVE_SEQUENCE_H
