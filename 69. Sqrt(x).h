//
// Created by jin on 5/17/2021.
//

#ifndef LEETCODE_69_SQRT_X_H
#define LEETCODE_69_SQRT_X_H

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x < 2) return x;
		long long result = 0;
		int offset = 1 << 16;

		while (offset) {
			result += offset;
			if (result * result > x) {
				result -= offset;
			}

			offset >>= 1;
		}

		return result;
	}
};

#endif //LEETCODE_69_SQRT_X_H
