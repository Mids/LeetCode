//
// Created by jin on 1/26/2021.
//

#ifndef LEETCODE_125_VALID_PALINDROME_H
#define LEETCODE_125_VALID_PALINDROME_H

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int i = 0, j = s.size() - 1;

		while (i < j) {
			if ('A' <= s[i] && s[i] <= 'Z')
				s[i] += 32;

			if ('A' <= s[j] && s[j] <= 'Z')
				s[j] += 32;

			if (isInvalid(s[i])) {
				++i;
				continue;
			}
			if (isInvalid(s[j])) {
				--j;
				continue;
			}

			if (s[i++] != s[j--])
				return false;
		}

		return true;
	}

	bool isInvalid(char c){
		return (c < 'a' || 'z' < c) && (c < '0' || '9' < c);
	}
};

#endif //LEETCODE_125_VALID_PALINDROME_H
