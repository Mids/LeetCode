//
// Created by jin on 4/5/2021.
//

#ifndef LEETCODE_200_NUMBER_OF_ISLANDS_H
#define LEETCODE_200_NUMBER_OF_ISLANDS_H

using namespace std;

class Solution {
public:
	int row, col;

	int numIslands(vector<vector<char>> &grid) {
		row = grid.size();
		col = grid[0].size();
		int result = 0;

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (grid[i][j] == '1') {
					++result;
					corrupt(grid, i, j);
				}
			}
		}

		return result;
	}

	void corrupt(vector<vector<char>> &grid, int i, int j) {
		if (i < 0 || j < 0 || i == row || j == col || grid[i][j] != '1')
			return;

		grid[i][j] = '2';

		corrupt(grid, i + 1, j);
		corrupt(grid, i - 1, j);
		corrupt(grid, i, j + 1);
		corrupt(grid, i, j - 1);
	}
};

#endif //LEETCODE_200_NUMBER_OF_ISLANDS_H
