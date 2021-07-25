//
// Created by jin on 7/25/2021.
//

#ifndef LEETCODE_124_BINARY_TREE_MAXIMUM_PATH_SUM_H
#define LEETCODE_124_BINARY_TREE_MAXIMUM_PATH_SUM_H

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
	int maxSum = INT_MIN;

	int maxPathSum(TreeNode *root) {
		maxPath(root);

		return maxSum;
	}

	int maxPath(TreeNode *root) {
		int left = 0, right = 0;

		if (root->left != nullptr) {
			left = max(0, maxPath(root->left));
		}

		if (root->right != nullptr) {
			right = max(0, maxPath(root->right));
		}

		int sum = left + root->val + right;
		if (sum > maxSum) {
			maxSum = sum;
		}

		return root->val + max(left, right);
	}
};

#endif //LEETCODE_124_BINARY_TREE_MAXIMUM_PATH_SUM_H
