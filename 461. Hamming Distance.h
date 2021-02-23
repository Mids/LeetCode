//
// Created by jin on 2/23/2021.
//

#ifndef LEETCODE_461_HAMMING_DISTANCE_H
#define LEETCODE_461_HAMMING_DISTANCE_H

using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int result = 0;
		x ^= y;

		while (x) {
			x &= x - 1;
			++result;
		}

		return result;
	}
};

#endif //LEETCODE_461_HAMMING_DISTANCE_H
