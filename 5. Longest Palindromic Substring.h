//
// Created by jin on 3/17/2021.
//

#ifndef LEETCODE_5_LONGEST_PALINDROMIC_SUBSTRING_H
#define LEETCODE_5_LONGEST_PALINDROMIC_SUBSTRING_H

using namespace std;

class Solution {
public:
	// 0 ms
	string longestPalindrome(string s) {
		int size = s.size();
		int resultOffset = 0;
		int longest = 1;
		int l, r, i = 0;
		while (i < size) {
			l = r = i;
			while (s[l] == s[r]) ++r;
			--l, i = r;


			while (l >= 0 && s[l] == s[r]) --l, ++r;
			++l, --r;

			if (r - l + 1 > longest) {
				resultOffset = l;
				longest = r - l + 1;
			}
		}

		return s.substr(resultOffset, longest);
	}

	// 20ms
	string longestPalindrome2(string s) {
		int size = s.size();
		int resultOffset = 0;
		int longest = 1;
		for (int i = 0; i < size; ++i) {
			// odd
			for (int j = 1; i + j < size && i - j >= 0; ++j) {
				if (s[i - j] == s[i + j]) {
					if (j * 2 + 1 > longest) {
						longest = j * 2 + 1;
						resultOffset = i - j;
					}
				} else {
					break;
				}
			}

			// even
			for (int j = 1; i + j < size && i - j + 1 >= 0; ++j) {
				if (s[i - j + 1] == s[i + j]) {
					if (j * 2 > longest) {
						longest = j * 2;
						resultOffset = i - j + 1;
					}
				} else {
					break;
				}
			}
		}

		return s.substr(resultOffset, longest);
	}
};

#endif //LEETCODE_5_LONGEST_PALINDROMIC_SUBSTRING_H
