//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_36_VALID_SUDOKU_H
#define LEETCODE_36_VALID_SUDOKU_H

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector <vector<char>> &board) {
		for (int i = 0; i < 9; ++i) {
			int row[9] = {0};

			for (int j = 0; j < 9; ++j) {
				char v = board[i][j];
				if (v == '.')
					continue;

				v = v - '1';
				if (row[v] == 0)
					row[v] = 1;
				else
					return false;
			}
		}


		for (int i = 0; i < 9; ++i) {
			int row[9] = {0};

			for (int j = 0; j < 9; ++j) {
				char v = board[j][i];
				if (v == '.')
					continue;

				v = v - '1';
				if (row[v] == 0)
					row[v] = 1;
				else
					return false;
			}
		}


		for (int BigRow = 0; BigRow < 9; BigRow += 3) {
			for (int BigCol = 0; BigCol < 9; BigCol += 3) {
				int subBox[9] = {0};
				for (int row = 0; row < 3; ++row) {
					for (int col = 0; col < 3; ++col) {
						char v = board[BigRow + row][BigCol + col];
						if (v == '.')
							continue;

						v = v - '1';
						if (subBox[v] == 0)
							subBox[v] = 1;
						else
							return false;
					}
				}
			}
		}

		return true;
	}
};

#endif //LEETCODE_36_VALID_SUDOKU_H
