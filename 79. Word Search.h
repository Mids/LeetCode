//
// Created by jin on 4/19/2021.
//

#ifndef LEETCODE_79_WORD_SEARCH_H
#define LEETCODE_79_WORD_SEARCH_H

using namespace std;

class Solution {
public:
	vector<vector<char>> *inputBoard;
	string *inputWord;
	int rowSize, colSize;

	bool exist(vector<vector<char>> &board, string word) {
		inputBoard = &board;
		inputWord = &word;
		rowSize = board.size();
		colSize = board[0].size();

		for (auto i = 0; i < rowSize; ++i) {
			for (auto j = 0; j < colSize; ++j) {
				if (exist(i, j, 0))
					return true;
			}
		}

		return false;
	}

	bool exist(int row, int col, int n) {
		if (row < 0 || col < 0 || row == rowSize || col == colSize)
			return false;

		auto v = (*inputBoard)[row][col];
		if (!v || v != (*inputWord)[n++])
			return false;

		if (n == inputWord->size())
			return true;

		(*inputBoard)[row][col] = 0;
		if (exist(row + 1, col, n)
			|| exist(row, col + 1, n)
			|| exist(row - 1, col, n)
			|| exist(row, col - 1, n))
			return true;
		(*inputBoard)[row][col] = v;

		return false;
	}
};

#endif //LEETCODE_79_WORD_SEARCH_H
