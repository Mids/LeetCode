//
// Created by jin on 2/15/2021.
//

#ifndef LEETCODE_101_SYMMETRIC_TREE_H
#define LEETCODE_101_SYMMETRIC_TREE_H

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		if (root == nullptr) return true;
		return isSymmetric(root->left, root->right);
	}

	bool isSymmetric(TreeNode *left, TreeNode *right) {
		if (left == nullptr || right == nullptr) return left == right;

		return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
};


#endif //LEETCODE_101_SYMMETRIC_TREE_H
