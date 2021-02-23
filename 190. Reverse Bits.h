//
// Created by jin on 2/23/2021.
//

#ifndef LEETCODE_190_REVERSE_BITS_H
#define LEETCODE_190_REVERSE_BITS_H

using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		int result = 0;
		for (int i = 0; i < 32; ++i) {
			result <<= 1;
			result += n % 2;
			n >>= 1;
		}

		return result;
	}
};

#endif //LEETCODE_190_REVERSE_BITS_H
