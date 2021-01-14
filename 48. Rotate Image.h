//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_48_ROTATE_IMAGE_H
#define LEETCODE_48_ROTATE_IMAGE_H

using namespace std;

class Solution {
public:
	int size;

	void rotate(vector<vector<int>> &matrix) {
		size = matrix.size();
		int subSizeX = size / 2 + size % 2;
		int subSizeY = size / 2;

		for (int i = 0; i < subSizeX; ++i) {
			for (int j = 0; j < subSizeY; ++j) {
				int row = i;
				int col = j;

				int rotRow = newRow(col);
				int rotCol = newCol(row);

				int temp = matrix[row][col];

				matrix[row][col] = matrix[rotRow][rotCol];

				row = rotRow;
				col = rotCol;
				rotRow = newRow(col);
				rotCol = newCol(row);
				matrix[row][col] = matrix[rotRow][rotCol];

				row = rotRow;
				col = rotCol;
				rotRow = newRow(col);
				rotCol = newCol(row);
				matrix[row][col] = matrix[rotRow][rotCol];

				matrix[rotRow][rotCol] = temp;
			}
		}
	}

	int newRow(int col) {
		return size - col - 1;
	}

	int newCol(int row) {
		return row;
	}
};

#endif //LEETCODE_48_ROTATE_IMAGE_H
