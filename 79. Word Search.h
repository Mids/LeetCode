//
// Created by jin on 4/19/2021.
//

#ifndef LEETCODE_79_WORD_SEARCH_H
#define LEETCODE_79_WORD_SEARCH_H

using namespace std;

class Solution {
public:
	vector<vector<char>> *inputBoard;
	int rowSize, colSize;

	bool exist(vector<vector<char>> &board, const string &word) {
		inputBoard = &board;
		rowSize = board.size();
		colSize = board[0].size();
		auto str = word.c_str();

		for (auto i = 0; i < rowSize; ++i) {
			for (auto j = 0; j < colSize; ++j) {
				if (exist(i, j, str))
					return true;
			}
		}

		return false;
	}

	bool exist(int row, int col, const char *n) {
		if (row < 0 || col < 0 || row == rowSize || col == colSize || (*inputBoard)[row][col] != (*n))
			return false;

		if (!*(n + 1))
			return true;

		(*inputBoard)[row][col] = 0;
		if (exist(row + 1, col, n + 1)
			|| exist(row, col + 1, n + 1)
			|| exist(row - 1, col, n + 1)
			|| exist(row, col - 1, n + 1))
			return true;
		(*inputBoard)[row][col] = *n;

		return false;
	}
};

#endif //LEETCODE_79_WORD_SEARCH_H
