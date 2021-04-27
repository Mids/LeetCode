//
// Created by jin on 4/26/2021.
//

#ifndef LEETCODE_347_TOP_K_FREQUENT_ELEMENTS_H
#define LEETCODE_347_TOP_K_FREQUENT_ELEMENTS_H

#include <unordered_map>
#include <queue>

using namespace std;

// 4ms 99.97%
class Solution {
public:
	vector<int> topKFrequent(vector<int> &nums, int k) {
		unordered_map<int, int> map;
		vector<int> result(k);
		auto cmp = [](pair<int, int> &left, pair<int, int> &right) { return left.second < right.second; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

		for (auto n : nums) {
			++map[n];
		}


		for (auto const &kvp : map) {
			pq.push(kvp);
		}

		for (auto i = 0; i < k; ++i) {
			result[i] = pq.top().first;
			pq.pop();
		}

		return result;
	}
};

#endif //LEETCODE_347_TOP_K_FREQUENT_ELEMENTS_H
