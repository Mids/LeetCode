//
// Created by jin on 4/30/2021.
//

#ifndef LEETCODE_162_FIND_PEAK_ELEMENT_H
#define LEETCODE_162_FIND_PEAK_ELEMENT_H

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int> &nums, int start = 0, int end = -1) {
		if (end == -1) end = nums.size() - 1;

		if (end - start <= 1) return nums[start] > nums[end] ? start : end;

		auto mid = (start + end) / 2;

		if (nums[start] > nums[mid]) {
			return findPeakElement(nums, start, mid - 1);
		} else if (nums[mid] < nums[end]) {
			return findPeakElement(nums, mid + 1, end);
		}

		auto startMidPeak = findPeakElement(nums, start, mid);
		auto midEndPeak = findPeakElement(nums, mid, end);

		return nums[startMidPeak] > nums[midEndPeak] ? startMidPeak : midEndPeak;
	}
};


class Solution2 {
public:
	int findPeakElement(vector<int> &nums) {
		int max = INT_MIN, maxIndex = 0;

		for (auto i = 0; i < nums.size(); ++i) {
			if (max < nums[i]) {
				max = nums[i];
				maxIndex = i;
			}
		}

		return maxIndex;
	}
};

#endif //LEETCODE_162_FIND_PEAK_ELEMENT_H
