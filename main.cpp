#include <iostream>
#include <vector>
#include "230. Kth Smallest Element in a BST.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"flower", "flow", "flight"};
	vector<string> arr2 = {"ab", "a", "ba", "b"};

	vector<int> nums = {1, 3, 5};
	vector<int> nums1 = {3, 1, 5};

	vector<vector<int>> board = {{5,  1,  9,  11},
								 {2,  0,  8,  10},
								 {13, 3,  6,  7},
								 {15, 14, 12, 16}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};

	TreeNode a6(6);
	TreeNode a4(4);
	TreeNode a1(1);
	TreeNode a2(2, &a1, nullptr);
	TreeNode a3(3, &a2, &a4);
	TreeNode a5(5, &a3, &a6);

	auto aa = s.kthSmallest(&a5, 3);

	cout << aa;

	return 0;
}