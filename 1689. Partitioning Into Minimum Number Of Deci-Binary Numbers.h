//
// Created by jin on 1/4/2021.
//

#ifndef LEETCODE_1689_PARTITIONING_INTO_MINIMUM_NUMBER_OF_DECI_BINARY_NUMBERS_H
#define LEETCODE_1689_PARTITIONING_INTO_MINIMUM_NUMBER_OF_DECI_BINARY_NUMBERS_H

using namespace std;

class Solution {
public:
	int minPartitions(string n) {
		for (char c:n) {
			if (c > n[0])
				n[0] = c;
		}
		return n[0] - '0';
	}
};

#endif //LEETCODE_1689_PARTITIONING_INTO_MINIMUM_NUMBER_OF_DECI_BINARY_NUMBERS_H
