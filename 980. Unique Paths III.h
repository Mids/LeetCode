//
// Created by jin on 1/4/2021.
//

#ifndef LEETCODE_980_UNIQUE_PATHS_III_H
#define LEETCODE_980_UNIQUE_PATHS_III_H

using namespace std;

class Solution {
public:
	int max = 0;
	int curX, curY;
	int sizeX, sizeY;
	int result = 0;
	vector<vector<int>> tempGrid;

	int uniquePathsIII(vector<vector<int>> &grid) {
		tempGrid = grid;
		sizeX = grid.size();
		sizeY = grid[0].size();
		max = sizeX * sizeY - 1;

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 1) {
					curX = i;
					curY = j;
				} else if (grid[i][j] == -1) {
					max--;
				}
			}
		}

		goNext(0);

		return result;
	}

	void goNext(int depth) {
		if (curX < 0 || curX == sizeX || curY < 0 || curY == sizeY)
			return;

		if (tempGrid[curX][curY] == 2) {
			if (depth == max)
				result++;
			return;
		}

		if (tempGrid[curX][curY] == -1) {
			return;
		}

		tempGrid[curX][curY] = -1;

//		print();

		curX += 1;
		goNext(depth + 1);
		curX -= 2;
		goNext(depth + 1);
		curX += 1;
		curY += 1;
		goNext(depth + 1);
		curY -= 2;
		goNext(depth + 1);
		curY += 1;

		tempGrid[curX][curY] = 0;
	}

	void print() {
		for (auto row : tempGrid) {
			for (auto square : row) {
				cout << square << '\t';
			}
			cout << endl;
		}

		cout << endl;
	}
};

#endif //LEETCODE_980_UNIQUE_PATHS_III_H
