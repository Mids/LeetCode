//
// Created by jin on 5/17/2021.
//

#ifndef LEETCODE_29_DIVIDE_TWO_INTEGERS_H
#define LEETCODE_29_DIVIDE_TWO_INTEGERS_H

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0 || divisor == 1) return dividend;
		if (divisor == -1) {
			if (dividend == INT_MIN) return INT_MAX;
			return -dividend;
		}
		long long x = dividend;
		long long y = divisor;

		x = x > 0 ? x : -x;
		y = y > 0 ? y : -y;

		int offset = 1;
		int result = 0;
		long long temp = 1;

		while (x >= y) {
			y <<= 1, temp <<= 1, ++offset;
		}
		y >>= 1, temp >>= 1, --offset;

		while (offset) {
			x -= y;
			if (x < 0) {
				x += y;
			} else {
				result += temp;
			}

			y >>= 1, temp >>= 1, --offset;
		}

		return result * ((divisor < 0) ^ (dividend < 0) ? -1 : 1);
	}
};

#endif //LEETCODE_29_DIVIDE_TWO_INTEGERS_H
