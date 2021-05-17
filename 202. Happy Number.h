//
// Created by jin on 5/17/2021.
//

#ifndef LEETCODE_202_HAPPY_NUMBER_H
#define LEETCODE_202_HAPPY_NUMBER_H

using namespace std;

#include <unordered_set>

class Solution {
public:
	unordered_set<int> set;

	bool isHappy(int n) {
		while (set.count(n) == 0) {
			if (n == 1) return true;

			set.insert(n);
			int sum = 0;
			while (n > 0) {
				auto c = n % 10;
				sum += c * c;
				n /= 10;
			}
			n = sum;
		}

		return false;
	}
};

#endif //LEETCODE_202_HAPPY_NUMBER_H
