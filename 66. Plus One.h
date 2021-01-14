//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_66_PLUS_ONE_H
#define LEETCODE_66_PLUS_ONE_H

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int size = digits.size();
		bool full = true;

		for (auto v : digits) {
			if (v != 9) {
				full = false;
				break;
			}
		}

		if (full) {
			digits[0] = 1;

			for (int i = 1; i < size; i++) {
				digits[i] = 0;
			}
			digits.push_back(0);
			return digits;
		}

		for (int i = size - 1; i >= 0; --i) {
			if (digits[i] != 9) {
				++digits[i];
				break;
			} else {
				digits[i] = 0;
			}
		}
		return digits;
	}
};

#endif //LEETCODE_66_PLUS_ONE_H
