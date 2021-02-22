//
// Created by jin on 2/22/2021.
//

#ifndef LEETCODE_326_POWER_OF_THREE_H
#define LEETCODE_326_POWER_OF_THREE_H

using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n == 0) return false;
		while (n % 3 == 0) {
			n /= 3;
		}
		return n == 1;
	}
};

#endif //LEETCODE_326_POWER_OF_THREE_H
