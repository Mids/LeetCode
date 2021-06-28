//
// Created by jin on 6/28/2021.
//

#ifndef LEETCODE_289_GAME_OF_LIFE_H
#define LEETCODE_289_GAME_OF_LIFE_H

using namespace std;

// In-place
class Solution {
public:
	int rowSize, colSize;

	void gameOfLife(vector<vector<int>> &board) {
		rowSize = board.size();
		colSize = board[0].size();

		for (auto i = 0; i < rowSize; ++i) {
			for (auto j = 0; j < colSize; ++j) {
				if (board[i][j] < 1) {
					if(check(board, i, j) == 3){
						board[i][j] = -1;
					}
				} else{
					auto liveCount = check(board, i, j);
					if (liveCount < 2 || liveCount > 3) {
						board[i][j] = 2;
					}
				}
			}
		}

		for (auto i = 0; i < rowSize; ++i) {
			for (auto j = 0; j < colSize; ++j) {
				if(board[i][j] == -1)
					board[i][j] = 1;
				else if(board[i][j] == 2)
					board[i][j] = 0;
			}
		}
	}

	int check(vector<vector<int>> &board, int row, int col) {
		int liveCount = 0;
		for (auto i = row - 1; i <= row + 1; ++i) {
			for (auto j = col - 1; j <= col + 1; ++j) {
				if (i == row && j == col) continue;
				if (i < 0 || i >= rowSize || j < 0 || j >= colSize) continue;

				if (board[i][j] > 0)
					++liveCount;
			}
		}

		return liveCount;
	}
};

// O(mxn)Space
class Solution1 {
public:
	vector<vector<int>> inputBoard;
	int rowSize, colSize;

	void gameOfLife(vector<vector<int>> &board) {
		rowSize = board.size();
		colSize = board[0].size();
		inputBoard = board;

		for (int i = 0; i < rowSize; ++i) {
			for (int j = 0; j < colSize; ++j) {
				board[i][j] = check(i, j);
			}
		}
	}

	int check(int row, int col) {
		int liveCount = 0;
		for (auto i = row - 1; i <= row + 1; ++i) {
			for (auto j = col - 1; j <= col + 1; ++j) {
				if (i == row && j == col) continue;
				if (i < 0 || i >= rowSize || j < 0 || j >= colSize) continue;

				if (inputBoard[i][j] == 1)
					++liveCount;
			}
		}

		if (inputBoard[row][col] == 1) {
			if (liveCount < 2 || liveCount > 3) {
				return 0;
			}
			return 1;
		} else if (liveCount == 3) {
			return 1;
		}

		return 0;
	}
};

#endif //LEETCODE_289_GAME_OF_LIFE_H
