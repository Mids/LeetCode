//
// Created by jin on 4/1/2021.
//

#ifndef LEETCODE_94_BINARY_TREE_INORDER_TRAVERSAL_H
#define LEETCODE_94_BINARY_TREE_INORDER_TRAVERSAL_H

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
	vector<int> result;

	vector<int> inorderTraversal(TreeNode *root) {
		if (root != nullptr)
			inorder(root);
		return result;
	}

	void inorder(TreeNode *root) {
		if (root->left) {
			inorder(root->left);
		}
		result.push_back(root->val);
		if (root->right) {
			inorder(root->right);
		}
	}
};

#endif //LEETCODE_94_BINARY_TREE_INORDER_TRAVERSAL_H
