#ifndef LEETCODE_297_SERIALIZE_AND_DESERIALIZE_BINARY_TREE_H
#define LEETCODE_297_SERIALIZE_AND_DESERIALIZE_BINARY_TREE_H

#include <sstream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

	TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode *root) {
		if (root == nullptr) return "#";

		return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data) {
		return deserializeRef(data);
	}

	TreeNode *deserializeRef(string &data) {
		if (data[0] == '#') {
			if (data.size() > 1)
				data = data.substr(2);
			return nullptr;
		}

		int pos = data.find(',');
		TreeNode *node = new TreeNode(stoi(data.substr(0, pos)));
		data = data.substr(pos + 1);
		node->left = deserializeRef(data);
		node->right = deserializeRef(data);
		return node;
	}
};


#endif //LEETCODE_297_SERIALIZE_AND_DESERIALIZE_BINARY_TREE_H
