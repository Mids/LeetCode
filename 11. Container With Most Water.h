//
// Created by jin on 7/10/2021.
//

#ifndef LEETCODE_11_CONTAINER_WITH_MOST_WATER_H
#define LEETCODE_11_CONTAINER_WITH_MOST_WATER_H

using namespace std;

class Solution {
public:
	int maxArea(vector<int> &height) {
		int size = height.size();
		int start = 0, end = size - 1;
		int max = 0;
		int exHeight = 0;

		while (start < end) {
			int area = (end - start);
			if (height[start] < height[end]) {
				exHeight = height[start];
				area *= exHeight;
				while (start < end && height[start] <= exHeight)
					++start;
			} else {
				exHeight = height[end];
				area *= height[end];
				while (start < end && height[end] <= exHeight)
					--end;
			}

			if (area > max)
				max = area;
		}

		return max;
	}
};

#endif //LEETCODE_11_CONTAINER_WITH_MOST_WATER_H
