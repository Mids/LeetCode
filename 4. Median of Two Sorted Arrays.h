//
// Created by Jin on 8/27/2021.
//

#ifndef LEETCODE_4_MEDIAN_OF_TWO_SORTED_ARRAYS_H
#define LEETCODE_4_MEDIAN_OF_TWO_SORTED_ARRAYS_H

#include <climits>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

		if (nums1.size() > nums2.size())
			nums1.swap(nums2);

		int n1 = nums1.size(), n2 = nums2.size();

		int l = 0, h = n1;

		while (l <= h) {

			int i1 = (l + h) / 2;
			int i2 = (n1 + n2 + 1) / 2 - i1;

			int max1 = (i1 == 0 ? INT_MIN : nums1[i1 - 1]);
			int max2 = (i2 == 0 ? INT_MIN : nums2[i2 - 1]);

			int min1 = (i1 == n1 ? INT_MAX : nums1[i1]);
			int min2 = (i2 == n2 ? INT_MAX : nums2[i2]);

			double maxl = max(max1, max2);
			double minr = min(min1, min2);

			if (maxl <= minr) {
				if ((n1 + n2) % 2 == 0)
					return (maxl + minr) / 2;
				return maxl;
			} else if (min1 < max2)
				l = i1 + 1;
			else
				h = i1 - 1;
		}
		return 0;
	}
};

#endif //LEETCODE_4_MEDIAN_OF_TWO_SORTED_ARRAYS_H
