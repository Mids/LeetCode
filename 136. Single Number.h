//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_136_SINGLE_NUMBER_H
#define LEETCODE_136_SINGLE_NUMBER_H

#include<algorithm>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int size = nums.size();

		sort(nums.begin(), nums.end());

		for (int i = 1; i < size; i += 2) {
			if(nums[i-1] != nums[i])
				return nums[i-1];
		}

		return nums[size-1];
	}
};

#endif //LEETCODE_136_SINGLE_NUMBER_H
