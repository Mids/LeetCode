#include <iostream>
#include <vector>
#include "215. Kth Largest Element in an Array.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"flower", "flow", "flight"};
	vector<string> arr2 = {"ab", "a", "ba", "b"};

	vector<int> nums = {3, 2, 1, 5, 6, 4};
	vector<int> nums1 = {3, 1, 5};

	vector<vector<int>> board = {{5,  1,  9,  11},
								 {2,  0,  8,  10},
								 {13, 3,  6,  7},
								 {15, 14, 12, 16}};

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

	auto aa = s.findKthLargest(nums, 2);

	cout << aa;

	return 0;
}