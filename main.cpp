#include <iostream>
#include <vector>
#include "94. Binary Tree Inorder Traversal.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"flower", "flow", "flight"};
	vector<string> arr2 = {"ab", "a", "ba", "b"};

	vector<int> nums = {1, 3, 5, 0, 0, 0};
	vector<int> nums1 = {2, 4, 6};

	vector<vector<int>> board = {{5,  1,  9,  11},
								 {2,  0,  8,  10},
								 {13, 3,  6,  7},
								 {15, 14, 12, 16}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};

	TreeNode c(3);
	TreeNode b(2, &c, nullptr);
	TreeNode a(1, nullptr, &b);
//	TreeNode f(4, &a);
//	TreeNode e(6, &b);
//	TreeNode d(5, &e);

	auto aa = s.inorderTraversal(&a);

	for (auto ac : aa) {
		cout << ac << '\t';
	}

	return 0;
}