//
// Created by jin on 1/7/2021.
//

#ifndef LEETCODE_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define LEETCODE_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int map[256] = {0};
		int temp = 0;
		int result = 0;

		if (s.size() == 0) return 0;

		int start = 0, end = 0;

		while (s[end] != 0) {
			int startChar = s[start];
			int endChar = s[end];
			if (map[endChar] != 0) {
				map[startChar] = 0;
				start++;
				temp--;
			} else {
				map[endChar] = 1;
				end++;
				temp++;
			}

			if (result < temp)
				result = temp;
		}

		return result;
	}
};

#endif //LEETCODE_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
