//
// Created by jin on 2/8/2021.
//

#ifndef LEETCODE_237_DELETE_NODE_IN_A_LINKED_LIST_H
#define LEETCODE_237_DELETE_NODE_IN_A_LINKED_LIST_H

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode *node) {
		while (true) {
			auto next = node->next;
			node->val = next->val;
			if (next->next == nullptr) {
				node->next = nullptr;
				return;
			}
			node = next;
		}
	}
};

#endif //LEETCODE_237_DELETE_NODE_IN_A_LINKED_LIST_H
