//
// Created by jin on 8/5/2021.
//

#ifndef LEETCODE_131_PALINDROME_PARTITIONING_H
#define LEETCODE_131_PALINDROME_PARTITIONING_H

using namespace std;

class Solution {
public:
	string str;
	int stringSize;
	vector<vector<string>> result;

	vector<vector<string>> partition(string s) {
		str = s;

		stringSize = s.size();

		vector<string> v;

		addEnd(0, v);

		return result;
	}

	void addEnd(int si, vector<string> &v) {
		for (int i = si; i < stringSize; ++i) {
			if (!isPalindrome(si, i)) continue;

			string n(&str[si], &str[i] + 1);
			v.emplace_back(n);
			if (i == stringSize - 1) {
				result.emplace_back(v);
			} else {
				addEnd(i + 1, v);
			}
			v.pop_back();
		}
	}

	bool isPalindrome(int si, int ei) {
		bool p = true;
		while (si <= ei) {
			if (str[si++] != str[ei--]) {
				p = false;
				break;
			}
		}

		return p;
	}
};

#endif //LEETCODE_131_PALINDROME_PARTITIONING_H
