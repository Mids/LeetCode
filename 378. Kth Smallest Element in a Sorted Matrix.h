//
// Created by Jin on 8/27/2021.
//

#ifndef LEETCODE_378_KTH_SMALLEST_ELEMENT_IN_A_SORTED_MATRIX_H
#define LEETCODE_378_KTH_SMALLEST_ELEMENT_IN_A_SORTED_MATRIX_H

using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>> &matrix, int k) {
		int n = matrix.size();
		int low = matrix[0][0], high = matrix[n - 1][n - 1];

		vector<int> lowRow(n, 0);
		vector<int> midRow(n);
		vector<int> highRow(n, n);

		int lowCol = 0;
		int highCol = n;

		while (low < high) {
			int mid = low + (high - low) / 2;

			int cnt = lowCol * n;
			for (int i = lowCol; i < highCol; ++i) {
				midRow[i] = (lower_bound(matrix[i].begin() + lowRow[i], matrix[i].begin() + highRow[i], mid + 1) - matrix[i].begin());
				cnt += midRow[i];
			}

			if (cnt < k) {
				low = mid + 1;
				for (int i = lowCol; i < highCol; ++i) {
					lowRow[i] = midRow[i];
					if (lowRow[i] == n) {
						lowCol = i + 1;
					}
				}
			} else {
				high = mid;
				for (int i = lowCol; i < highCol; ++i) {
					highRow[i] = min(n, midRow[i] + 1);
					if (highRow[i] == 0) {
						highCol = i;
					}
				}
			}
		}


		return low;
	}
};

#endif //LEETCODE_378_KTH_SMALLEST_ELEMENT_IN_A_SORTED_MATRIX_H
