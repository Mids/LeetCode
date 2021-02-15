//
// Created by jin on 2/15/2021.
//

#ifndef LEETCODE_104_MAXIMUM_DEPTH_OF_BINARY_TREE_H
#define LEETCODE_104_MAXIMUM_DEPTH_OF_BINARY_TREE_H

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
	int maxDepth(TreeNode *root) {
		int max = 0;
		int left = 0, right = 0;

		if (root == nullptr)
			return 0;

		right = maxDepth(root->right);
		left = maxDepth(root->left);

		max = right > left ? right : left;

		return max + 1;
	}
};

#endif //LEETCODE_104_MAXIMUM_DEPTH_OF_BINARY_TREE_H
