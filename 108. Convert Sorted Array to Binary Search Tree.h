//
// Created by jin on 2/15/2021.
//

#ifndef LEETCODE_108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H
#define LEETCODE_108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H

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
	vector<int> *numVector;

	TreeNode *sortedArrayToBST(vector<int> &nums) {
		numVector = &nums;

		return sortedArrayToBST(0, nums.size() - 1);
	}

	TreeNode *sortedArrayToBST(int front, int end) {
		if (front > end) {
			return nullptr;
		}

		int cur = (front + end) / 2;

		return new TreeNode((*numVector)[cur], sortedArrayToBST(front, cur - 1), sortedArrayToBST(cur + 1, end));
	}
};

#endif //LEETCODE_108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H
