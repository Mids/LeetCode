//
// Created by jin on 2/8/2021.
//

#ifndef LEETCODE_19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define LEETCODE_19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}

	ListNode(int x) : val(x), next(nullptr) {}

	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		int i = 1;
		ListNode *cur = head;
		ListNode *target = head;
		while (i++ <= n) {
			cur = cur->next;
		}

		if (cur == nullptr) return head->next;

		while (true) {
			if (cur->next == nullptr) {
				target->next = target->next->next;
				return head;
			}

			target = target->next;
			cur = cur->next;
		}

		return head;
	}
};

#endif //LEETCODE_19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
