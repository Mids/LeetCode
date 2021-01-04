//
// Created by Jin on 1/4/2021.
//

#ifndef LEETCODE_42_TRAPPING_RAIN_WATER_H
#define LEETCODE_42_TRAPPING_RAIN_WATER_H

using namespace std;

class Solution {
public:
	int trap(vector<int> &height) {
		int peak = 0;
		int sum = 0;

		for (int i = 0; i < height.size(); i++) {
			if (height[peak] < height[i]) {
				peak = i;
			}
		}
		int highest = 0;
		for (int i = 0; i < peak; i++) {
			if (height[i] > highest) {
				highest = height[i];
				continue;
			}

			sum += highest - height[i];
		}

		highest = 0;
		for (int i = height.size() - 1; i > peak; i--) {
			if (height[i] > highest) {
				highest = height[i];
				continue;
			}

			sum += highest - height[i];
		}

		return sum;
	}
};


#endif //LEETCODE_42_TRAPPING_RAIN_WATER_H
