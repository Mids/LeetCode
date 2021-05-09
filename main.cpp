#include <iostream>
#include <vector>
#include "297. Serialize and Deserialize Binary Tree.h"

using namespace std;

int main() {
	Codec s;

	vector<string> arr = {"flower", "flow", "flight"};
	vector<string> arr2 = {"ab", "a", "ba", "b"};

	vector<int> nums = {4, 10, 4, 3, 8, 9};
	vector<int> nums1 = {3, 1, 5};

	vector<vector<int>> board = {{1,  4,  7,  11, 15},
								 {2,  5,  8,  12, 19},
								 {3,  6,  9,  16, 22},
								 {10, 13, 14, 17, 24},
								 {18, 21, 23, 26, 30}};

	vector<vector<int>> board2 = {{1, 2, 3, 4},
								  {4, 5, 6, 7},
								  {7, 8, 9, 10}};

	vector<vector<char>> grid = {{'A', 'B', 'C', 'E'},
								 {'S', 'F', 'C', 'S'},
								 {'A', 'D', 'E', 'E'}};
	vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
								  {'1', '1', '0', '0', '0'},
								  {'0', '0', '1', '0', '0'},
								  {'0', '0', '0', '1', '1'}};

	TreeNode a5(5);
	TreeNode a4(4);
	TreeNode a3(3, &a4, &a5);
	TreeNode a2(2);
	TreeNode a1(1, &a2, &a3);

	cout << s.serialize(s.deserialize("[1,2]"));

	return 0;
}