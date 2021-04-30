//
// Created by jin on 4/30/2021.
//

#ifndef LEETCODE_34_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
#define LEETCODE_34_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H

using namespace std;

class Solution {
public:
	int start, mid, end, size;

	vector<int> searchRange(vector<int> &nums, int target) {
		size = nums.size();
		vector<int> result = {-1, -1};

		start = 0, end = size;
		while (start < end) {
			mid = (start + end) / 2;

			if (nums[mid] > target) {
				end = mid;
			} else if (nums[mid] < target) {
				start = mid + 1;
			} else {
				result[0] = mid;
				end = mid;
			}
		}

		start = 0, end = size;
		while (start < end) {
			mid = (start + end) / 2;

			if (nums[mid] > target) {
				end = mid;
			} else if (nums[mid] < target) {
				start = mid + 1;
			} else {
				result[1] = mid;
				start = mid + 1;
			}
		}

		return result;
	}
};


class Solution2 {
public:
	int start, end;

	vector<int> searchRange(vector<int> &nums, int target) {
		auto size = nums.size();
		vector<int> result = {-1, -1};
		if (size == 0) return result;
		start = 0;
		end = size - 1;

		if (nums[start] > target || nums[end] < target) {
			return result;
		}

		while (nums[start] != nums[end]) {
			auto mid = (start + end) / 2;

			if (nums[mid] > target) {
				end = mid - 1;
			} else if (nums[mid] < target) {
				start = mid + 1;
			} else if (nums[start] == target) {
				end = mid;
				break;
			} else if (nums[end] == target) {
				start = mid;
				break;
			} else {
				start = (start + mid) / 2;
				end = (mid + end) / 2;
			}
		}

		if (nums[start] != target) {
			return result;
		}

		while (start > 0 && nums[start - 1] == target) {
			--start;
		}
		while (end < size - 1 && nums[end + 1] == target) {
			++end;
		}

		result[0] = start;
		result[1] = end;

		return result;
	}
};

#endif //LEETCODE_34_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
