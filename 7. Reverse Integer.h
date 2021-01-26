//
// Created by jin on 1/26/2021.
//

#ifndef LEETCODE_7_REVERSE_INTEGER_H
#define LEETCODE_7_REVERSE_INTEGER_H

#include <queue>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int result = 0;
		queue<int> num;

		int neg = x > 0 ? 1 : -1;
		if (x == INT_MIN) return 0;
		x *= neg;

		while (x > 0) {
			num.push(x % 10);
			x /= 10;
		}

		while (num.size() != 0) {
			if (result > INT_MAX / 10)
				return 0;
			result *= 10;
			result += num.front();
			num.pop();
		}

		result *= neg;

		return result;
	}
};

#endif //LEETCODE_7_REVERSE_INTEGER_H
