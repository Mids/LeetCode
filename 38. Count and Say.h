//
// Created by jin on 1/26/2021.
//

#ifndef LEETCODE_38_COUNT_AND_SAY_H
#define LEETCODE_38_COUNT_AND_SAY_H

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string s = "1";

		for (int i = 1; i < n; ++i) {
			s = countAndSay(s);
		}

		return s;
	}

	string countAndSay(string s) {
		if (s == "1") return "11";

		int size = s.size();

		int cnt = 1;
		char cur = s[0];
		string result = "";
		for (int i = 1; i < size; ++i) {
			if (s[i - 1] == s[i]) {
				++cnt;
			} else {
				result.append(1, (cnt + '0'));
				result.append(1, cur);
				cur = s[i];
				cnt = 1;
			}
		}

		result.append(1, (cnt + '0'));
		result.append(1, cur);

		return result;
	}
};

#endif //LEETCODE_38_COUNT_AND_SAY_H
