//
// Created by jin on 4/1/2021.
//

#ifndef LEETCODE_105_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H
#define LEETCODE_105_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H

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
	vector<int> *_preorder;
	vector<int> *_inorder;
	int preorderIndex = 0;

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int size = preorder.size();
		if (size == 0) return nullptr;

		_preorder = &preorder;
		_inorder = &inorder;

		auto *root = build((*_preorder)[preorderIndex++], 0, size);

		return root;
	}

	TreeNode *build(int val, int start, int end) {
		auto *node = new TreeNode(val);
		int valIndex = -1;

		for (int i = start; i < end; i++) {
			if ((*_inorder)[i] == val) {
				valIndex = i;
				break;
			}
		}

		if (start < valIndex) {
			node->left = build((*_preorder)[preorderIndex++], start, valIndex);
		}

		if (valIndex + 1 < end) {
			node->right = build((*_preorder)[preorderIndex++], valIndex + 1, end);
		}

		return node;
	}
};

#endif //LEETCODE_105_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H
