//
// Created by jin on 1/26/2021.
//

#ifndef LEETCODE_8_STRING_TO_INTEGER_ATOI_H
#define LEETCODE_8_STRING_TO_INTEGER_ATOI_H

using namespace std;

class Solution {
public:
	int myAtoi(string s) {
		bool isReading = false;
		int result = 0, size = s.size();
		int neg = 1;

		for (auto c: s) {
			if (!isReading) {
				if (c == ' ') {
					continue;
				} else if (c == '-') {
					neg = -1;
					isReading = true;
					continue;
				} else if (c == '+') {
					isReading = true;
					continue;
				} else if ('9' < c || c < '0') {
					return result * neg;
				} else {
					isReading = true;
					result += c - '0';
				}
			} else {
				if (c < '0' || '9' < c)
					return result * neg;
				if (result > INT_MAX / 10) {
					if (neg == 1)
						return INT_MAX;
					else
						return INT_MIN;
				}
				result *= 10;

				if (result > INT_MAX - c + '0') {
					if (neg == 1)
						return INT_MAX;
					else
						return INT_MIN;
				}
				result += c - '0';
			}
		}

		return result * neg;
	}
};

#endif //LEETCODE_8_STRING_TO_INTEGER_ATOI_H
