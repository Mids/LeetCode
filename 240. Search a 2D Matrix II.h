//
// Created by Jin on 5/2/2021.
//

#ifndef LEETCODE_240_SEARCH_A_2D_MATRIX_II_H
#define LEETCODE_240_SEARCH_A_2D_MATRIX_II_H

using namespace std;

class Solution {
public:
	int start, end;

	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		int height = matrix.size();

		int i = 0, j = matrix[0].size() - 1;
		while (i < height && j >= 0) {
			if (matrix[i][j] < target) {
				++i;
			} else if (matrix[i][j] > target) {
				--j;
			} else {
				return true;
			}
		}

		return false;
	}
};

#endif //LEETCODE_240_SEARCH_A_2D_MATRIX_II_H
