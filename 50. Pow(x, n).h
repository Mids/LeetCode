//
// Created by jin on 5/17/2021.
//

#ifndef LEETCODE_50_POW_X_N_H
#define LEETCODE_50_POW_X_N_H

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		double result = 1;
		long long nn = n;
		if (nn < 0) {
			nn = -nn;
			x = 1 / x;
		}

		while (nn) {
			if (nn & 1)
				result *= x;
			x *= x;
			nn >>= 1;
		}
		return result;
	}
};

#endif //LEETCODE_50_POW_X_N_H
