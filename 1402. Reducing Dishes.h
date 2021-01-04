//
// Created by jin on 1/4/2021.
//

#ifndef LEETCODE_1402_REDUCING_DISHES_H
#define LEETCODE_1402_REDUCING_DISHES_H

#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSatisfaction(vector<int> &satisfaction) {
		int partSum = 0;
		int sum = 0;

		sort(satisfaction.begin(), satisfaction.end());

		for (int i = satisfaction.size() - 1; i >= 0; i--) {
			partSum += satisfaction[i];

			if (partSum <= 0) {
				break;
			}

			sum += partSum;
		}

		return sum;
	}

	static bool desc(int i, int j) { return i > j; }
};

#endif //LEETCODE_1402_REDUCING_DISHES_H
