//
// Created by jin on 1/26/2021.
//

#ifndef LEETCODE_387_FIRST_UNIQUE_CHARACTER_IN_A_STRING_H
#define LEETCODE_387_FIRST_UNIQUE_CHARACTER_IN_A_STRING_H

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		int size = s.size(), map[26] = {0};
		for (auto c : s) {
			++map[c - 'a'];
		}

		for (int i = 0; i < size; ++i) {
			if (map[s[i] - 'a'] == 1) return i;
		}
		return -1;
	}
};

#endif //LEETCODE_387_FIRST_UNIQUE_CHARACTER_IN_A_STRING_H
