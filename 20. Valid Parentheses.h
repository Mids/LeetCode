//
// Created by jin on 2/23/2021.
//

#ifndef LEETCODE_20_VALID_PARENTHESES_H
#define LEETCODE_20_VALID_PARENTHESES_H

#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> parentheses;

		for (auto &c : s) {
			if (parentheses.empty()) {
				parentheses.push(c);
				continue;
			}
			switch (c) {
				case ')':
					if (parentheses.top() == '(')
						parentheses.pop();
					else
						return false;
					break;
				case '}':
				case ']':
					if (parentheses.top() == c - 2)
						parentheses.pop();
					else
						return false;
					break;
				default:
					parentheses.push(c);
					break;
			}
		}

		return parentheses.empty();
	}
};

#endif //LEETCODE_20_VALID_PARENTHESES_H
