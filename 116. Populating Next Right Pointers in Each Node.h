//
// Created by jin on 4/5/2021.
//

#ifndef LEETCODE_116_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H
#define LEETCODE_116_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H

using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	Node *left;
	Node *right;
	Node *next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node *_left, Node *_right, Node *_next)
			: val(_val), left(_left), right(_right), next(_next) {}
};

// O(1) Space
class Solution {
public:
	Node *curParent, *prevRight, *downFloor;

	Node *connect(Node *root) {
		if(!root || !root->right) return root;

		curParent = root;
		while (curParent->left) {
			downFloor = curParent->left;
			downFloor->next = curParent->right;

			while(curParent->next){
				prevRight = curParent->right;
				curParent = curParent->next;
				prevRight->next = curParent->left;
				curParent->left->next = curParent->right;
			}

			curParent = downFloor;
		}


		return root;
	}
};

// O(log N) Space
class Solution1 {
public:
	Node *first[12] = {nullptr};

	Node *connect(Node *root) {
		// log base 2 4096 is 12

		set(root, 0);


		return root;
	}

	void set(Node *root, int depth) {
		if (root == nullptr) return;

		if (first[depth] != nullptr) {
			first[depth]->next = root;
		}

		first[depth] = root;

		set(root->left, depth + 1);
		set(root->right, depth + 1);

	}
};

#endif //LEETCODE_116_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H
