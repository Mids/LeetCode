//
// Created by jin on 9/26/2021.
//

#ifndef LEETCODE_84_LARGEST_RECTANGLE_IN_HISTOGRAM_H
#define LEETCODE_84_LARGEST_RECTANGLE_IN_HISTOGRAM_H

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &heights) {
		return getMax(heights, 0, heights.size() - 1);
	}


	int getMax(vector<int> &heights, int start, int end) {
		if (start == end) return heights[start];

		int newLow = INT_MAX;

		for (int i = start; i <= end; ++i) {
			if (newLow > heights[i])
				newLow = heights[i];
		}

		int Max = (end - start + 1) * newLow;
		for (int i = start; i <= end; ++i) {
			if (heights[i] == newLow) {
				int subMax = getMax(heights, start, i - 1);
				Max = max(Max, subMax);
				start = i + 1;
			} else if (i == end) {
				int subMax = getMax(heights, start, i);
				Max = max(Max, subMax);
				break;
			}
		}

		return Max;
	}
};

#endif //LEETCODE_84_LARGEST_RECTANGLE_IN_HISTOGRAM_H
