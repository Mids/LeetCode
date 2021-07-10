//
// Created by jin on 7/10/2021.
//

#ifndef LEETCODE_76_MINIMUM_WINDOW_SUBSTRING_H
#define LEETCODE_76_MINIMUM_WINDOW_SUBSTRING_H

using namespace std;

class Solution {
public:
	int map[100] = {0};

	string minWindow(string s, string t) {
		int size = s.size();

		for (auto c : s) {
			++map[c - 'A'];
		}

		for (auto c : t) {
			if (--map[c - 'A'] < 0)
				return "";
		}

		int end = size - 1;
		for (; end >= 0; --end) {
			if (map[s[end] - 'A'] == 0) break;
			--map[s[end] - 'A'];
		}

		int start = 0;
		for (auto c : s) {
			if (map[c - 'A'] == 0) break;
			--map[c - 'A'];
			++start;
		}

		int min = end - start + 1;
		int minStart = start;

		bool isDone = false;

		while (true) {
			while (true) {
				++end;
				if (end == size) {
					return s.substr(minStart, min);
				}
				++map[s[end] - 'A'];
				if (s[end] == s[start])
					break;
			}

			for (; start < end; ++start) {
				if (map[s[start] - 'A'] == 0)
					break;
				--map[s[start] - 'A'];
			}

			if (min > end - start + 1) {
				min = end - start + 1;
				minStart = start;
			}
		}

		return s.substr(minStart, min);
	}
};

#endif //LEETCODE_76_MINIMUM_WINDOW_SUBSTRING_H
