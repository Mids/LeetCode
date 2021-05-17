//
// Created by jin on 5/17/2021.
//

#ifndef LEETCODE_172_FACTORIAL_TRAILING_ZEROES_H
#define LEETCODE_172_FACTORIAL_TRAILING_ZEROES_H

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int result = 0;

		while (n >= 5) {
			n /= 5;
			result += n;
		}

		return result;
	}
};


#endif //LEETCODE_172_FACTORIAL_TRAILING_ZEROES_H
