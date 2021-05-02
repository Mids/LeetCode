//
// Created by Jin on 5/2/2021.
//

#ifndef LEETCODE_33_SEARCH_IN_ROTATED_SORTED_ARRAY_H
#define LEETCODE_33_SEARCH_IN_ROTATED_SORTED_ARRAY_H

using namespace std;

// iterative
class Solution {
public:
	int search(vector<int> &nums, int target) {
		int start = 0, end = nums.size() - 1;

		while (start <= end) {
			auto mid = (start + end) / 2;

			if (nums[start] == target) return start;
			if (nums[end] == target) return end;
			if (nums[mid] == target) return mid;

			if (nums[start] < target && target < nums[mid] ||
				nums[mid] < nums[start] && (nums[start] < target || target < nums[mid])) {
				++start;
				end = mid - 1;
			} else {
				start = mid + 1;
				--end;
			}
		}

		return -1;
	}
};

// recursive
class Solution2 {
public:
	int search(vector<int> &nums, int target) {
		return search(nums, target, 0, nums.size() - 1);
	}

	int search(vector<int> &nums, int target, int start, int end) {
		if (start > end) return -1;

		auto mid = (start + end) / 2;

		if (nums[start] == target) return start;
		if (nums[end] == target) return end;
		if (nums[mid] == target) return mid;

		if (nums[start] < target && target < nums[mid] ||
			nums[mid] < nums[start] && (nums[start] < target || target < nums[mid])) {
			return search(nums, target, start + 1, mid - 1);
		}

		return search(nums, target, mid + 1, end - 1);
	}
};

#endif //LEETCODE_33_SEARCH_IN_ROTATED_SORTED_ARRAY_H
