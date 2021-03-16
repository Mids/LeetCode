//
// Created by jin on 3/16/2021.
//

#ifndef LEETCODE_73_SET_MATRIX_ZEROES_H
#define LEETCODE_73_SET_MATRIX_ZEROES_H

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>> &matrix) {
		int rowCount = matrix.size();
		int colCount = matrix[0].size();

		bool firstRow = false;
		bool firstCol = false;

		for (int i = 0; i < rowCount; ++i) {
			for (int j = 0; j < colCount; ++j) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;

					if (i == 0)
						firstRow = true;
					if (j == 0)
						firstCol = true;
				}
			}
		}

		for (int i = 1; i < rowCount; ++i) {
			for (int j = 1; j < colCount; ++j) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
		}

		if (firstRow) {
			for (int i = 0; i < colCount; ++i) {
				matrix[0][i] = 0;
			}
		}
		if (firstCol) {
			for (int i = 0; i < rowCount; ++i) {
				matrix[i][0] = 0;
			}
		}

	}

	// O(M+N) space
	void setZeroes2(vector<vector<int>> &matrix) {
		int rowCount = matrix.size();
		int colCount = matrix[0].size();

		int zeroRow[200] = {-1};
		int zeroCol[200] = {-1};

		for (int i = 0; i < rowCount; ++i) {
			for (int j = 0; j < colCount; ++j) {
				if (matrix[i][j] == 0) {
					zeroRow[i] = 1;
					zeroCol[j] = 1;
				}
			}
		}

		for (int i = 0; i < rowCount; ++i) {
			for (int j = 0; j < colCount; ++j) {
				if (zeroRow[i] == 1 || zeroCol[j] == 1)
					matrix[i][j] = 0;
			}
		}
	}
};

#endif //LEETCODE_73_SET_MATRIX_ZEROES_H
