//
// Created by jin on 3/17/2021.
//

#ifndef LEETCODE_49_GROUP_ANAGRAMS_H
#define LEETCODE_49_GROUP_ANAGRAMS_H

#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
	// 20ms
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		unordered_map<string, vector<string>> map;
		vector<vector<string>> result;

		for (auto &str : strs) {
			int abcMap[26] = {0};

			for (auto &c:str) {
				++abcMap[c - 'a'];
			}

			string key;
			for (int i = 0; i < 26; ++i) {
				if (abcMap[i]) {
					key += string(abcMap[i], (i + 'a'));
				}
			}

			map[key].push_back(str);
		}

		for (const auto &kvp : map) {
			result.push_back(kvp.second);
		}

		return result;
	}

	// 28ms
	vector<vector<string>> groupAnagrams3(vector<string> &strs) {
		int size = strs.size();
		unordered_map<string, vector<string>> map;
		vector<vector<string>> result;

		for (int i = 0; i < size; ++i) {
			string str = strs[i];
			sort(str.begin(), str.end());
			if (map.count(str) == 0) {
				vector<string> vec;
				map[str] = vec;
			}

			map[str].push_back(strs[i]);
		}

		for (const auto &kvp : map) {
			result.push_back(kvp.second);
		}

		return result;
	}

	// 500ms
	vector<vector<string>> groupAnagrams2(vector<string> &strs) {
		int size = strs.size();
		int check[10001] = {0};
		int checkTable[10001][26] = {0};

		vector<vector<string>> result;
		for (int i = 0; i < size; ++i) {
			for (auto &c : strs[i]) {
				++checkTable[i][c - 'a'];
			}
		}

		for (int i = 0; i < size; ++i) {
			if (check[i] == 1) continue;
			check[i] = 1;
			vector<string> vec;
			vec.push_back(strs[i]);

			for (int j = i + 1; j < size; ++j) {
				if (check[j] == 1) continue;

				bool dup = true;
				for (int k = 0; k < 26; ++k) {
					if (checkTable[i][k] != checkTable[j][k]) {
						dup = false;
						break;
					}
				}

				if (dup) {
					check[j] = 1;
					vec.push_back(strs[j]);
				}
			}

			result.push_back(vec);
		}

		return result;
	}
};

#endif //LEETCODE_49_GROUP_ANAGRAMS_H
