//
// Created by Jin on 8/1/2021.
//

#ifndef LEETCODE_329_LONGEST_INCREASING_PATH_IN_A_MATRIX_H
#define LEETCODE_329_LONGEST_INCREASING_PATH_IN_A_MATRIX_H

using namespace std;

class Solution {
public:
	int rowSize, colSize;
	vector<vector<int>> count;

	int getPath(vector<vector<int>> &matrix, int i, int j) {
		int maxNum = 0;
		if (count[i][j] > 0)
			return count[i][j];

		int ni = i - 1, nj = j;
		if (ni >= 0 && matrix[ni][nj] > matrix[i][j]) {
			maxNum = max(maxNum, getPath(matrix, ni, nj));
		}
		ni = i + 1;
		if (ni < rowSize && matrix[ni][nj] > matrix[i][j]) {
			maxNum = max(maxNum, getPath(matrix, ni, nj));
		}
		ni = i, nj = j - 1;
		if (nj >= 0 && matrix[ni][nj] > matrix[i][j]) {
			maxNum = max(maxNum, getPath(matrix, ni, nj));

		}
		nj = j + 1;
		if (nj < colSize && matrix[ni][nj] > matrix[i][j]) {
			maxNum = max(maxNum, getPath(matrix, ni, nj));
		}

		count[i][j] = maxNum + 1;

		return maxNum + 1;
	}

	int longestIncreasingPath(vector<vector<int>> &matrix) {
		colSize = matrix[0].size();
		rowSize = matrix.size();
		count = matrix;
		int maxNum = 0;

		for (auto &v : count) {
			for (auto &c : v) {
				c = 0;
			}
		}

		for (auto i = 0; i < rowSize; ++i) {
			for (auto j = 0; j < colSize; ++j) {
				auto num = getPath(matrix, i, j);
				maxNum = max(maxNum, num);
			}
		}

		return maxNum;
	}
};

#endif //LEETCODE_329_LONGEST_INCREASING_PATH_IN_A_MATRIX_H
