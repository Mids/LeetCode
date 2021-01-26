//
// Created by jin on 1/26/2021.
//

#ifndef LEETCODE_28_IMPLEMENT_STRSTR_H
#define LEETCODE_28_IMPLEMENT_STRSTR_H

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int haySize = haystack.size();
		int needleSize = needle.size();

		if (needleSize == 0) return 0;

		for (int i = 0; i <= haySize - needleSize; ++i) {
			int j = i;
			int ii = 0;
			while (ii < needleSize && j != haySize && haystack[j] == needle[ii]) {
				++ii, ++j;
			}

			if (ii == needleSize)
				return i;
		}

		return -1;
	}
};

#endif //LEETCODE_28_IMPLEMENT_STRSTR_H
