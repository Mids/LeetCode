//
// Created by jin on 7/10/2021.
//

#ifndef LEETCODE_239_SLIDING_WINDOW_MAXIMUM_H
#define LEETCODE_239_SLIDING_WINDOW_MAXIMUM_H

#include <deque>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		deque<int> dq;
		int size = nums.size();
		vector<int> result;
		result.reserve(size - k + 1);

		for (int i = 0; i < size; ++i) {
			int v = nums[i];

			while (!dq.empty() && nums[dq.back()] < v) {
				dq.pop_back();
			}

			dq.push_back(i);

			if(i>=k-1)
			{
				result.push_back(nums[dq.front()]);
				if(dq.front() == i - k + 1)
					dq.pop_front();
			}
		}

		return result;
	}
};

#endif //LEETCODE_239_SLIDING_WINDOW_MAXIMUM_H
