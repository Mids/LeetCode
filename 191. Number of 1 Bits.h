//
// Created by jin on 2/23/2021.
//

#ifndef LEETCODE_191_NUMBER_OF_1_BITS_H
#define LEETCODE_191_NUMBER_OF_1_BITS_H

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int result = 0;

		while (n) {
			n &= (n - 1);
			result++;
		}

		return result;
	}

	int hammingWeight2(uint32_t n) {
		int result = 0;
		while (n != 0) {
			if (n % 2 == 1) {
				++result;
			}

			n /= 2;
		}
		return result;
	}
};

#endif //LEETCODE_191_NUMBER_OF_1_BITS_H
