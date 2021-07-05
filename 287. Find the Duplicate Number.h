//
// Created by jin on 7/5/2021.
//

#ifndef LEETCODE_287_FIND_THE_DUPLICATE_NUMBER_H
#define LEETCODE_287_FIND_THE_DUPLICATE_NUMBER_H

#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int> &nums) {
		int slow = nums[0];
		int fast = nums[nums[0]];

		while (slow != fast) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		slow = nums[slow];
		fast = nums[0];

		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}

		return slow;
	}
};

#endif //LEETCODE_287_FIND_THE_DUPLICATE_NUMBER_H
