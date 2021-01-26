//
// Created by jin on 1/26/2021.
//

#ifndef LEETCODE_14_LONGEST_COMMON_PREFIX_H
#define LEETCODE_14_LONGEST_COMMON_PREFIX_H

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string result = "";
		int end = 0;

		int size = strs.size();

		if (size == 0) return "";
		if (size == 1) return strs[0];

		int minSize = strs[0].size();
		for (int j = 1; j < size; ++j) {
			int sSize = strs[j].size();
			if (sSize < minSize) {
				minSize = sSize;
			}
		}

		for (int i = 0; i < minSize; ++i) {
			char c = strs[0][i];

			for (int j = 1; j < size; ++j) {
				if (c != strs[j][i])
					return strs[0].substr(0, end);
			}

			++end;
		}

		return strs[0].substr(0, end);
	}
};

#endif //LEETCODE_14_LONGEST_COMMON_PREFIX_H
