#include <iostream>
#include <vector>
#include "76. Minimum Window Substring.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"flower", "flow", "flight"};
	vector<string> arr2 = {"ab", "a", "ba", "b"};

	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	vector<int> nums1 = {3, 1, 5};

	vector<vector<int>> board = {{0, 1, 0},
								 {0, 0, 1},
								 {1, 1, 1},
								 {0, 0, 0}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};

	vector<vector<char>> grid = {{'A', 'B', 'C', 'E'},
								 {'S', 'F', 'C', 'S'},
								 {'A', 'D', 'E', 'E'}};
	vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
								  {'1', '1', '0', '0', '0'},
								  {'0', '0', '1', '0', '0'},
								  {'0', '0', '0', '1', '1'}};

	cout<< s.minWindow("ADOBECODEBANC", "ABC");

	return 0;
}