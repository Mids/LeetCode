//
// Created by jin on 4/1/2021.
//

#ifndef LEETCODE_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
#define LEETCODE_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H

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

	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		if (root != nullptr) {
			zigzag(root, 0);
		}
		for (int n = 1; n < result.size(); n += 2) {
			reverse(result[n].begin(), result[n].end());
		}
		return result;
	}

	void zigzag(TreeNode *root, int depth) {
		if (result.size() < depth + 1) {
			result.push_back(*new vector<int>());
		}

		result[depth].push_back(root->val);

		if (root->left)
			zigzag(root->left, depth + 1);
		if (root->right)
			zigzag(root->right, depth + 1);

	}
};

#endif //LEETCODE_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
