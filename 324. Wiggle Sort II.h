//
// Created by Jin on 8/27/2021.
//

#ifndef LEETCODE_324_WIGGLE_SORT_II_H
#define LEETCODE_324_WIGGLE_SORT_II_H

#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> cp(nums);
		sort(cp.begin(), cp.end());

		for(int i = 0, j = nums.size() - 1, mid = j /2 + 1; j>=0; --j){
			nums[j] = cp[j%2 ? mid++ : i++];

		}
	}
};


#endif //LEETCODE_324_WIGGLE_SORT_II_H
