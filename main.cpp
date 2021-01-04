#include <iostream>
#include <vector>
#include "980. Unique Paths III.h"

using namespace std;

int main() {
	Solution s, s2, s3;

	vector<vector<int>> grid = {{1, 0, 0, 0},
								{0, 0, 0, 0},
								{0, 0, 2, -1}};
	vector<vector<int>> grid2 = {{1, 0, 0, 0},
								 {0, 0, 0, 0},
								 {0, 0, 0, 2}};
	vector<vector<int>> grid3 = {{0, 1},
								 {2, 0}};
//	vector<vector<int>> grid = {{1,-1},{0,2}};


	cout << s.uniquePathsIII(grid) << endl;
	cout << s2.uniquePathsIII(grid2) << endl;
	cout << s3.uniquePathsIII(grid3) << endl;


	return 0;
}