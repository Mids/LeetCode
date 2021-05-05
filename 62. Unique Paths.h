//
// Created by Jin on 5/5/2021.
//

#ifndef LEETCODE_62_UNIQUE_PATHS_H
#define LEETCODE_62_UNIQUE_PATHS_H

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		int i = 1, j;

		if (m == 1 || n == 1)
			return 1;

		vector<int> row(n, 1);

		for (; i < m; ++i) {
			for (j = 1; j < n; ++j) {
				row[j] += row[j - 1];
			}

		}


		return row[n - 1];
	}
};

#endif //LEETCODE_62_UNIQUE_PATHS_H
