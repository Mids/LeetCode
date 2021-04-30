//
// Created by jin on 4/30/2021.
//

#ifndef LEETCODE_56_MERGE_INTERVALS_H
#define LEETCODE_56_MERGE_INTERVALS_H

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals) {
		vector<vector<int>> result = {intervals[0]};
		auto size = intervals.size();
		auto i = 0, j = 0;
		while (++i < size) {
			auto newInterval = intervals[i];
			for (j = result.size() - 1; j >= 0; --j) {
				if (result[j][1] >= newInterval[0] && result[j][0] <= newInterval[1]) {
					newInterval[0] = min(result[j][0], newInterval[0]);
					newInterval[1] = max(result[j][1], newInterval[1]);

					result.erase(result.begin() + j);
				}
			}
			result.push_back(newInterval);
		}
		return result;
	}
};

#endif //LEETCODE_56_MERGE_INTERVALS_H
