//
// Created by jin on 2/15/2021.
//

#ifndef LEETCODE_98_VALIDATE_BINARY_SEARCH_TREE_H
#define LEETCODE_98_VALIDATE_BINARY_SEARCH_TREE_H

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
	bool isValidBST(TreeNode *root) {
		return isValidBST(root, INT_MIN, INT_MAX);
	}

	bool isValidBST(TreeNode *root, int min, int max) {
		return !(min > root->val || root->val > max ||
				 root->left != nullptr && (root->left->val >= root->val || !isValidBST(root->left, min, root->val - 1)) ||
				 root->right != nullptr && (root->right->val <= root->val || !isValidBST(root->right, root->val + 1, max)));

	}
};


#endif //LEETCODE_98_VALIDATE_BINARY_SEARCH_TREE_H
