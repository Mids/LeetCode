//
// Created by jin on 7/25/2021.
//

#ifndef LEETCODE_547_NUMBER_OF_PROVINCES_H
#define LEETCODE_547_NUMBER_OF_PROVINCES_H

using namespace std;

class Solution {
public:
	int size;
	int index = 2;

	int findCircleNum(vector<vector<int>> &isConnected) {
		size = isConnected.size();

		for (int i = 0; i < size; ++i) {
			if (isConnected[i][i] == 1) {
				colorize(isConnected, i);
				++index;
			}
		}


		return index - 2;
	}

	void colorize(vector<vector<int>> &isConnected, int i) {
		for (int j = 0; j < size; ++j) {
			if (isConnected[i][j] != 1) continue;

			isConnected[i][j] = index;

			if (isConnected[j][j] == 1)
				colorize(isConnected, j);
		}

	}
};

#endif //LEETCODE_547_NUMBER_OF_PROVINCES_H
