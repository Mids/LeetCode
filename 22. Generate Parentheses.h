//
// Created by jin on 4/12/2021.
//

#ifndef LEETCODE_22_GENERATE_PARENTHESES_H
#define LEETCODE_22_GENERATE_PARENTHESES_H

#include <stack>

using namespace std;

// 0ms & 7.2MB
class Solution {
public:
	vector<int> result;

	vector<string> generateParenthesis(int n) {
		Check(1, n - 1, n - 1);

		vector<string> res(result.size());

		auto bitSize = 2 * n;
		auto pow = 1 << (bitSize - 1);

		char *s = static_cast<char *>(malloc(sizeof(char) * (bitSize + 1)));

		for (auto i = 0; i < result.size(); ++i) {
			auto temp = pow;
			for (auto j = 0; j < bitSize; ++j) {
				if (result[i] >= temp) {
					result[i] -= temp;
					s[j] = '(';
				} else {
					s[j] = ')';
				}

				temp >>= 1;
			}
			s[bitSize] = 0;
			res[i] = s;
		}

		return res;
	}

	void Check(int s, int left, int right) {
		if (!left && !right) result.push_back(s << 1);

		if (left) {
			Check((s << 1) + 1, left - 1, right);
		}

		if (left <= right) {
			Check(s << 1, left, right - 1);
		}
	}
};


// 4ms & 14MB
class Solution2 {
public:
	vector<string> result;

	vector<string> generateParenthesis(int n) {
		string cur = "";
		int close = 0;

		Check("(", n - 1, n);

		return result;
	}

	void Check(string s, int left, int right) {
		if (!left && !right) result.push_back(s);

		if (left) {
			Check(s + '(', left - 1, right);
		}

		if (left < right) {
			Check(s + ')', left, right - 1);
		}

	}
};

#endif //LEETCODE_22_GENERATE_PARENTHESES_H
