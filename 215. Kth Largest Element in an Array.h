//
// Created by jin on 4/30/2021.
//

#ifndef LEETCODE_215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H
#define LEETCODE_215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H

#include <map>
#include <queue>

using namespace std;

// 4ms
class Solution {
public:
	int findKthLargest(vector<int> &nums, int k) {
		priority_queue<int, vector<int>, greater<>> pq;
		int i = 0, size = nums.size();
		for (; i < k; ++i) {
			pq.push(nums[i]);
		}
		for (; i < size; ++i) {
			pq.push(nums[i]);
			pq.pop();
		}

		return pq.top();
	}
};

// 20ms
class Solution2 {
public:
	int findKthLargest(vector<int> &nums, int k) {
		map<int, int, greater<>> sorted_map;

		for (auto &n : nums) {
			if (sorted_map.count(n) == 0) {
				sorted_map[n] = 1;
			} else {
				++sorted_map[n];
			}
		}

		for (auto &kvp : sorted_map) {
			k -= kvp.second;
			if (k == 0) {
				return kvp.first;
			}
		}

		return 0;
	}
};

#endif //LEETCODE_215_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H
