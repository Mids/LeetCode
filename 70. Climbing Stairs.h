//
// Created by jin on 2/15/2021.
//

#ifndef LEETCODE_70_CLIMBING_STAIRS_H
#define LEETCODE_70_CLIMBING_STAIRS_H
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n < 4) return n;
		return climbStairs(n / 2) * climbStairs(n - n / 2) + climbStairs(n / 2 - 1) * climbStairs(n - n / 2 - 1);
	}
};

#endif //LEETCODE_70_CLIMBING_STAIRS_H
