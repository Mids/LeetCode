//
// Created by jin on 4/5/2021.
//

#ifndef LEETCODE_230_KTH_SMALLEST_ELEMENT_IN_A_BST_H
#define LEETCODE_230_KTH_SMALLEST_ELEMENT_IN_A_BST_H

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
	bool isFound = false;
	int target;
	int result;

	int kthSmallest(TreeNode *root, int k) {
		target = k;
		GetCount(root, 0);
		return result;
	}


	int GetCount(TreeNode *root, int leftSum) {
		if (root->left)
			leftSum = GetCount(root->left, leftSum);

		if (isFound)
			return 0;

		if (++leftSum == target) {
			result = root->val;
			isFound = true;
			return 0;
		}

		if (root->right) {
			leftSum = GetCount(root->right, leftSum);

			if (isFound)
				return 0;
		}

		return leftSum;

	}
};

#endif //LEETCODE_230_KTH_SMALLEST_ELEMENT_IN_A_BST_H
