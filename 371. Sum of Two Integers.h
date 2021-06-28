//
// Created by jin on 6/28/2021.
//

#ifndef LEETCODE_371_SUM_OF_TWO_INTEGERS_H
#define LEETCODE_371_SUM_OF_TWO_INTEGERS_H

using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		int carry;
		while (b != 0) {
			carry = a & b;
			a = a ^ b;
			b = ((carry & 0x7fffffff) << 1);
		}

		return a;
	}
};

#endif //LEETCODE_371_SUM_OF_TWO_INTEGERS_H
