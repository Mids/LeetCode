//
// Created by jin on 2/15/2021.
//

#ifndef LEETCODE_278_FIRST_BAD_VERSION_H
#define LEETCODE_278_FIRST_BAD_VERSION_H

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version) {
	if (version < 4) return false;
	return true;
}

class Solution {
public:
	int firstBadVersion(int n) {
		int start = 0, end = n;
		int mid;
		while (start < end) {
			mid = start / 2 + end / 2;
			if (isBadVersion(mid)) {
				end = mid;
			} else {
				start = mid + 1;
			}
		}

		return start;
	}
};

#endif //LEETCODE_278_FIRST_BAD_VERSION_H
