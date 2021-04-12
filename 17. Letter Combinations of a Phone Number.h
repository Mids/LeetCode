//
// Created by jin on 4/12/2021.
//

#ifndef LEETCODE_17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#define LEETCODE_17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.empty()) return result;

		result.emplace_back("");

		for (auto c : digits) {
			auto s = GetString(c);

			auto temp = result;

			result.resize(result.size() * s.size());
			for (int i = 0; i < temp.size(); ++i) {
				for (int j = 0; j < s.size(); ++j) {
					result[i * s.size() + j] = temp[i] + s[j];
				}
			}
		}

		return result;
	}

	string GetString(char c) {
		switch (c) {
			case '2':
				return "abc";
			case '3':
				return "def";
			case '4':
				return "ghi";
			case '5':
				return "jkl";
			case '6':
				return "mno";
			case '7':
				return "pqrs";
			case '8':
				return "tuv";
			case '9':
				return "wxyz";
		}
		return "";
	}
};

#endif //LEETCODE_17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
