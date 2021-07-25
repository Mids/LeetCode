//
// Created by jin on 7/25/2021.
//

#ifndef LEETCODE_236_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_H
#define LEETCODE_236_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_H

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x, TreeNode *left = nullptr, TreeNode *right = nullptr) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int v1, v2;
	TreeNode *result;

	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		v1 = p->val, v2 = q->val;

		find(root);

		return result;
	}

	int find(TreeNode *root) {
		if (result != nullptr || root == nullptr) return 0;

		int foundCount = (root->val == v1 || root->val == v2) + find(root->left) + find(root->right);

		if (foundCount == 2) {
			result = root;
			return 1;
		}

		return foundCount;
	}
};

#endif //LEETCODE_236_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_H
