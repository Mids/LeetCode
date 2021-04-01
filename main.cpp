#include <iostream>
#include <vector>
#include "105. Construct Binary Tree from Preorder and Inorder Traversal.h"

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

//	TreeNode c(15);
//	TreeNode b(7);
//	TreeNode a(20, &c, &b);
//	TreeNode f(9);
//	TreeNode e(3, &f, &a);
//	TreeNode d(5, &e);

	auto aa = s.buildTree(nums, nums1);

	while(aa){

		cout << aa->left->val<< ' ';
		cout << aa->val<< ' ';
		cout << aa->right->val<< ' ';
		break;
	}

	return 0;
}