//
// Created by jin on 7/25/2021.
//

#ifndef LEETCODE_130_SURROUNDED_REGIONS_H
#define LEETCODE_130_SURROUNDED_REGIONS_H

using namespace std;

class Solution {
public:
	int rowSize, colSize;

	void solve(vector<vector<char>> &board) {
		rowSize = board.size();
		colSize = board[0].size();

		for (int j = 0; j < colSize; ++j) {
			check(board, 0, j);
			check(board, rowSize - 1, j);
		}

		for (int i = 1; i < rowSize - 1; ++i) {
			check(board, i, 0);
			check(board, i, colSize - 1);
		}

		for (int i = 0; i < rowSize; ++i) {
			for (int j = 0; j < colSize; ++j) {
				if (board[i][j] == 0)
					board[i][j] = 'O';
				else
					board[i][j] = 'X';
			}
		}
	}

	void check(vector<vector<char>> &board, int i, int j) {
		auto &v = board[i][j];
		if (v == 'X' || !v)
			return;

		v = 0;

		int ni = i - 1;
		int nj = j;

		if (ni >= 0)
			check(board, ni, nj);
		ni = i + 1;
		if (ni < rowSize)
			check(board, ni, nj);
		ni = i, nj = j - 1;
		if (nj >= 0)
			check(board, ni, nj);
		nj = j + 1;
		if (nj < colSize)
			check(board, ni, nj);
	}
};

#endif //LEETCODE_130_SURROUNDED_REGIONS_H
