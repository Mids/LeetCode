//
// Created by jin on 1/26/2021.
//

#ifndef LEETCODE_344_REVERSE_STRING_H
#define LEETCODE_344_REVERSE_STRING_H

#include <algorithm>

using namespace std;

class Solution {
public:
	void reverseString(vector<char> &s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			swap(s[i++], s[j--]);
		}
	}
};

#endif //LEETCODE_344_REVERSE_STRING_H
