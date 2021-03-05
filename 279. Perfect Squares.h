//
// Created by jin on 3/5/2021.
//

#ifndef LEETCODE_279_PERFECT_SQUARES_H
#define LEETCODE_279_PERFECT_SQUARES_H

using namespace std;

class Solution {
public:
	int numSquares(int n) {
		if (n < 4) return n;

		vector<int> array(n + 1);
		array[1] = 1;

		for (int i = 2; i <= n; ++i) {
			int min = array[i - 1] + 1;

			for (int j = 2; j * j <= i; ++j) {
				int left = i - j * j;

				if (min > array[left])
					min = array[left] + 1;
			}

			array[i] = min;
		}

		return array[n];
	}
};

#endif //LEETCODE_279_PERFECT_SQUARES_H
