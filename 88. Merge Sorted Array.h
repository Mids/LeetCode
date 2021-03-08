//
// Created by jin on 1/11/2021.
//

#ifndef LEETCODE_88_MERGE_SORTED_ARRAY_H
#define LEETCODE_88_MERGE_SORTED_ARRAY_H

using namespace std;

class Solution {
public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;

		while (j >= 0)
			nums1[k--] = i < 0 || nums1[i] < nums2[j] ? nums2[j--] : nums1[i--];
	}

//	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
//		if (!n) return;
//		int size = m + n;
//		auto it1 = nums1.begin(), it2 = nums2.begin();
//		vector<int> newNums(size);
//		auto newNumsIt = newNums.begin();
//		while (m > 0 && it2 != nums2.end()) {
//			if (*it1 < *it2) {
//				*newNumsIt++ = *it1++;
//				--m;
//			} else {
//				*newNumsIt++ = *it2++;
//			}
//		}
//
//		while (*it1 != 0) {
//			*newNumsIt++ = *it1++;
//		}
//		while (it2 != nums2.end()) {
//			*newNumsIt++ = *it2++;
//		}
//
//		nums1.assign(newNums.begin(), newNums.end());
//	}
};

#endif //LEETCODE_88_MERGE_SORTED_ARRAY_H
