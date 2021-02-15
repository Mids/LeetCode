//
// Created by jin on 2/15/2021.
//

#ifndef LEETCODE_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define LEETCODE_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H

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
	vector<vector<int>> result;

	vector<vector<int>> levelOrder(TreeNode *root) {
		order(root, 0);

		return result;
	}

	void order(TreeNode *root, int i) {
		if (root == nullptr)
			return;

		if (result.size() == i) {
			vector<int> newVector;
			result.push_back(newVector);
		}

		result[i].push_back(root->val);
		order(root->left, i + 1);
		order(root->right, i + 1);
	}
};

#endif //LEETCODE_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
