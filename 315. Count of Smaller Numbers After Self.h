//
// Created by Jin on 8/1/2021.
//

#ifndef LEETCODE_315_COUNT_OF_SMALLER_NUMBERS_AFTER_SELF_H
#define LEETCODE_315_COUNT_OF_SMALLER_NUMBERS_AFTER_SELF_H

using namespace std;

#include <map>
#include <set>
#include <algorithm>

class Solution {
public:
#define iterator vector<pair<int, int>>::iterator
	vector<pair<int, int>> hold;
	vector<pair<int, int>> hold2;

	void sort_count(iterator l, iterator r, vector<int> &count) {
		if (r - l <= 1) return;
		auto m = l + (r - l) / 2;

		sort_count(l, m, count);
		sort_count(m, r, count);

		while ((*l).first <= (*m).first && l < m)
			++l;

		auto start = l - hold.begin();
		int idx = start;

		auto i = l, j = m;
		for (; i < m; i++) {
			while (j < r && (*i).first > (*j).first) {
				hold2[idx++] = *j;
				j++;
			}
			hold2[idx++] = *i;
			count[(*i).second] += j - m;
		}

		copy(hold2.begin() + start, hold2.begin() + (j - hold.begin()), l);
	}

	vector<int> countSmaller(vector<int> &nums) {
		int n = nums.size();
		hold.resize(n);
		hold2.resize(n);
		for (int i = 0; i < n; ++i)
			hold[i] = {nums[i], i};
		vector<int> count(n, 0);

		sort_count(hold.begin(), hold.end(), count);
		return count;
	}
};

#endif //LEETCODE_315_COUNT_OF_SMALLER_NUMBERS_AFTER_SELF_H
