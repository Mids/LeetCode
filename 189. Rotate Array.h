//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_189_ROTATE_ARRAY_H
#define LEETCODE_189_ROTATE_ARRAY_H

using namespace std;

class Solution {
public:
	void rotate(vector<int> &nums, int k) {
		int size = nums.size();
		vector<int> newNums(size);
		k %= size;

		for (auto v : nums) {
			if (k == size)
				k = 0;
			newNums[k++] = v;
		}

		nums.assign(newNums.begin(), newNums.end());
	}
};

#endif //LEETCODE_189_ROTATE_ARRAY_H
