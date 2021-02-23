//
// Created by jin on 2/23/2021.
//

#ifndef LEETCODE_118_PASCAL_S_TRIANGLE_H
#define LEETCODE_118_PASCAL_S_TRIANGLE_H

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result(numRows);

		for (int i = 0; i < numRows; ++i) {
			vector<int> newVector(i + 1, 1);

			for (int j = 1; j < i; ++j) {
				newVector[j] = result[i - 1][j - 1] + result[i - 1][j];
			}

			result[i] = newVector;
		}

		return result;
	}
};

#endif //LEETCODE_118_PASCAL_S_TRIANGLE_H
