//
// Created by jin on 9/8/2021.
//

#ifndef LEETCODE_140_WORD_BREAK_II_H
#define LEETCODE_140_WORD_BREAK_II_H

#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, vector<string> &wordDict) {
		vector<string> result = {""};
		vector<int> lastWordIdx = {0};
		unordered_set<string> set;

		int longest = 0;
		for (auto &word : wordDict) {
			set.insert(word);
			longest = max(longest, (int) word.size());
		}

		for (char &c : s) {
			int size = result.size();
			for (int i = 0; i < size; ++i) {
				auto &sentence = result[i];
				auto &idx = lastWordIdx[i];
				auto cnt = sentence.size() - idx;
				auto lastWord = sentence.substr(idx, cnt);

				if (set.count(lastWord) > 0) {
					string newSentence = sentence + " " + c;
					result.push_back(newSentence);
					lastWordIdx.push_back(idx + cnt + 1);
				}

				if (cnt > longest) {
					result[i] = "";
				} else {
					result[i].push_back(c);
				}
			}

			for (int i = size - 1; i >= 0; --i) {
				if (result[i].empty()) {
					result.erase(result.begin() + i);
					lastWordIdx.erase(lastWordIdx.begin() + i);
				}
			}
		}

		for (int i = result.size() - 1; i >= 0; --i) {
			auto &sentence = result[i];
			auto &idx = lastWordIdx[i];
			auto cnt = sentence.size() - idx;
			auto lastWord = sentence.substr(idx, cnt);

			if (set.count(lastWord) == 0) {
				result.erase(result.begin() + i);
			}
		}

		return result;
	}
};

#endif //LEETCODE_140_WORD_BREAK_II_H
