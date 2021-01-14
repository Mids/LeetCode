//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_350_INTERSECTION_OF_TWO_ARRAYS_II_H
#define LEETCODE_350_INTERSECTION_OF_TWO_ARRAYS_II_H

#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
		int size1 = nums1.size(), size2 = nums2.size();
		if (size1 == 0) return nums1;
		if (size2 == 0) return nums2;

		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		vector<int> result;
		int i1 = 0, i2 = 0;
		while (i1 < size1 && i2 < size2) {
			if (nums1[i1] > nums2[i2])
				++i2;
			else if (nums1[i1] < nums2[i2])
				++i1;
			else {
				result.push_back(nums1[i1]);
				++i1, ++i2;
			}
		}

		return result;
	}
};


#endif //LEETCODE_350_INTERSECTION_OF_TWO_ARRAYS_II_H
