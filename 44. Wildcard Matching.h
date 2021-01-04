//
// Created by jin on 1/4/2021.
//

#ifndef LEETCODE_44_WILDCARD_MATCHING_H
#define LEETCODE_44_WILDCARD_MATCHING_H

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int sSize = s.size();
		int pSize = p.size();

		if (sSize == 0 && pSize == 0) return true;

		int i = 0;

		bool endStar = false;
		int beforeStar = -1;
		int beforeI = -1;

		bool result = false;

		for (int j = 0; j < pSize || i < sSize; j++) {

			if (i == sSize && p[j] != '*') {
				result = false;
				continue;
			}

			if (j == pSize && beforeStar != -1) {
				j = beforeStar;
				i = ++beforeI;
				continue;
			}
			endStar = false;

			if (p[j] == '*') {
				if (j != 0 && !result) {
					return false;
				}
				result = true;
				endStar = true;
				beforeStar = j;
				beforeI = i;
				continue;
			} else if (p[j] == '?') {
				if (i == 0) {
					result = true;
				} else if (!result) {
					return false;
				}
				i++;
				continue;
			} else {
				if (s[i] == p[j]) {
					i++;
					result = true;
				} else if (beforeStar != -1) {
					j = beforeStar;
					i = ++beforeI;
				} else {
					return false;
				}
			}
		}

		if (i != sSize && !endStar)
			result = false;

		return result;
	}
};

#endif //LEETCODE_44_WILDCARD_MATCHING_H
